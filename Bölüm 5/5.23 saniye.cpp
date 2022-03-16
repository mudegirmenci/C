#include <stdio.h>
#include <math.h>
/*
Kullan�c�dan saat,dakika ve saniye al�p bunu saat 12 den itibaren yazd�ran program.
iki saat aras�ndaki fark� 12 lik sisteme g�re d�nderen program.

-12 lik sistem i�in saatin 12 modunu al�yoruz.

*/
int saniyeHesapla(int saat,int dakika,int saniye);
void saatFarkiBul(int a);

int main(){
	int saat,dakika,saniye,saat2,dakika2,saniye2;
	printf("%d",(57600/3600)%12);
	printf("Saat dakika ve saniye girin: ");
	scanf("%d%d%d",&saat,&dakika,&saniye);
	printf("ikinci saati girin: ");
	scanf("%d%d%d",&saat2,&dakika2,&saniye2);
	saatFarkiBul(fabs(saniyeHesapla(saat,dakika,saniye)-saniyeHesapla(saat2,dakika2,saniye2)));   //iki saat aras�ndaki fark� bul. mutlak de�erini al
}

int saniyeHesapla(int saat,int dakika,int saniye){
	return (saniye+(dakika*60)+((saat%12)*60*60));
}
void saatFarkiBul(int a){
	int saat=(a/3600)%12;  //12 lik sistemde saat ka�
	a-=saat*3600;			//toplam saniyeden saat ��kar
	int dakika=a/60;		//dakikay� bul
	a-=dakika*60;			//toplam kalan saniyeden dakikan�n saniyesini ��kar. Geriye kalan ger�ek saniyedir.
	
	printf("Saat:%d  Dakika:%d  Saniye:%d  \n",saat,dakika,a);
}



