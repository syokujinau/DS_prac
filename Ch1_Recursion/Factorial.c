#include <stdio.h>
#include <stdlib.h>

#define N 8

/*factorial iterative*/
int Fac_Ite(int n){
  int sum=1,i;
  for (i = 1; i <= n; i++){
    sum=sum*i;
  }
  return sum;
}

/*factorial recursive*/
int Fac_Rec(int n){
  if(n==0) return 1;
  else return Fac_Rec(n-1)*n;
}


int main(){

  printf("Fac_Ite %d!= %d \n",N,Fac_Ite(N) );
  printf("Fac_Rec %d!= %d \n",N,Fac_Rec(N) );

  return 0;
}