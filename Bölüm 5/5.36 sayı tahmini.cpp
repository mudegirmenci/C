#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

1-1000 aras� rasgele say� tutan bilgisayar�n tuttu�u say�y� tahmin etme. Tahmin say�s� 10 veya alt� bir say�yla do�ru sonuca ula��labilir.
tahmin say�s�n� s�rekli yar�lamak gerekiyor. 1000-500-250-125 vs.

*/
int main(){
	
	int a,b=0,sayac=0;
	char cevap;
	
	srand(time(NULL));
	a=1+rand()%1000;
		
	while(b!=a) {
	    printf("1-1000 arasinda rasgele bir sayi tuttum\ntahmin edebilirmisin?\nLutfen tahminini gir:\n");
	   scanf("%d",&b);
	   sayac++;
	   if(a==b) {
	   	printf("Mukemmel bildiniz!");
	   	  if(sayac<10) printf("Siz sirri biliyorsunuz ya da sanslisiniz.\nToplam tahmin sayisi:%d\n",sayac);
	   	  else if(sayac==10) printf("Aha! siz sirri biliyorsunuz.\n");
	   	  else if(sayac>10) printf("Daha iyisini yapabilirsiniz.\n");
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
