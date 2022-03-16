#include <stdio.h>
#include <math.h>

int sayiyiBol(int,int);
int kalaniBul(int,int);
int main()
{
	int sayi,bolen=10000;
	printf("1-32767 arasi bir sayi girin:\n");
	scanf("%d",&sayi);
	
	while(sayi>=1){
		if(sayi>=bolen){
			printf("%d  ",sayiyiBol(sayi,bolen));
			sayi=kalaniBul(sayi,bolen);	
			bolen=sayiyiBol(bolen,10);
	    } else bolen=sayiyiBol(bolen,10);
	}
		
	
}
int sayiyiBol(int a,int b){
	return a/b;
}
int kalaniBul(int a,int b){
	return a%b;
}

