function openWin(){
    win = open ("Scrollable.html","","width=700,height=300");
   timer= setInterval(function(){
        win.scrollBy(0,20);
    },100);
  setTimeout(function(){
    win.close();
    clearInterval(timer);
  },10000)
}