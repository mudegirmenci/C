/*

Eratosthenes'in Eleði

N sayýlýk bir dizide, dizideki en küçük asaldan baþlayarak bu asallarýn tüm katlarý asal DEÐÝL olarak iþaretlenir. Ýþaretlenmeyen sayýlar asal sayýdýr denir.
Örn:0-100 arasý asal sayýlar için en küçük asal sayý 2 dir. Bu sayýnýn katlarý asal deðil olarak iþaretlenir: 4,6,8,10...100. daha sonra 3 

*/

#include <stdio.h>
#include <math.h>

#define BOYUT 100


void diziyiAyarla(int dizi[],int n);
void diziYazdir(const int dizi[],int n);
int asallariBul(int sayilar[],int asallar[],int n);

int main(){
	int sayilar[BOYUT],asallar[BOYUT]={0},asalSayisi;
	
	
	diziyiAyarla(sayilar,BOYUT);
	
	asalSayisi=asallariBul(sayilar,asallar,BOYUT);
	
    printf("asalSayisi:%d\n",asalSayisi);
	diziYazdir(asallar,asalSayisi);
}

void diziyiAyarla(int sayilar[],int n){
	sayilar[0]=0;
	for(int i=1;i<n;i++) sayilar[i]=i+1;   //verilen N sayýsýna kadar bir dizi oluþturur.
}
void diziYazdir(const int dizi[],int n){
	for(int i=0;i<n;i++) printf("%d. %d\n",i,dizi[i]);  
}



int asallariBul(int sayilar[],int asallar[],int n ){
	int j=0,k=0;										//1-100 arasýnda ilk 10 sayýnýn katlarýný silmek yeterli.
	for(int i=2;i<n/10;i++){
	    j=i*i;
	    if(sayilar[j-1]!=0){							//sayý daha önce elenmemiþse
		  	while(j<=n) {
			  sayilar[j-1]=0;
			  j+=i;
		    }
		}
    }
    
	for(int i=0;i<n;i++) {
    	if(sayilar[i]!=0)    asallar[k++]=sayilar[i];
		 
	}
     
 return k;
}
