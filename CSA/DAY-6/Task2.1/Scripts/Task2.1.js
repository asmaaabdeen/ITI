var timer;
var i = 0;
function resume() {
   timer = setInterval(function(){
        if(i >0){
            document.images[i-1].src = "../Images/marble1.jpg";
        }
        if(i==document.images.length)
        {
            i=0;
        }
        document.images[i].src = "../Images/marble3.jpg";
        i++;
        
    },1000);
}
function stop(){
    clearInterval(timer);
}