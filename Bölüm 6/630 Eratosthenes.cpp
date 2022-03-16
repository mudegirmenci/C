/*

Eratosthenes'in Ele�i

N say�l�k bir dizide, dizideki en k���k asaldan ba�layarak bu asallar�n t�m katlar� asal DE��L olarak i�aretlenir. ��aretlenmeyen say�lar asal say�d�r denir.
�rn:0-100 aras� asal say�lar i�in en k���k asal say� 2 dir. Bu say�n�n katlar� asal de�il olarak i�aretlenir: 4,6,8,10...100. daha sonra 3 

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
	for(int i=1;i<n;i++) sayilar[i]=i+1;   //verilen N say�s�na kadar bir dizi olu�turur.
}
void diziYazdir(const int dizi[],int n){
	for(int i=0;i<n;i++) printf("%d. %d\n",i,dizi[i]);  
}



int asallariBul(int sayilar[],int asallar[],int n ){
	int j=0,k=0;										//1-100 aras�nda ilk 10 say�n�n katlar�n� silmek yeterli.
	for(int i=2;i<n/10;i++){
	    j=i*i;
	    if(sayilar[j-1]!=0){							//say� daha �nce elenmemi�se
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
