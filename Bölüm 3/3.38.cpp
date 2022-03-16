/*
3.38 Bir seferde 100 yýldýz yazan program


*/

#include<stdio.h>

int main(){

   int i=0;
   
   while(i<100){
   	if(i%10==0)		//10'un katýmý?
   	   printf("\n");
   	printf("*");
   	++i;
   }

   return 0;
}
