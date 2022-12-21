
var timer;
var img1 = document.getElementById("img1");
var img2 = document.getElementById("img2");
var topimg = document.getElementById("top");

var x = 5, y = 5, z = 5, i = 0;
document.getElementsByTagName("p")[0].innerText = "<img src=\"images/icon1.gif\" style=\"left:" + getComputedStyle(img2).left + "\"/>";
document.getElementsByTagName("p")[1].innerText = "<img src=\"images/icon1.gif\" style=\"left:" + getComputedStyle(img1).left + "\"/>";
document.getElementById("goStop").addEventListener("click", function () {

    if (i % 2 == 0) {

        document.getElementById("goStop").innerText = "Stop";
        timer = setInterval(function () {
            if ((parseInt(getComputedStyle(img2).left) + x) > 450 || (parseInt(getComputedStyle(img2).left) + x) < 0) {
                x = -x;
            }
            img2.style.left = parseInt(getComputedStyle(img2).left) + x + "px";

            if ((parseInt(getComputedStyle(img1).left) - y) < 0 || (parseInt(getComputedStyle(img1).left) - y) > 450) {
                y = -y;
            }
            img1.style.left = parseInt(getComputedStyle(img1).left) - y + "px";
            if ((parseInt(getComputedStyle(topimg).top) + z) > 450 || (parseInt(getComputedStyle(topimg).top) + z) < 0) {
                z = -z
            }
            topimg.style.top = parseInt(getComputedStyle(topimg).top) + z + "px";
            document.getElementsByTagName("p")[0].innerText = "<img src=\"images/icon1.gif\" style=\"left:" + getComputedStyle(img2).left + "\"/>";
            document.getElementsByTagName("p")[1].innerText = "<img src=\"images/icon2.gif\" style=\"left:" + getComputedStyle(img1).left + "\"/>";
        }, 50);
    }

    else {
        document.getElementById("goStop").innerText = "Go";
        clearInterval(timer);
    }
    i++;
})

document.getElementById("reset").addEventListener("click", function () {
    clearInterval(timer);
    img1.style.left = "455px";
    img2.style.left = "0";
    topimg.style.top = "0";
    x = 5;
    y = 5;
    z = 5;
    i = 0;
    document.getElementById("goStop").innerText = "Go";
    document.getElementsByTagName("p")[0].innerText = "<img src=\"images/icon1.gif\" style=\"left:" + getComputedStyle(img2).left + "\"/>";
    document.getElementsByTagName("p")[1].innerText = "<img src=\"images/icon1.gif\" style=\"left:" + getComputedStyle(img1).left + "\"/>";
})

