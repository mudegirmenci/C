
/*
3.40. a�a��daki �ekli yazd�r�n.

* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
 
 
 8x8 sat�r i�in 64 olan bir sayac de�i�ken tan�mla. tek ve �ift sat�rlar� belirlemek i�in  step de�i�keni olu�tur.
 
 while(sayac>0) sayac 0 dan b�y�k oldu�u s�rece
    E�er sayac 8'in kat�ysa 
       bir alt sat�ra ge�
       step de�i�kenini bir art�r
       
       e�er �iftli sat�rdaysa bir girinti ver
    y�ld�z yaz ve bir bo�luk b�rak
    sayac de�i�kenini bir azalt
    
    endWhile

*/

#include<stdio.h>

int main(){
	
	int sayac=64,step=0;
	
	while(sayac>0){
		if(sayac%8==0){			//sat�r sonuysa (8 * yazd�ysa)
			printf("\n");		//bir sat�r alta ge�
			++step; 			//step 1 art�r
		
			if(step%2==0)		//step �ift ise bir bo�luk girinti b�rak
		      printf(" ");
		}
	printf("* ");              //y�ld�z yazd�r
	--sayac;
	}
	

   return 0;	
}
