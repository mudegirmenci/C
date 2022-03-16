/* çek koruma */

#include<stdio.h>
#include<string.h>

int main()
{
   char *birlerB[10]={"","BİR","İKİ","ÜÇ","DÖRT","BEŞ","ALTI","YEDİ","SEKİZ","DOKUZ"};
   char *onlarB[10]={"","ON","YİRMİ","OTUZ","KIRK","ELLİ","ALTMIŞ","YETMİŞ","SEKSEN","DOKSAN"}; 

   int virguldenOnce,virguldenSonra,birler,onlar;

   printf("Çek miktarını giriniz: ");
   scanf("%d.%d",&virguldenOnce,&virguldenSonra);

   if(virguldenOnce<10)
	   printf("%s ",birlerB[virguldenOnce]);
   else {
	   birler=virguldenOnce%10;
	   onlar=virguldenOnce /10;
	   printf("%s%s",onlarB[onlar],birlerB[birler]);
   }
   printf("ve %d/100\n",virguldenSonra);
	   

   

}
