function display(){
var x = prompt("please enter a message","Hi");
    for (var i = 1;i<7;i++){
document.write("<h"+i+">"+x+"</h"+">"+i);
    }
    return ;
}

function sum(){
    var sum = 0;
    do{
        var x = parseInt(prompt("please enter a number",1)) ;
        if (isNaN(x)){
            alert("please enter a numeric value");
        }
        else{
            sum +=x;
        }
        
    }
    while(x!=0 && sum<100);
    document.write(sum);
}
