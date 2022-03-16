#include <stdio.h>
/*
fibonacci 
*/
void fibonacci(int a);

int main(){
	
	fibonacci(50);
}

void fibonacci(int a){
	int fib1=0,fib2=1,fib=0; //ilk iki sayýnýn toplamý (1,1,2,3,5,...)
	
	printf("1.fibonacci:%d\n",fib2);
	for(int i=2;a>1;a--,i++){
	    fib=fib1+fib2;
	    fib1=fib2;
	    fib2=fib;
	   printf("%d.fibonacci:%d\n",i,fib);
	  
   }
}
