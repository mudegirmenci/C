/*
4.13 1-13 ars� tek say�lar�n �arp�m�
*/

#include<stdio.h>

int main(void){
	int sayac=1,carpim=1;
	
	while(sayac<=15){
		sayac+=2;
		carpim*=sayac;
	}
	printf("1-30 aras� sayilarin carpimi:%d\n",carpim);
}
