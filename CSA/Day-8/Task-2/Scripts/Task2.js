function hdlr(){

    document.body.firstElementChild.classList.remove("center");
    document.body.getElementsByTagName("img")[0].style.marginLeft ="83%"
    var newImg = document.createElement("img");
    newImg.src = document.images[0].src;
    document.body.append(newImg);
    newImg.style.marginTop = "5%"
    document.getElementById("navigation").style.textAlign ="center";
    document.getElementById("nav").type = "circle";
    document.removeEventListener("click",hdlr);
}

document.addEventListener("click",hdlr);
 