/*
Kullanýcýdan aldýðý ikilik tabanda bir sayýyý 10 luk sisteme çevirir.
3.36. Kullanýcýdan ikilik bir sayý al.
Ýnt sayi, toplam,taban=1

While(sayi>=0)
   toplam+=(sayi%10)*taban; -- ikilik sayýyý onluk olarak toplama ekle.
   Taban*=2 -- ikilik tabaný sola doðru bir kaydir 
   sayi/=10 --sayýyý bir basamak sola kaydir 

*/
#include<stdio.h>

//kenar uzunluðu verilen bir kareniyi * ile çizer
int main()
{
   int sayi, toplam,taban=1;
   
   printf("ikilik tabanda bir sayi girin:\n");
   scanf("%d",&sayi);
   
   
   while(sayi>0){				//sayi 0 dan büyük olduðu sürece
   	toplam+=(sayi%10)*taban;	//sayýnýn mod 10 ile birler basamaðýný alýp tabanla çarp. taban ikilik sistemin birler basamaðýnda 1 olduðu için 1 ile baþlat.
   	taban*=2;					//tabaný sola doðru artýr yani ..64  32  16  8  4  2  1...
   	sayi=sayi/10;				//kullanýcýdan aldýðýmýz sayýyý sola bir kaydýr. 1010 aldýysak, yeni sayýmýz 101 olacak
   	
   }
   
   printf("%d",toplam);

   return 0;	
}
