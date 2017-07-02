// recursive binomial coefficient

function Bin(n,m){
	if (m==0 || n==m) return 1;
	else return Bin(n-1,m) + Bin(n-1,m-1);
}

for (var i = 0; i <= 5; i++) {
	console.log("Bin(5,"+i+") =" + Bin(5,i));
}
