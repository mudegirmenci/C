#include<stdio.h>

int main()
{
	int sayac=1;
	
	while(sayac<=10){
		printf("%s\n",sayac%2 ?"****":"++++++++" ); //2 bölümünden kalan 1 veya 0 olacak
		++sayac;
	}
	
	return 0;
}
