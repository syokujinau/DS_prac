#include <stdio.h>
#include <stdlib.h>

#define n1 15

/*recursive Fibonacci*/
int Fib_re(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return Fib_re(n-1) + Fib_re(n-2);
}

/*Iterative Fibonacci*/
int Fib_ite(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else {
        int a=0,b=1,c;
        for(int i=2; i <= n; i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
}


int main (void){
 
    printf("Fib_re(%d) = %d \n",n1,Fib_re(n1));
    printf("Fib_ite(%d) = %d \n",n1,Fib_ite(n1));
    
    return 0;
    
} 

