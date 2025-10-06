function setEdit(id, content){

  if (!document.getElementById('editArea').hidden){
    return
  }

 
  
  document.getElementById('editArea').hidden=false
  document.getElementById('ta').value=content

 let button=document.getElementById('edit')
  button.addEventListener('click',()=>{

  fetch(`/editPost/${id}`,{
    method:'PUT',
    body: JSON.stringify({
      id: id,
      content: document.getElementById('ta').value
    })
   })
   .then(response=>response.json())
   .then(message=>console.log(message))
   document.getElementById(`content ${id}`).innerText=document.getElementById('ta').value
   document.getElementById('editArea').hidden=true;
   
  
  
  }

     )
}


function showArea(){
  document.getElementById('newPost').style.display=block;
}

function setButton(follows){
  butt=document.getElementById('follow')
  if (follows){
    butt.innerText='Follow'
  }
  else{
    butt.innerText='Unfollow'
  }
}




 async function likePost(postId, userId){
  butt=document.getElementById(`like ${postId}`)
 console.log(postId ,userId )

  if (butt.innerText==='Like'){
    butt.innerText='Unlike'
    let response = await fetch('/like',{
      method:'PUT',
      body: JSON.stringify({
        postId: postId
      })
    })
    let message=await response.json()

     console.log(message)
    document.getElementById(`count ${postId}`).innerText= await (message.message.likesCount)
    
  }

  else{
    butt.innerText='Like'
    let response = await fetch('/unlike',{
      method:'PUT',
      body: JSON.stringify({
        postId: postId
      })
    })
    let message=await response.json()

     console.log(message)
    document.getElementById(`count ${postId}`).innerText= await (message.message.likesCount)
}
 }