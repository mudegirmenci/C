#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
kullanýcýya 1-10 arasý rasgele iki sayý verip bunu çarpmasýný istiyoruz. Kullanýcý doðru cevap verirse tebrikler dizisinden rasgele bir tebrik mesajý,
yanlýþ cevap verirse de yanlisCevap dizisinden rasgele bir mesaj veriyoruz.
-öðenci 10 cevap veriyor ve bu 10 cevabýn doðru yüzdesini hesaplýyoruz. Doðru yüzdesi %75 altýndaysa "öðretmeninden yardým al" mesajý yazdýrýyoruz
*/
int main(){
	
	int a,b,c,dogru=0,seviye,sec=0,islem;
	char *tebrikler[]={"Çok güzel","Mükemmel","Aferin","Böyle devam et"};
	char *yanlisCevap[]={"Hayýr.Lütfen tekrar deneyin","Yanlýþ.Lütfen bir daha deneyin","Pes etmeyin","Hayýr. Denemeye devam edin"};
	char islemTuru;
	
	printf("Hangi seviye istersiniz?(1-10))\n");
	scanf("%d",&seviye);
	
	printf("Hangi iþlemi yapmak istiyorsunuz?(1-toplama, 2-cikarma,3-carpma,4-bolme)\n");
	scanf("%d",&sec);
	
	
	
	for(int i=1;i<10;i++) {
	
		srand(time(NULL));
		a=(int)pow(10,seviye-1)+rand()%(int)pow(10,seviye);    //kullanýcý kaç basamaklý istiyorsa o basamak kadar rasgele sayýlar çýkarýr.
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
   if(dogru*100/10<75) printf("lütfen öðretmeninden yardým al. 10 sorudan %d dogru yanýt verdin: Baþarý oranýn:yüzde %d\n",dogru,dogru*100/10);
}
