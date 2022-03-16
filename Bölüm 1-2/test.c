#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int i;
  for(i=1;i<=10;i++)	
  	printf("%2d!=%ld\n",i,faktoriyal(i));

   return 0;
}
long faktoriyal(long sayi)
{
	if(sayi<=1)
	   return 1;
	else 
	   return(sayi*faktoriyal(sayi-1));
}
