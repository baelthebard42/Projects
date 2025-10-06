function compute()
{
   let principal = document.getElementById("principal").value;
   let rate=document.getElementById("rate").value;
   let years=document.getElementById("years").value;
   let interest= principal*rate*years/100;
   let amount=(principal)+interest;
   document.getElementById("result").innerText=interest;
   document.getElementById("amount").innerText=amount;
   let year=new Date().getFullYear()+years;
   
   if (principal<=0){
       window.alert("Enter a positive number!!");
       document.getElementById("principal").focus(); //sets the cursor on principal input field
   }

   
}

function updateRate(){
    let rateval=document.getElementById("rate").value;
    document.getElementById("rate_val").innerText=rateval;
}
        