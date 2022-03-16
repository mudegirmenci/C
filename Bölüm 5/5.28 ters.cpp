#include <stdio.h>

/*
Bir tamsayý alan ve tersten yazdýran program. 

*/

void ters(int);

int main()
{
	int sayi;
	printf("Ters yazýlacak sayýyý girin:\n");
	scanf("%d",&sayi);
	ters(sayi);
}

/* 
-aldýðý tamsayýyý tersten yazdýrýr.
-Sayýnýn sürekli mod 10 deðerini yazdýrarak ters sonucu verir.
 */
void ters(int sayi){
	while(sayi%10>0){
		printf("%d",sayi%10);
		sayi/=10;
	}
	
}
