#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 5

int main()
{
    const char *isim[ARRAYSIZE] ={"erkek","kiz","kopek","sehir","araba"};
    const char *edat[ARRAYSIZE] ={"dogru","uzerine","yanina","arkasina","basina"};
    const char *fiil[ARRAYSIZE] ={"surdu","atladi","kostu","yurudu","gecti"};

    char kelime[100];

    srand(time(NULL));

    int x,y,z,n,i=0;

    while(++i<20) {
        x=rand()%ARRAYSIZE;
        y=rand()%ARRAYSIZE;
        z=rand()%ARRAYSIZE;
        n=rand()%ARRAYSIZE;

        strcpy(kelime,isim[x]);   //ismi kelimeye kopyala
        strcat(kelime," ");       //bo�luk
        strcat(kelime,isim[n]);   //ismi kelimeye kopyala
        strcat(kelime,"in");
        strcat(kelime," ");       //bo�luk ekle
        strcat(kelime,edat[y]);   //edat ekle
        strcat(kelime," ");       //bo�luk ekle
        strcat(kelime,fiil[z]);   //fiil ekle
        strcat(kelime,".");       //. ekle

        /*
            farkl� olarak bu �ekilde de yap�labilir. Yukardaki sat�rlar� silinmesi yeterli.(strcpyden itibaren)
            strcat(strcat(strcat(strcat(strcat(strcpy(kelime,isim[y])," "),edat[y])," "),fiil[z]),".");
        */

        kelime[0] = toupper(kelime[0]);  //ilk harfi b�y�k yap
        printf("%s\n",kelime );

        if(i%5==0) printf("\n");

    }
    return 0;

}
