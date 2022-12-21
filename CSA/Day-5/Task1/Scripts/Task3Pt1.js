
var win,timer,nx=60,ny=60 ;
var x=y=0;

function newwindow(){
    win =  open("window.html","newWin","width=150,height=150");
    win.focus();
 timer = setInterval(function(){
    win.resizeTo(150,150);
    if ((y+ny)>(screen.height-150)||(x+nx)>(screen.width-150)||(y+ny)<0)
{
   nx=-nx;
    ny=-ny;
}

win.moveTo(x,y);
x+= nx;
y+= ny;
 },55);
 
  }
  function stopwindow(){
    clearInterval(timer);
    win.focus();
  
  }
  function closeWin(){
    win.close();
  
  }