#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

1-1000 arasý rasgele sayý tutan bilgisayarýn tuttuðu sayýyý tahmin etme.

*/
int main(){
	
	int a,b=0;
	char cevap;
	
	srand(time(NULL));
	a=1+rand()%1000;
		
	while(b!=a) {
	    printf("1-1000 arasinda rasgele bir sayi tuttum\ntahmin edebilirmisin?\nLutfen tahminini gir:\n");
	   scanf("%d",&b);
	   if(a==b) {
	   	printf("Mukemmel bildiniz!");
	   	return 1;
	   } else {
	   	   if(a>b) printf("Cok kucuk. tekrar deneyin.\n");
	   	   else printf("Cok buyuk. tekrar deneyin.\n");
	   	  printf("Tekrar oynamak istermisiniz(E veya H)?)\n");
	   	  scanf(" %c",&cevap);
	   	  if(cevap=='H' || cevap=='h') break;
	   	  else continue;
	   } 
	}
	
}
