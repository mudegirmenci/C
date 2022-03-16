/*

Belli bir harfle baþlayan dizi elemanlarýný listeler.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDIS 10
void harfiIleBaslayanlar(char *dizi[],char c);

int main(){

  char *ilceler[10]={"hacilar","ardicli","karafakili","su gedigi","gudaller","haydarlar","sogut","kizillar","gulpinar","hacihasan"};

  harfiIleBaslayanlar(ilceler,'h');

}

void harfiIleBaslayanlar(char *dizi[],char c)
{
    char *temp;

  for(int i=0;i<INDIS;i++) {
    temp=dizi[i];
    if(temp[0]==c) printf("%s\n",temp);
  }

}
