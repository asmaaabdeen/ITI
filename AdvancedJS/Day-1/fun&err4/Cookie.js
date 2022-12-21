
function setCookie(cookieName, cookieValue, expiryDate = "Session") {
    if (typeof cookieName != "string") {
        throw new TypeError("cookie name must be a string");
    }
    else if (arguments.length > 3 || arguments.length < 2) {
        throw new Error("wrong number of arguments");
    }
    else if(expiryDate != "Session" && typeof expiryDate != "number"){
        throw new Error("expiry date must be a number ");
    }
    else if (expiryDate == "Session") {
        document.cookie = cookieName + "=" + cookieValue;
    }
    else {

        const d = new Date();
        d.setTime(d.getTime() + (expiryDate * 24 * 60 * 60 * 1000));

        document.cookie = cookieName + "=" + cookieValue + ";expires=" + d.toUTCString();
    }
}

function getCookie(coName) {
    if (typeof coName != "string") {
        throw new TypeError("cookie name must be a string");
    }
    else if (arguments.length != 1) {
        throw new Error("number of arguments must be exactly one");
    }
    else {
    var flag = 0;
    var y = document.cookie.replace(/ /g, "");
    var x = y.split(/=|;/);
    for (i = 0; i < x.length; i += 2) {
        if (x[i] == coName) {
            return x[i + 1];
            flag = 1;
        }
    }
    if (flag == 0)
    throw ":cookie does not exist";
}}


function allCookieList() {
    if (arguments.length > 0) {
        throw new Error("function allCookieList does not accept any parameters");
    }
    else if (document.cookie != "") {
        var x = document.cookie.split(/=|;/);
        return x;
    }
    else throw ":no cookies to show";
}

function hasCookie(cookieName) {
    if (typeof cookieName != "string") {
        throw new TypeError("cookie name must be a string");
    }
    else if (arguments.length != 1) {
        throw new Error("number of arguments must be exactly one");
    }
    else {
        var x = getCookie(cookieName);
        if (x == "cookie does not exist") {
            return 0;
        }
        else return 1;
    }

}

function deleteCookie(cookieName) {
    if (typeof cookieName != "string") {
        throw new TypeError("cookie name must be a string");
    }
    else if (arguments.length != 1) {
        throw new Error("number of arguments must be exactly one");
    }
    else if (!hasCookie(cookieName)) {
        throw new Error("cookie does not exist");
    }
    else {
        var newDate = new Date();
        newDate.setTime(newDate.getTime() - 86400000);
        document.cookie = cookieName + "=;expires=" + newDate.toUTCString();
    }

}