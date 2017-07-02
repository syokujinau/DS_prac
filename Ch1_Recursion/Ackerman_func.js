// Recursive Ackerman's function

var Ack=function(m,n){
	if (m==0) return n+1;
	if (n==0) return Ack(m-1,1);
	else return Ack(m-1,Ack(m,n-1));
}

console.log("Ack(2,2) = ",Ack(2,2));
console.log("Ack(2,1) = ",Ack(2,1));
console.log("Ack(1,2) = ",Ack(1,2));
console.log("Ack(2,3) = ",Ack(2,3));