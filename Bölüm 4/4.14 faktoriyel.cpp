/*
4.14 5 faktoriyel hesapla �izelge olarak yazdur.

 faktoriyel=n.(n-1)
 1. say�n�n faktoriyeli=1
 2. say�n�n faktoriyeli=2.1
 3. say�n�n faktoriyeli=3.2.1
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
