#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Yaz� tura:paraAt adl� arg�man almayan bir fonksiyon paran�n her at�l���nda ekrana yaz� veya tura yazs�n.Program 100 kez yaz� tura ats�n 
ve sonu�lar� ekrana yazd�rs�n.
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
