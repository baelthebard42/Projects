let a=document.getElementById("tarif");
let c=document.getElementById("notes");
let d=document.getElementById("inputsec");
let e=document.getElementById("popup");
let count=0;
function addRecom(){
    let b=document.createElement("fieldset");
    if(a.value!=""){
        b.innerHTML="\<span\>&#8220;\</span\>"+a.value+"\<span\>&#8221;\</span\>";
    c.appendChild(b);
    popup(true);
    count++;
    a.value="";
    }
    else{
        alert("Please type something in the box!");
    }
}

function popup(flag){
    if (flag){
     e.style.visibility="visible";
    }
    else{
        e.style.visibility="hidden";  
    }
}