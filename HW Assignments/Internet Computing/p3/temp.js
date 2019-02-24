var total = 0;

var report = function (first, last, total) {
    document.getElementById("result").innerHTML =
        
		first + last + " = " + total;
};

document.getElementById("plus").onclick = function () {
    var f = document.getElementById("first_box").value;
	var l = document.getElementById("last_box").value;
	total = f + l;
	report(f, l, total);
};

document.getElementById("minus").onclick = function () {
    var m = document.getElementById("last_box").value;
    
};