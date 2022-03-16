#include <stdio.h>

void sekilCiz(int,char);
int main(){

  int kenar;
  char sekil;
  printf("Kenar Girin:\n");
  scanf("%d",&kenar);
  printf("Hangi karakter cizilsin?:\n");
  scanf(" %c",&sekil);       /*ÖNEMLÝ: scanf %c den önce bir karakter boþluk býrakýlmazsa bir önceki newline karakterini(veya boþluk) 
  								tek karakter girilmiþ olarak görüyor. Dolayýsýyla kod bloðunu çalýþtýrmýþ gibi yapýp atlýyor.*/
  
  sekilCiz(kenar,sekil);
}

void sekilCiz(int kenar,char sekil){
	for(int i=kenar*kenar;i>0;i--){
		if(i%kenar==0)
			printf("\n");
	   printf("%c",sekil);
	}
}
