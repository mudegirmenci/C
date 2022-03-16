/* 

6.28 

1-20 arasý rasgele sayýlar üretip birbirinin aynýsý olmayan sayýlarý bir dizide saklayan program.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dizideVarmi(int dizi[],int deger,int);
void diziYazdir(const int dizi[]);

int main() {
	
	int dizi[20]={0},deger=0;
	
	srand(time(NULL));
	
	for(int i=0;i<20;i++){
			
		do {
			deger=1+rand()%20;
		}
		while(dizideVarmi(dizi,deger,i)==0);  //dizide olmayan deger bulana kadar arama yap.
	}
	diziYazdir(dizi);
}
void diziYazdir(const int dizi[]){
	for(int i=0;i<20;i++)
		printf("%d:%3d\n",i+1,dizi[i]);
}
int dizideVarmi(int dizi[],int deger,int j) {
	for(int i=0;i<20;i++) {
		if(dizi[i]==deger) return 0;	//eðer dizide varsa 0 dönder
	}
    
	dizi[j]=deger;
	return 1;		
}
