function displayRadioValue() {
    var ele = document.getElementsByName('card');
      
    for(i = 0; i < ele.length; i++) {
        if(ele[i].checked)
       return ele[i].value;
    }
}

document.getElementById("genBtn").addEventListener("click",function(){
 var win = window.open("", "", 'height=800px,width=700px', false);
   createImage(win);
   createPar(win);
   closewin(win);
})

function createImage(win){
    var newImg = document.createElement("img");
    newImg.src = location.origin+"/"+displayRadioValue();
    win.document.body.prepend(newImg);
    newImg.style.height = "80%";
    newImg.style.width = "100%";

}

function createPar(win){
    var newPar = document.createElement("p");
    newPar.innerText=document.getElementById("tArea").value;
    win.document.body.append(newPar);
    newPar.style.textAlign = "center";
    newPar.style.color = "rgb(66, 138, 180)";
    newPar.style.fontFamily = "Courier New', Courier, monospace";
    newPar.style.fontSize = "18px";


}

function closewin(win){
    var newbutton = document.createElement("button");
    newbutton.innerText="Close Window";
    win.document.body.append(newbutton);
    newbutton.style.marginLeft ="40%";
    newbutton.onclick= function(){
        win.close();
    }
   
}
// var elem = document.getElementsByName('card');
// for(i = 0; i < elem.length; i++) {
//     if(elem[i].checked){
//         for(var i=0;i<document.images.length;i++){
//             if (document.images[i].src==elem[i].value){
//                 console.log("7i")
//                 document.images[i].style.border ="5px solid red"
//             }
//         }
//     }
   
// }
