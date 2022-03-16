#include <stdio.h>
#include <math.h>
/*
Kullanıcıdan saat,dakika ve saniye alıp bunu saat 12 den itibaren yazdıran program.
iki saat arasındaki farkı 12 lik sisteme göre dönderen program.

-12 lik sistem için saatin 12 modunu alıyoruz.

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
	saatFarkiBul(fabs(saniyeHesapla(saat,dakika,saniye)-saniyeHesapla(saat2,dakika2,saniye2)));   //iki saat arasındaki farkı bul. mutlak değerini al
}

int saniyeHesapla(int saat,int dakika,int saniye){
	return (saniye+(dakika*60)+((saat%12)*60*60));
}
void saatFarkiBul(int a){
	int saat=(a/3600)%12;  //12 lik sistemde saat kaç
	a-=saat*3600;			//toplam saniyeden saat çıkar
	int dakika=a/60;		//dakikayı bul
	a-=dakika*60;			//toplam kalan saniyeden dakikanın saniyesini çıkar. Geriye kalan gerçek saniyedir.
	
	printf("Saat:%d  Dakika:%d  Saniye:%d  \n",saat,dakika,a);
}



