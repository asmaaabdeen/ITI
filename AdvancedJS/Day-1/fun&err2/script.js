function myfun(a,b){
    if (arguments.length>2 ){
        var err = new Error("To many arguments");
        throw err;
    }
    else if(arguments.length<2){
         var err = new Error("To few arguments");
        throw err;
    }
}
myfun(1);