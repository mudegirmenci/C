#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int a,b,c;
	char tebrikler[]={"Çok güzel","Mükemmel","Aferin","Böyle devam et"};
	char *yanlisCevap[]={"Hayýr.Lütfen tekrar deneyin","Yanlýþ.Lütfen bir daha deneyin","Pes etmeyin","Hayýr. Denemeye devam edin"};
	
	srand(time(NULL));
	a=1+rand()%10;
	b=1+rand()%10;
	
	printf("%d kere %d nedir?",a,b);
	scanf("%d",&c);
	
	if(a*b==c) printf("%s\n",tebrikler[rand()%4]);
	else printf("%s\n",yanlisCevap[rand()%4]);
}
