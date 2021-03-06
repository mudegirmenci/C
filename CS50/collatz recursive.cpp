#include <stdio.h>

#define N 3

void collatz(int n);
int collatzRecursion(int n);

int main() {
	
  int n=collatzRecursion(N);
  
  printf("**************************************************\n");
  printf("Collatz recursive %d icin adim sayisi:%d\n\n",N,n);
  printf("**************************************************\n");
  
  collatz(N);
}


int collatzRecursion(int n){
   
   
   //temel durum
   if(n==1)
   		return 0;
   //?ift say?lar
   else if(n%2==0)
      return 1+collatzRecursion(n/2);
   //tek say?lar
    else 
	  return 1+collatzRecursion(3*n+1);
	
}


void collatz(int n){
	int i,step=0;
	
	while(n>1) {
		i=n;
		if(n%2==0) n/=2;
		else n=3*n+1;
		printf("%d->%d ",i,n);
		step++;
	}
	printf("\nToplam step:%d\n",step);
	
	
}
