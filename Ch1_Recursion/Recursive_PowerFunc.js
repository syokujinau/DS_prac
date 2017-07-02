//Recursive Power Function

var exp = function(x,y){
	if (y==0) return 1;
	else return x*exp(x,y-1);
}


for (var i = 0; i <= 15; i++) {
	console.log("2^"+i+" = "+exp(2,i))
}
