var imgs = ['images/1.gif', 'images/2.gif', 'images/3.gif', 'images/4.gif', 'images/5.gif', 'images/6.gif'];

for (var i = 0; i < imgs.length; i++) {
    document.getElementById("container").innerHTML += "<div ><img src=\"" + imgs[i] + "\"></div>";
}
for (var i = 0; i < imgs.length; i++) {
    document.getElementById("container").innerHTML += "<div ><img src=\"" + imgs[i] + "\"></div>";
}
var flag = true;
var arr = [];
var divs = document.getElementsByTagName("div");
for (var i = 0; i < divs.length; i++) {
    divs[i].addEventListener("click", function () {
        if (flag) {
            this.firstChild.style.opacity = "1";
            if (arr.length == 0) { arr[0] = this; }
            else if (arr.length == 1) { arr[1] = this; }
            if (arr.length == 2) {
                flag = false;
                setTimeout(function () {
                    if (arr[0].firstChild.getAttribute('src') === arr[1].firstChild.getAttribute('src')) {
                        console.log("shater")
                    }
                    else {

                        arr[0].firstChild.style.opacity = 0;
                        arr[1].firstChild.style.opacity = 0;


                    }
                    arr = [];
                    flag = true;
                }, 400)

            }

        }

    })
}
