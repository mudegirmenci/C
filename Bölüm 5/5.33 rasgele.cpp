#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int a,b,c;
	char tebrikler[]={"�ok g�zel","M�kemmel","Aferin","B�yle devam et"};
	char *yanlisCevap[]={"Hay�r.L�tfen tekrar deneyin","Yanl��.L�tfen bir daha deneyin","Pes etmeyin","Hay�r. Denemeye devam edin"};
	
	srand(time(NULL));
	a=1+rand()%10;
	b=1+rand()%10;
	
	printf("%d kere %d nedir?",a,b);
	scanf("%d",&c);
	
	if(a*b==c) printf("%s\n",tebrikler[rand()%4]);
	else printf("%s\n",yanlisCevap[rand()%4]);
}
