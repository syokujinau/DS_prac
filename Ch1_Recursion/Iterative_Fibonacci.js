//Iterative Fibonacci


function Fib(n){
	if(n==0) return 0;
	else if (n==1) return 1;
	else {
		var a=0,b=1,c;
		for (var i = 2; i <= n; i++) {
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	} 
}

for (var j = 0; j <= 80; j++) {
	 console.log("F"+j+" = "+Fib(j));
}