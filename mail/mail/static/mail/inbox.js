document.addEventListener('DOMContentLoaded', function() {

  // Use buttons to toggle between views
  document.querySelector('#inbox').addEventListener('click', () => load_mailbox('inbox'));
  document.querySelector('#sent').addEventListener('click', () => load_mailbox('sent'));
  document.querySelector('#archived').addEventListener('click', () => load_mailbox('archive'));
  document.querySelector('#compose').addEventListener('click', compose_email);
  document.querySelector('#compose-form').addEventListener('submit',send_email);

  // By default, load the inbox
  load_mailbox('inbox');
});

function compose_email(recipients ,subject, timestamp, body, isReply=false) {

  // Show compose view and hide other views
  document.querySelector('#emails-view').style.display = 'none';
  document.querySelector('#compose-view').style.display = 'block';
  document.querySelector('#email-view').style.display = 'none';

  // Clear out composition fields
  if(isReply){
  document.querySelector('#compose-recipients').value = recipients;}
  else{
    document.querySelector('#compose-recipients').value = '';
  }

  if (isReply){
  document.querySelector('#compose-body').value = `On ${timestamp}, ${recipients} wrote : ${body}`;
}
else{
  document.querySelector('#compose-body').value ='';
}
if (isReply){
  if (subject.includes('Re: ')){
  document.querySelector('#compose-subject').value = subject;
}
else{
  document.querySelector('#compose-subject').value =`Re: ${subject}`
}
}
else{
  document.querySelector('#compose-subject').value ='';
}

}

function load_mailbox(mailbox) {
  
  // Show the mailbox and hide other views
  document.querySelector('#emails-view').style.display = 'block';
  document.querySelector('#compose-view').style.display = 'none';
  document.querySelector('#email-view').style.display = 'none';

  // Show the mailbox name
  document.querySelector('#emails-view').innerHTML = `<h3>${mailbox.charAt(0).toUpperCase() + mailbox.slice(1)}</h3>`;

  

    fetch(`/emails/${mailbox}`)
    .then(response => response.json())
    .then(emails => {
        // Print emails
        console.log(emails);
     
      const sentList=document.getElementById('emails-view')
     emails.forEach(Element => {
     let a=document.createElement('div')
     
     a.innerHTML=  `From: <b>${Element.sender}</b>. Subject: <b>${Element.subject}</b> .     TimeStamp:      <b>${Element.timestamp}</b>`
     a.style.border=" solid black";
     a.style.marginBottom="10px";
     a.style.fontSize='medium';

     if (Element.read){
      a.style.backgroundColor='gray';
     }
     else{
      a.style.backgroundColor='white';
     }
     
    a.addEventListener('click', ()=>displayEmail(Element.id, mailbox))
     sentList.append(a)
      
     });
    
        
    });
  

}

async function send_email(event){
  event.preventDefault();

  
  const a=document.querySelector('#compose-recipients').value
  const b=document.querySelector('#compose-subject').value
  const c=document.querySelector('#compose-body').value

  
 let resp=  await fetch('/emails', {
    method:'POST',
    body: JSON.stringify({
      recipients: a,
      subject: b,
      body: c
    })
  })




  
  if (resp.status==201){
    alert("Email sent successfully !!")
    load_mailbox('sent')
    
  }
  if (resp.status==400){
    alert("Email doesn't exist. Please check the spelling")
  }
  
 
}

function displayEmail(iid, mailbox){
  document.querySelector('#emails-view').style.display = 'none';
  document.querySelector('#compose-view').style.display = 'none';

  if (document.getElementById('mm')){
    document.getElementById('mm').remove()
  }
  document.querySelector('#email-view').style.display = 'block';

  fetch(`/emails/${iid}`)
  .then (response=>response.json())
  .then(email=>{
    console.log(email)
    const view=document.getElementById('email-view')
    const frame=document.createElement('div')
    frame.id='mm'
    frame.innerHTML= `
    <b>Sent by: </b> ${email.sender} <br>
    <b>Recipient(s): </b> ${email.recipients}<br>
    <b>Subject: </b> ${email.subject}<br>
    <b>Timestamp: </b> ${email.timestamp}<br><br><br>
    <b>Body: </b><br>
    ${email.body}
    <br><br><br>
    `
    view.append(frame)
    if(document.getElementById('arcBut')){
      document.getElementById('arcBut').remove()
    }
    if (mailbox!='sent'){
    const butt=document.createElement('button')
    butt.id='arcBut'
    butt.style.width='80px'
    butt.style.height='25px'
    let arcStatus=email.archived
    if (arcStatus){
      butt.innerText='Unarchive'
    }
    else{
      butt.innerText='Archive'
    }
    butt.addEventListener('click', ()=>{
      fetch(`/emails/${iid}`, {
        method: 'PUT',
        body: JSON.stringify({
           archived: !arcStatus
        })
      })
      load_mailbox('inbox')
    })
    view.append(butt)

    //marking the email read
    fetch(`/emails/${iid}`, {
      method: 'PUT',
      body: JSON.stringify({
          read: true
      })
    })}
    if (document.getElementById('reply')){
      document.getElementById('reply').remove()
    }
    const reply=document.createElement('button')
    reply.id='reply'
    reply.style.width='80px'
    reply.style.height='25px'
    reply.style.marginLeft='5px'
    reply.innerText='Reply'
    reply.addEventListener('click',()=>{
      compose_email(email.sender, email.subject, email.timestamp, email.body, true)
    })
    view.append(reply)
  
} )
  }



