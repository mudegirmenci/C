/*
Kullan�c�dan ald��� ikilik tabanda bir say�y� 10 luk sisteme �evirir.
3.36. Kullan�c�dan ikilik bir say� al.
�nt sayi, toplam,taban=1

While(sayi>=0)
   toplam+=(sayi%10)*taban; -- ikilik say�y� onluk olarak toplama ekle.
   Taban*=2 -- ikilik taban� sola do�ru bir kaydir 
   sayi/=10 --say�y� bir basamak sola kaydir 

*/
#include<stdio.h>

//kenar uzunlu�u verilen bir kareniyi * ile �izer
int main()
{
   int sayi, toplam,taban=1;
   
   printf("ikilik tabanda bir sayi girin:\n");
   scanf("%d",&sayi);
   
   
   while(sayi>0){				//sayi 0 dan b�y�k oldu�u s�rece
   	toplam+=(sayi%10)*taban;	//say�n�n mod 10 ile birler basama��n� al�p tabanla �arp. taban ikilik sistemin birler basama��nda 1 oldu�u i�in 1 ile ba�lat.
   	taban*=2;					//taban� sola do�ru art�r yani ..64  32  16  8  4  2  1...
   	sayi=sayi/10;				//kullan�c�dan ald���m�z say�y� sola bir kayd�r. 1010 ald�ysak, yeni say�m�z 101 olacak
   	
   }
   
   printf("%d",toplam);

   return 0;	
}
