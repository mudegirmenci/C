#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDIS 10
void bubbleSort(char *dizi[]);

int main(){

  char *ilceler[10]={"hacilar","ardicli","karafakili","su gedigi","gudaller","haydarlar","sogut","kizillar","gulpinar","hacihasan"};

  bubbleSort(ilceler);
  //printf("%s",ilceler[2]);

}

void bubbleSort(char *dizi[])
{


  int kontrol=0,k;
  char *temp;


	for(int tur=1;*dizi;tur++,kontrol=0) {		 //tur sayýsý
	   for(int i=0;i<INDIS-(tur+1);i++){
			k = strcmp(dizi[i],dizi[i+1]);

			if(k>0){
				temp=dizi[i];
				dizi[i]=dizi[i+1];
				dizi[i+1]=temp;
				kontrol=1;
			}
        }
   if(kontrol==0) break;  //herhangi bir yer deđiţikliđi yapýlmamýţsa, dizi sýralýdýr. Bu durumda döngüye devam etmeye gerek yok.

   }

	printf("\n");
	printf("Veriler artan sýrada:\n");

	for(int i=0;i<INDIS-1;i++)
		printf("%s\n",dizi[i]);

}
