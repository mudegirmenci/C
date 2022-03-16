/*

Sonu "ar" ile biten stringler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDIS 10
void sonHarfler(char *dizi[],char *);

int main(){

  char *ilceler[10]={"hacilar","ardicli","karafakili","su gedigi","gudaller","haydarlar","sogut","kizillar","gulpinar","hacihasan"};
  char *sonek ="ar";

  sonHarfler(ilceler,sonek);

}

void sonHarfler(char *dizi[],char *sonek)
{
    char *temp,*ek;
    int k;

  for(int i=0;i<INDIS;i++) {
    temp=dizi[i];
    k=strlen(temp);
    if(temp[k-1]==sonek[1] && temp[k-2]==sonek[0] ) printf("%s\n",temp);
  }

}
