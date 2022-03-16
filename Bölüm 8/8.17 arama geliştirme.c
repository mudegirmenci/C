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
        araPtr arama yapýlan girdi stringinde bulunan aramaTeriminden itibaren stringi tutar.
        örnek: girdi>string içinde arama yap araTerimi>in  araPtr>ing içinde arama yap
        ikinci strstr ise(araPtr+1) ayný arama terimini kalan string içinde yani "ing içinde arama yap" içinde arar.
        bunun için arama bir sonraki karakterden baþlamalý yoksa, ilk "in" stringi tekrar bulunur. Bunu da araPtr+1
        ile saðlýyoruz.
    */

    /* ilk kullaným için hazýrla */
    araPtr = strstr(girdi,aramaTerimi);
    for(i=0;araPtr!=NULL;i++) {
       puts(araPtr);
       araPtr = strstr((araPtr+1),aramaTerimi);
    }
   printf("%s terimi metin icinde %d adet bulundu:\n",aramaTerimi,i);


}
