#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char girdi[200],aramaTerimi[20];
    char *araPtr;

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
    araPtr = strstr(girdi,aramaTerimi);

    if(araPtr)
       printf("%s\n",araPtr);

    araPtr = strstr((araPtr+1),aramaTerimi);

      if(araPtr)
        puts(araPtr);



}
