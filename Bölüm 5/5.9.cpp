/*
5.9

Bir park yeri i�letmecisi
-3 saate kadar min 2.00$ al�yor
-3 saat a��m�nda her saat i�in 0.5$
-maks al�nan para e�er 24 saat park edilirse 10.00$
-24 saatten uzun  s�reli hi�bir ara� park etmiyor

-D�n bu park yerine park etmi� 3 m��terinin �demelerini hesaplay�p yazd�ran bir program.
-kullan�c� her m��terinin park saatini girmeli ve ��kt� d�zg�n bir �izelge �eklinde olmal�.
-program ucretHesapla adl� bir fonksiyon kullanmal�.

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
