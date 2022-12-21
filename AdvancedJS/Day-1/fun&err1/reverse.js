//first way to reverse the arguments by converting the arguments to array using Array.from()
function reverse1() {

   return Array.from(arguments).reverse();
}
var arr = reverse1(10, 20, 30, 50, "lok", 0, "oo");
document.write(arr);

//second way 
function reverse2() {
   var arr = [];
   return arr.slice.call(arguments, ",").reverse();
}
var arr = reverse2(100, 20, 30, 50, "lok", 0, "kk");
document.write("<br>" + arr);
