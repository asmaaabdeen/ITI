function displayRadioValue() {
    var ele = document.getElementsByName('gender');
      
    for(i = 0; i < ele.length; i++) {
        if(ele[i].checked)
       return ele[i].value;
    }
}
function NewCookie(){
    
   setCookie("username",document.getElementById("name").value,"30");
    setCookie("age",document.getElementById("age").value);
    setCookie("gender",displayRadioValue());
    setCookie("color",document.getElementById("Col").value,"20");
    setCookie("count",1);

    open("Welcome.html");
}

function retrievecookie(){
    var cook = getCookie("username");
    console.log(cook);
}

function showcookielist(){
    console.log(allCookieList());
}

function chechcook(){
    var existcook = hasCookie("username");
    console.log(existcook);
}
function deletecook(){
    deleteCookie("age");
}
function img(){
    if(getCookie("gender")=="male"){
        return "Images/1.jpg";
    }
    else return "Images/2.jpg";
}
document.images[0].src = img();

if (hasCookie("username")){
    document.getElementById("Uname").innerHTML ="<span style=\"color: "+getCookie("color")+";\">"+getCookie("username")+"</span>";
}
else{
    var namee = prompt("please enter your name","asmaa")
    setCookie("username",namee,"30");
    document.getElementById("Uname").innerHTML ="<span style=\"color: "+getCookie("color")+";\">"+getCookie("username")+"</span>";
}

window.addEventListener("load",function(){

document.getElementById("count").innerHTML ="<span style=\"color: "+getCookie("color")+";\">"+getCookie("count")+"</span>";
setCookie("count",parseInt(getCookie("count"))+1);
})

