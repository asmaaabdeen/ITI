
  
    var x = location.search.split(/=|&/) ;
    var email = x[9].replace(/%40/,"@");
    
    document.write("<h1> Welcome "+x[1]+" "+x[3]+"</h1>"+"<hr>");
    document.write("Your Address Is : "+x[5]+"<br>");
    document.write("Your E-Mail Is : "+email+"<br>");
    document.write("Your Gender Is : "+x[7]+"<br>");
    document.write("Your Phone Is : "+x[11]+"<br>");

   