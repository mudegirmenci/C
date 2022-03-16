/*
4.13 1-13 arsý tek sayýlarýn çarpýmý
*/

#include<stdio.h>

int main(void){
	int sayac=1,carpim=1;
	
	while(sayac<=15){
		sayac+=2;
		carpim*=sayac;
	}
	printf("1-30 arasý sayilarin carpimi:%d\n",carpim);
}
