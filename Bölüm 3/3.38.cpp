/*
3.38 Bir seferde 100 y�ld�z yazan program


*/

#include<stdio.h>

int main(){

   int i=0;
   
   while(i<100){
   	if(i%10==0)		//10'un kat�m�?
   	   printf("\n");
   	printf("*");
   	++i;
   }

   return 0;
}
