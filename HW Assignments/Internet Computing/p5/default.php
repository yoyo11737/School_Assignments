<html>
<head>
<title>Converted!</title>

<style>
a {
	background-color: blue;
	border: none;
	color: white;
	padding: 15px 32px;
	text-align: center;
	text-decoration: none;
	display: inline-block;
	font-size: 20px;
	font-family: Arial;
	margin: 50px;
	cursor: pointer;
}
body{
	margin: 50px;
	text-align: center;
	font-size: 24px;
	font-family: Arial;
}
 </style>
</head>

<body>

<?php
//Pull Request
$endpoint = 'latest';
$key = 'b2e4599c9abd1787aad825d53243d10f';

$from = 'EUR';

$ch = curl_init('http://data.fixer.io/api/'.$endpoint.'?access_key='.$key.'&from='.$from.'&symbols=EUR,USD,GBP,INR,AUD,CAD');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$json = curl_exec($ch);
curl_close($ch);


$exchangeRates = json_decode($json, true);

$amount = $_POST['Amount'];
$error = "The amount entered is incorrect . . . ";


if(!is_numeric($amount)){
	echo "<script type='text/javascript'>alert('$error');</script>";
	$amount = 0;
}

$to = $_POST['to'];

if($to == 'USD'){
	echo 'The conversion of ' . $amount . ' from EUR to USD is ' . $amount * $exchangeRates['rates']['USD'];
}
else if($to == 'GBP'){
	echo 'The conversion of ' . $amount . ' from EUR to GBP is ' . $amount * $exchangeRates['rates']['GBP'];
}
else if($to == 'INR'){
	echo 'The conversion of ' . $amount . ' from EUR to INR is ' . $amount * $exchangeRates['rates']['INR'];
}
else if($to == 'AUD'){
	echo 'The conversion of ' . $amount . ' from EUR to AUD is ' . $amount * $exchangeRates['rates']['AUD'];
}
else if($to == 'CAD'){
	echo 'The conversion of ' . $amount . ' from EUR to CAD is ' . $amount * $exchangeRates['rates']['CAD'];
}
else if($to == 'EUR'){
	echo 'The conversion of ' . $amount . ' from EUR to EUR is ' . $amount * $exchangeRates['rates']['EUR'];
}else{
	echo 'ERROR!!!';
}

?>
<br>
<a href="index.html">Make another conversion</a>

</body>
</html>
