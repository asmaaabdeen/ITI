
var i=1;
var x = document.getElementById("next");
console.log(x);
document.getElementById("next").onclick = 
function() {
    if(i<6){
        document.images[0].src= "Images/"+(i+1)+".jpg";
        i++;
    }
}

function Pre(){
    if(i>1){
        document.images[0].src= "Images/"+(i-1)+".jpg";
        i--;
    }
}
var timer;
function SlideShow(){
    
    timer = setInterval(function(){
        if(i>=6)
        {
            i=0;
        }
        document.images[0].src= "Images/"+(i+1)+".jpg";
        i++
        
    },700)
}
function Stop(){
clearInterval(timer);
}