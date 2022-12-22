
//*gallary section


(function () { $("#galdiv ,#aboutdiv,#compdiv,#data ").hide(); }());
$("#gal").click(function () {
    $("#aboutdiv,#myDropdown,#compdiv,#data").hide();
    $("#galdiv").show().css({ "margin": "auto", "width": "500px", "box-shadow": "5px 5px 10px 10px grey", "height": "270px", "backgroundColor": "white" });

});
var i = 1;
$("#right").click(function () {
    if (i < 8) {
        i++;
        $("#img1").attr("src", "../Images/" + i + ".jpg");
    }
});
$("#left").click(function () {
    if (i > 1) {
        i--;
        $("#img1").attr("src", "../Images/" + i + ".jpg");
    }
})

//*end gallary section

////////////////////////////////////////////////////////////////////////////////

//?about section

$("#about").click(function () {
    $("#galdiv,#myDropdown,#compdiv,#data").hide();
    $("#aboutdiv").show().css({ "margin": "auto", "width": "500px", "box-shadow": "5px 5px 10px 10px grey", "height": "270px", "backgroundColor": "white" });

});

//?end about section

/////////////////////////////////////////////////////////////////////////////////

//&Services section

$(".dropbtn").click(function () {
    $("#compdiv,#galdiv,#aboutdiv,#data").hide();
    $("#myDropdown").slideToggle(3000);
});

//&end services section

//////////////////////////////////////////////////////////////////////////////////

//^Complain section

$("#Compl").click(function () {
    $("#galdiv,#aboutdiv,#myDropdown,#data").hide();
    $("#compdiv").show().css({ "margin": "auto", "width": "550px", "box-shadow": "5px 5px 10px 10px grey", "height": "400px", "backgroundColor": "white" });
})

$("#send").click(function () {
    var comp = $("#ta").val();
    var nam = $("#name").val();
    var tel = $("#phone").val();
    var mail = $("#email").val();

    $("#compdiv").hide();
    $("#data").show().css({ "margin": "auto", "width": "550px", "box-shadow": "5px 5px 10px 10px grey", "height": "400px", "backgroundColor": "white" });
    $("#com").html("<span style=\"font-weight:bold;color:black\">Your complain is " + "</span>" + comp);
    $("#na").html("<span style=\"font-weight:bold;color:black\">Your name is " + "</span>" + nam);
    $("#ema").html("<span style=\"font-weight:bold;color:black\">Your Email address is " + "</span>" + mail);
    $("#ph").html("<span style=\"font-weight:bold;color:black\">Your phone number is " + "</span>" + tel);

})
$("#edit").click(function () {
    $("#data").hide();
    $("#compdiv").show();
})

//^end complain section