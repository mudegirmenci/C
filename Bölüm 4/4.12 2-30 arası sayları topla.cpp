/*
4.12  2-30 arasý çift sayýlarýn toplamý
*/

#include<stdio.h>

int main(void){
	int sayac=0,toplam=0;
	
	while(sayac<=30){
		sayac+=2;
		   toplam+=sayac;
	}
	printf("1-30 arasý sayilarin toplami:%d\n",toplam);
}
