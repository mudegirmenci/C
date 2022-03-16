#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int a,b,c;
	
	srand(time(NULL));
	a=1+rand()%10;
	b=1+rand()%10;
	
	printf("%d kere %d nedir?",a,b);
	scanf("%d",&c);
	
	if(a*b==c) printf("Çok güzel\n");
	else printf("lütfen tekrar deneyin\n");
}
