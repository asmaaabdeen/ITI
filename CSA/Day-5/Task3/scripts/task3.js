function type(){
    var txt= "your message will be displayed charachter by charachter :)";
    var i=0;    
    var txt2 = "few seconds and the window will be terminated ...";
    var j=0;

    timer = setInterval(function(){
        document.write(txt[i]);
        i++;
        if(i==txt.length){
            document.write("<br>");
            timer2 = setInterval(function(){
                document.write(txt2[j]);
                j++;
                if(j==txt2.length){
                    clearInterval(timer2);
                    setTimeout(function(){
                        window.close();
                    },3000);
                }
            },50);
            clearInterval(timer);
        }
    },50);

}
function type2(){
   
    
}