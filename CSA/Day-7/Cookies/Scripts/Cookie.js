
function setCookie (cookieName,cookieValue,expiryDate = "Session"){
if(expiryDate=="Session"){
    document.cookie = cookieName +"="+ cookieValue;
}
else{

    const d = new Date();
    d.setTime(d.getTime() + (expiryDate*24*60*60*1000));
  
document.cookie = cookieName +"="+ cookieValue+";expires="+ d.toUTCString();
}
}

function getCookie(coName){
    var flag = 0;
    var y = document.cookie.replace(/ /g,"");
    var x = y.split(/=|;/);
        for (i=0;i<x.length;i+=2){
        if(x[i]==coName){
            return x[i+1];
            flag =1;
        } 
    }
    if (flag==0)
    return "cookie does not exist";
}


function allCookieList(){
    if (document.cookie != ""){
        var x = document.cookie.split(/=|;/);
        return x;
    }
    else return "no cookies to show";
}
function hasCookie(cookieName){
    var x = getCookie(cookieName);
    if (x == "cookie does not exist"){
        return 0;
    }
    else return 1;
}

function  deleteCookie(cookieName){
    var newDate = new Date();
newDate.setTime(newDate.getTime() - 86400000);
document.cookie = cookieName +"=;expires="+ newDate.toUTCString();
}
