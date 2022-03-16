/*

Girilen metin içerisinde alfabedeki karakterlerden kaç tane bulunduðunu bulur.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char girdi[200],aramaTerimi[50];
    char *araPtr;
    int i,k=0;

    /* büyük harfleri diziye al*/
    for(int j=65;k<26;j++,k++)
        aramaTerimi[k]=j;

   /*küçük harfleri diziye al*/
    for(int j=97;k<42;j++,k++)
        aramaTerimi[k]=j;

    puts("Metin girin>");
    gets(girdi);



    /*
        araPtr arama yapýlan girdi stringinde bulunan aramaTeriminden itibaren stringi tutar.
        örnek: girdi>string içinde arama yap araTerimi>in  araPtr>ing içinde arama yap
        ikinci strstr ise(araPtr+1) ayný arama terimini kalan string içinde yani "ing içinde arama yap" içinde arar.
        bunun için arama bir sonraki karakterden baþlamalý yoksa, ilk "in" stringi tekrar bulunur. Bunu da araPtr+1
        ile saðlýyoruz.
    */

    /* 42 karakterin tamamýný girilen metin içinde ara*/
    for(int j=0;j<42;j++) {
        araPtr = strchr(girdi,aramaTerimi[j]);
        for(i=0;araPtr!=NULL;i++) {
          araPtr = strchr((araPtr+1),aramaTerimi[j]);
        }
        /* j sýradaki karakterden bulunduysa*/
        if(i>0)
          printf("%c karakteri metin icinde %d adet bulundu:\n",aramaTerimi[j],i);
        /*sayacý sýfýrla */
        i=0;

    }




}
