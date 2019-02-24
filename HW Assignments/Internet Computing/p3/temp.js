/*
Dalton McClain
Intr. Internet Comp.
COP 3813
Project 3

JAVASCRIPT
*/

var reportPlus = function (first, last, total) {
    document.getElementById("result").innerHTML =
        
		parseInt(first) + " + " + parseInt(last) + " = " + parseInt(total);
};

var reportMinus = function (first, last, total) {
    document.getElementById("result").innerHTML =
        
		parseInt(first) + " - " + parseInt(last) + " = " + parseInt(total);
};

document.getElementById("equals").onclick = function () {
	if(document.getElementById("plus").checked == true){
		var f = document.getElementById("first_box").value;	
		var l = document.getElementById("last_box").value;
		var total = parseInt(f) + parseInt(l);
		reportPlus(f, l, total);
	} 
	else if(document.getElementById("minus").checked == true){
		var f = document.getElementById("first_box").value;
		var l = document.getElementById("last_box").value;
		var total = parseInt(f) - parseInt(l);
		reportMinus(f, l, total);
	}
};
