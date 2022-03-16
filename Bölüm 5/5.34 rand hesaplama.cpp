#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
kullan�c�ya 1-10 aras� rasgele iki say� verip bunu �arpmas�n� istiyoruz. Kullan�c� do�ru cevap verirse tebrikler dizisinden rasgele bir tebrik mesaj�,
yanl�� cevap verirse de yanlisCevap dizisinden rasgele bir mesaj veriyoruz.
-��enci 10 cevap veriyor ve bu 10 cevab�n do�ru y�zdesini hesapl�yoruz. Do�ru y�zdesi %75 alt�ndaysa "��retmeninden yard�m al" mesaj� yazd�r�yoruz
*/
int main(){
	
	int a,b,c,dogru=0;
	char *tebrikler[]={"�ok g�zel","M�kemmel","Aferin","B�yle devam et"};
	char *yanlisCevap[]={"Hay�r.L�tfen tekrar deneyin","Yanl��.L�tfen bir daha deneyin","Pes etmeyin","Hay�r. Denemeye devam edin"};
	
	for(int i=1;i<=10;i++) {
	
		srand(time(NULL));
		a=1+rand()%10;
		b=1+rand()%10;
	
		printf("%d kere %d nedir?",a,b);
		scanf("%d",&c);
	
		if(a*b==c) {
		  printf("%s\n",tebrikler[rand()%4]);
		  dogru++;
	    }
		else printf("%s\n",yanlisCevap[rand()%4]);
   }
   if(dogru*100/10<75) printf("l�tfen ��retmeninden yard�m al. 10 sorudan %d dogru yan�t verdin: Ba�ar� oran�n:y�zde %d\n",dogru,dogru*100/10);
}
