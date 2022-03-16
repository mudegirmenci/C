#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Yazý tura:paraAt adlý argüman almayan bir fonksiyon paranýn her atýlýþýnda ekrana yazý veya tura yazsýn.Program 100 kez yazý tura atsýn 
ve sonuçlarý ekrana yazdýrsýn.
*/

int paraAt(void);

int main(){
	int a=0,b=0;
	srand(time(NULL));  //besleme0
	for(int i=0;i<=100;i++){
		if(paraAt()==1){
		  printf("Tura\t");
		  a++;
	    }
		else{
	       printf(" Yazi\t");
	       b++;
		}
	}
	printf("\nTura sayisi:%d  Yazi sayisi:%d",a,b);
}

int paraAt(void){
	
	return rand()%2;
}
