#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char girdi[200],aramaTerimi[20];
    char *araPtr;
    int i;
    puts("Metin girin>");
    gets(girdi);
    puts("strstr ile aranacak metin girin>");
    gets(aramaTerimi);

    /*
        araPtr arama yap�lan girdi stringinde bulunan aramaTeriminden itibaren stringi tutar.
        �rnek: girdi>string i�inde arama yap araTerimi>in  araPtr>ing i�inde arama yap
        ikinci strstr ise(araPtr+1) ayn� arama terimini kalan string i�inde yani "ing i�inde arama yap" i�inde arar.
        bunun i�in arama bir sonraki karakterden ba�lamal� yoksa, ilk "in" stringi tekrar bulunur. Bunu da araPtr+1
        ile sa�l�yoruz.
    */

    /* ilk kullan�m i�in haz�rla */
    araPtr = strstr(girdi,aramaTerimi);
    for(i=0;araPtr!=NULL;i++) {
       puts(araPtr);
       araPtr = strstr((araPtr+1),aramaTerimi);
    }
   printf("%s terimi metin icinde %d adet bulundu:\n",aramaTerimi,i);


}
