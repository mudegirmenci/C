#include<stdio.h>

//kenar uzunlu�u verilen bir kareniyi * ile �izer
int main()
{
	int kenar=0,satir=1,sutun=1,alan=0;
	
	printf(	"Kenar uzunlugunu gir:\n");
	scanf("%d",&kenar);
 alan=kenar*kenar;
	
	while(kenar>=sutun){
	   while(kenar>=satir){
	      if(alan%kenar==0)	printf("*");
	   	++satir;
	   	alan--;
	   }
	   printf("\n");
	   ++sutun;
	   satir=1;
   }


   return 0;	
}
