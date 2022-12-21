//function to search for a char in a string the user entered
function SearchChar(){
var x = prompt("enter a string","Hello from prompet window");
var y = prompt("enter a charachter","o");
var i = confirm("do you want to consider char case in search ?");
if (i==true)
{
    var regex = new RegExp(y,"g");
    document.write("count of the char = " + x.match(regex).length)
}
else {
    var regex = new RegExp(y,"ig");
    document.write("count of the char = " + x.match(regex).length)
}
    return;
}

// test a string entered by user eather a palindrome or not
function palindrome(){

    var str = prompt("enter a string","DdoodD");
    var strrev = str.split("",str.length).reverse().join("");
    var c = confirm("do you want to consider char case in search ?");
    
    if (c==true)
    {
        var regex = new RegExp(strrev,"g");
        if (str.match(regex)==null)
        document.write("not a palindrome");
        else 
        document.write("it is a palindrome");
    }
    else{
        var regex = new RegExp(strrev,"gi");
        if (str.match(regex)==null)
        document.write("not a palindrome");
        else 
        document.write("it is a palindrome");
    }
    
}

//find the largest word in a string
function largword(){
    var str = prompt("enter a string","Hello it's Asmaa from the beautiful javascript");
var arr= str.split(" ");

var longestwordlen  =0;
var longestword;
for (var i=0;i<arr.length;i++){
    if(arr[i].length>longestwordlen){
        longestwordlen = arr[i].length;
        longestword = arr[i];
    }
}
document.write(longestword);
}

//validate user input
function validate(){
    var namereg = /^([a-zA-Z ]){2,30}$/i;
    var telreg = /^[0-9]{8,8}$/;
    var mobreg = /^01[0-2][0-9]{8}$/;
    var mailreg = /^[a-zA-Z_.0-9]{1,15}@[a-zA-Z]{1,7}\.[A-Za-z]{1,3}$/;
    var clr = /^red$|^green$|^blue$/
    do{
        var flag=0;
        var name = prompt("please enter your name","Asmaa");
        if(name.match(namereg)==null){
            alert ("please enter charachters  from a to z");
            flag = 1;
        }
       
    }while(flag);
    do{
        var flag=0;
        var telphone = prompt("please enter your telephone","25544526");
        if(telphone.match(telreg)==null){
            alert ("please enter 8 numbers from 0 to 9");
            flag = 1;
        }
       
    }while(flag);
    
    do{
        var flag=0;
        var mobile = prompt("please enter your telephone","01113516325");
        if(mobile.match(mobreg)==null){
            alert ("please enter 11 numbers from 0 to 9");
            flag = 1;
        }
       
    }while(flag);
    do{
        var flag=0;
        var email = prompt("please enter your email","a@h.com");
        if(email.match(mailreg)==null){
            alert ("please enter valid mail");
            flag = 1;
        }
       
    }while(flag);
    do{
        var flag=0;
        var colour = prompt("choose a color (red,green,blue)","red");
        if(colour.match(clr)==null){
            alert ("please enter red or green or blue");
            flag = 1;
        }
    }while(flag);
    
    document.write("<h1>"+"entering user enfo"+"</h1>" + "<hr>");
    document.write("<span style=\"color:"+colour+";font-weight: bold;\">welcome dear guest " + "</span>"+name+ "<br>"+ "<br>");
    document.write("<span style=\"color:"+colour+";font-weight: bold;\">your telephone number is " + "</span>"+telphone+ "<br>"+ "<br>");
    document.write("<span style=\"color:"+colour+";font-weight: bold;\">your mobile number is " + "</span>"+mobile+ "<br>"+ "<br>");
    document.write("<span style=\"color:"+colour+";font-weight: bold;\">your e-mail is " + "</span>"+email+ "<br>"+ "<br>");

   
    
}
//a function to take the radius of a circle from the user and print the area of the circle in an alert
function circle(){
var rad = prompt("enter the value of the radius of your circle",15);
var area = Math.PI * rad *rad;
alert ("total value of circle area = "+ area);
}

// function to calculate the square root of a number the user has entered and show it in an alert
function sqrr(){
   var flag = 0;
   do{
    var val = prompt("enter a value to calc it's square root",16);
    if (val >= 0 ){
        var x = Math.sqrt(val);
        alert ("the square root of the number you entered =  " + x);
        flag = 1;
    }
    else{
        alert ("please enter a number equal or greater than zero  " );
    }
   
   }while(!flag)
}

//function to take an angle from the  user an calculate the cosin of it
function cos(){
    var radd =parseInt( prompt("enter an angle to calc it's cos value",45));
    var f = (radd/180)*Math.PI;
    var cosval = Math.cos(f);
    document.write("cos "+radd+"° = " + cosval.toFixed(3));
}


//function to take three numbes from the user and perform (+,*,/) on them
function array(){

    var val1 = prompt("enter first element of the  array ",16);
    var val2 = prompt("enter second element of the  array",16);
    var val3 = prompt("enter third element of the  array",16);
    var arr = [val1,val2,val3];
    var sum =0 , multi=1, dev=1;
   for(var i = 0;  i< arr.length ;i++){
        var value =  parseInt(arr[i]);
    
        sum +=  value;
        multi *=  value;
        dev/= value;
   }
    document.write("<h1>Adding -- Multiblying -- and dividing 3 values </h1>"+"<hr>");
    
    document.write("<span style=\"color: red;font;font-weight: bold;\">sum of three values</span> "+ val1 + " + " + val2 + " + " + val3 + " = " +  sum + "<br>"+ "<br>");
    document.write("<span style=\"color: red;font-weight: bold;\">Multiblication of three values</span> " + val1 + " * " + val2 + " * " + val3 + " = " + multi+ "<br>"+ "<br>");
    document.write("<span style=\"color: red;font-weight: bold;\">division of three values</span> " + val1 + " / " + val2 + " / " + val3 + " = " + dev+ "<br>"+ "<br>");
}

//another way
function arr2(){
    var arr = new Array();
    var sum =0 , multi=1, dev=1;
    for (var i = 0 ; i < 3 ; i++){
        var val = prompt("enter element "+(parseInt(i)+1)+" of the  array ",16);
        arr[i]=val;
        var value =  parseInt(arr[i]);
        sum +=  value;
        multi *=  value;
        dev/= value;
    }
   
    document.write("<h1>Adding -- Multiblying -- and dividing 3 values </h1>"+"<hr>");
    document.write("<span style=\"color: red;font;font-weight: bold;\">sum of three values</span> "+ arr.join("+") +" = " +  sum + "<br>"+ "<br>");
    document.write("<span style=\"color: red;font-weight: bold;\">Multiblication of three values</span> " + arr.join("*") + " = " + multi+ "<br>"+ "<br>");
    document.write("<span style=\"color: red;font-weight: bold;\">division of three values</span> " +arr.join("/") + " = " + dev+ "<br>"+ "<br>");

}

//function to sort an array of 5 intgers (scaned from the user) in an asc an desc order
function sort(){
    var arrr = new Array();
    for (var i = 0 ; i < 5 ; i++){
        var val = parseInt (prompt("enter element "+(parseInt(i)+1)+" of the  array ",16));
        arrr[i]=val;
        
    }
    document.write("<h1>Sorting </h1>"+"<hr>");
    document.write("<span style=\"color: red;font;font-weight: bold;\">u'v entered values </span> "+ arrr.join(" , ") + "<br>"+ "<br>");
    
    arrr.sort(function(a,b){return a-b});
    document.write("<span style=\"color: red;font;font-weight: bold;\">u're values after being ordered ascending </span> "+ arrr.join(",") + "<br>"+ "<br>");
    document.write("<span style=\"color: red;font;font-weight: bold;\">u're values after being ordered descending </span> "+ arrr.reverse().join(",") + "<br>"+ "<br>");
}

