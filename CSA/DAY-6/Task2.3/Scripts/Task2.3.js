

function EnterNumber(val){

document.getElementById("Answer").value += val;
   
}

var operator,x,y;
function EnterOperator(oper){
     x = parseFloat(document.getElementById("Answer").value ) ;
document.getElementById("Answer").value = "";
operator = oper;

}
function EnterEqual(){
    y = parseFloat(document.getElementById("Answer").value );
if (operator=='+'){
     document.getElementById("Answer").value = (x+y)

}
if (operator=='*'){
    document.getElementById("Answer").value = (x*y)

}
if (operator=='/'){
    document.getElementById("Answer").value = (x/y)

}
if (operator=='-'){
    document.getElementById("Answer").value = (x-y)

}

}

function EnterClear(){
  
    document.getElementById("Answer").value = "";
}