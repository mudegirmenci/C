#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
kullan�c�ya 1-10 aras� rasgele iki say� verip bunu �arpmas�n� istiyoruz. Kullan�c� do�ru cevap verirse tebrikler dizisinden rasgele bir tebrik mesaj�,
yanl�� cevap verirse de yanlisCevap dizisinden rasgele bir mesaj veriyoruz.
-��enci 10 cevap veriyor ve bu 10 cevab�n do�ru y�zdesini hesapl�yoruz. Do�ru y�zdesi %75 alt�ndaysa "��retmeninden yard�m al" mesaj� yazd�r�yoruz
*/
int main(){
	
	int a,b,c,dogru=0,seviye,sec=0,islem;
	char *tebrikler[]={"�ok g�zel","M�kemmel","Aferin","B�yle devam et"};
	char *yanlisCevap[]={"Hay�r.L�tfen tekrar deneyin","Yanl��.L�tfen bir daha deneyin","Pes etmeyin","Hay�r. Denemeye devam edin"};
	char islemTuru;
	
	printf("Hangi seviye istersiniz?(1-10))\n");
	scanf("%d",&seviye);
	
	printf("Hangi i�lemi yapmak istiyorsunuz?(1-toplama, 2-cikarma,3-carpma,4-bolme)\n");
	scanf("%d",&sec);
	
	
	
	for(int i=1;i<10;i++) {
	
		srand(time(NULL));
		a=(int)pow(10,seviye-1)+rand()%(int)pow(10,seviye);    //kullan�c� ka� basamakl� istiyorsa o basamak kadar rasgele say�lar ��kar�r.
		b=(int)pow(10,seviye-1)+rand()%(int)pow(10,seviye);
	
		if(sec==1) {islem=a+b; islemTuru='+';}
		else if(sec==2) {islem=a-b; islemTuru='-';}
		else if(sec==3) {islem=a*b; islemTuru='*';}
		else if(sec==4) {islem=a/b; islemTuru='/';}
	
		printf("%d %c %d nedir?\n",a,islemTuru,b);
		scanf("%d",&c);
		
		
		
		if(islem==c) {
		  printf("%s\n",tebrikler[rand()%4]);
		  dogru++;
	    }
		else printf("%s\n",yanlisCevap[rand()%4]);
   }
   if(dogru*100/10<75) printf("l�tfen ��retmeninden yard�m al. 10 sorudan %d dogru yan�t verdin: Ba�ar� oran�n:y�zde %d\n",dogru,dogru*100/10);
}
