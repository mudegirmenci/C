#include<stdio.h>

//kenar uzunluðu verilen bir kareniyi * ile çizer
int main()
{
	int kenar=0,satir=1,sutun=1,alan=0,sayac=0;
	
	printf(	"Kenar uzunlugunu gir:\n");
	scanf("%d",&kenar);
    
    alan=kenar*kenar+1;
    satir=kenar;
    sayac=kenar;

	
	while(alan>=0){
	   if(satir==1 || satir==kenar ){
           while(sayac>=0){
    		  printf("*");
    		  sayac--;
    	   	  alan--;
    	   	}
    	   
	    printf("\n");
	   } else if(alan % kenar==0){
	   	
		  	   printf("*");
		  	   while(sayac<=0){
		  	   	printf(" ");
		  	   	sayac--;
				 }
		  	   alan--;
		  }
		   
		  sayac=kenar;
		  satir--;
		  alan--;
	   }
   

   return 0;	
}
