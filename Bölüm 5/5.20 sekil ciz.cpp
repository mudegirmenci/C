#include <stdio.h>

void sekilCiz(int,char);
int main(){

  int kenar;
  char sekil;
  printf("Kenar Girin:\n");
  scanf("%d",&kenar);
  printf("Hangi karakter cizilsin?:\n");
  scanf(" %c",&sekil);       /*�NEML�: scanf %c den �nce bir karakter bo�luk b�rak�lmazsa bir �nceki newline karakterini(veya bo�luk) 
  								tek karakter girilmi� olarak g�r�yor. Dolay�s�yla kod blo�unu �al��t�rm�� gibi yap�p atl�yor.*/
  
  sekilCiz(kenar,sekil);
}

void sekilCiz(int kenar,char sekil){
	for(int i=kenar*kenar;i>0;i--){
		if(i%kenar==0)
			printf("\n");
	   printf("%c",sekil);
	}
}
