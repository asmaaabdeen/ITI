
document.body.addEventListener("keydown",function(){
    alert("the asccii code of "+event.code+" is "+event.keyCode);
    if (event.altKey){
        alert("you pressed alt key");
    }
    else if(event.shiftKey){
        alert("you pressed shift key");
    }else if(event.ctrlKey){
        alert("you pressed control key");
    }
})

document.addEventListener("contextmenu",function(){
    event.preventDefault();
 })
