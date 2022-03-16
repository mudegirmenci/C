/*
5.9

Bir park yeri iþletmecisi
-3 saate kadar min 2.00$ alýyor
-3 saat aþýmýnda her saat için 0.5$
-maks alýnan para eðer 24 saat park edilirse 10.00$
-24 saatten uzun  süreli hiçbir araç park etmiyor

-Dün bu park yerine park etmiþ 3 müþterinin ödemelerini hesaplayýp yazdýran bir program.
-kullanýcý her müþterinin park saatini girmeli ve çýktý düzgün bir çizelge þeklinde olmalý.
-program ucretHesapla adlý bir fonksiyon kullanmalý.

*/

#include <stdio.h>

float ucretHesapla(int);

int main()
{
	printf("Uc araba icin park kalis surelerini girin:\n");
	
	int i=0,saat;
	
	
	printf("Araba\tSaat\t Ucret\n");
	while(i<3){
	   scanf("%d",&saat);
	   printf("%d %10d %10f\n",i+1,saat,ucretHesapla(saat));
	   	   ++i;	
   }
}

float ucretHesapla(int saat){
	if(saat>=24)
		return 10.00;
	if(saat<=3)
		return 2.00;
	return (2+(saat-3)*0.5)>10.00 ? 10.00 : (2+(saat-3)*0.5);
}
