#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
kullanýcýya 1-10 arasý rasgele iki sayý verip bunu çarpmasýný istiyoruz. Kullanýcý doðru cevap verirse tebrikler dizisinden rasgele bir tebrik mesajý,
yanlýþ cevap verirse de yanlisCevap dizisinden rasgele bir mesaj veriyoruz.
-öðenci 10 cevap veriyor ve bu 10 cevabýn doðru yüzdesini hesaplýyoruz. Doðru yüzdesi %75 altýndaysa "öðretmeninden yardým al" mesajý yazdýrýyoruz
*/
int main(){
	
	int a,b,c,dogru=0;
	char *tebrikler[]={"Çok güzel","Mükemmel","Aferin","Böyle devam et"};
	char *yanlisCevap[]={"Hayýr.Lütfen tekrar deneyin","Yanlýþ.Lütfen bir daha deneyin","Pes etmeyin","Hayýr. Denemeye devam edin"};
	
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
   if(dogru*100/10<75) printf("lütfen öðretmeninden yardým al. 10 sorudan %d dogru yanýt verdin: Baþarý oranýn:yüzde %d\n",dogru,dogru*100/10);
}
