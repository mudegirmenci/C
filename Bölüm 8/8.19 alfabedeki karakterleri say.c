/*

Girilen metin i�erisinde alfabedeki karakterlerden ka� tane bulundu�unu bulur.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char girdi[200],aramaTerimi[50];
    char *araPtr;
    int i,k=0;

    /* b�y�k harfleri diziye al*/
    for(int j=65;k<26;j++,k++)
        aramaTerimi[k]=j;

   /*k���k harfleri diziye al*/
    for(int j=97;k<42;j++,k++)
        aramaTerimi[k]=j;

    puts("Metin girin>");
    gets(girdi);



    /*
        araPtr arama yap�lan girdi stringinde bulunan aramaTeriminden itibaren stringi tutar.
        �rnek: girdi>string i�inde arama yap araTerimi>in  araPtr>ing i�inde arama yap
        ikinci strstr ise(araPtr+1) ayn� arama terimini kalan string i�inde yani "ing i�inde arama yap" i�inde arar.
        bunun i�in arama bir sonraki karakterden ba�lamal� yoksa, ilk "in" stringi tekrar bulunur. Bunu da araPtr+1
        ile sa�l�yoruz.
    */

    /* 42 karakterin tamam�n� girilen metin i�inde ara*/
    for(int j=0;j<42;j++) {
        araPtr = strchr(girdi,aramaTerimi[j]);
        for(i=0;araPtr!=NULL;i++) {
          araPtr = strchr((araPtr+1),aramaTerimi[j]);
        }
        /* j s�radaki karakterden bulunduysa*/
        if(i>0)
          printf("%c karakteri metin icinde %d adet bulundu:\n",aramaTerimi[j],i);
        /*sayac� s�f�rla */
        i=0;

    }




}
