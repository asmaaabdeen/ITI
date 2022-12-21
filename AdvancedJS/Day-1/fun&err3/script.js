function add(){
    var flag = 0;
    for (i=0;i<arguments.length;i++){
        if(typeof arguments[i] != "number"){
flag =1;
        }
    }
    if(flag){
        var err = new  TypeError("you must pass a numeric value");
        throw err;
    }
if(arguments.length==0){
    var err = new  Error("you must pass atleast one parameter");
    throw err;
}
else{
    var sum =0;
    for (i=0;i<arguments.length;i++){
sum += arguments[i];
}
return sum;
}
}

var x =add();
document.write(x);