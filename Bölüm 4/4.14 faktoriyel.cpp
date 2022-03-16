/*
4.14 5 faktoriyel hesapla çizelge olarak yazdur.

 faktoriyel=n.(n-1)
 1. sayýnýn faktoriyeli=1
 2. sayýnýn faktoriyeli=2.1
 3. sayýnýn faktoriyeli=3.2.1
*/

#include<stdio.h>

int main(void){
	
	int i,j,fak=1;
	
	for(i=1;i<=12;i++){
	   for(j=1;j<=i;j++){
	   	    if(j==1)
	   	       fak=1;
	   	    else
	   	       fak*=j;
	   	
	   }
		printf("----------------------------------------------\n");
		printf("%d sayisinin faktoriyeli:%13d      |\n",i,fak);
		printf("----------------------------------------------\n");
	}
	
}
