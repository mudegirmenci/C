#include <stdio.h>

/*
Bir tamsay� alan ve tersten yazd�ran program. 

*/

void ters(int);

int main()
{
	int sayi;
	printf("Ters yaz�lacak say�y� girin:\n");
	scanf("%d",&sayi);
	ters(sayi);
}

/* 
-ald��� tamsay�y� tersten yazd�r�r.
-Say�n�n s�rekli mod 10 de�erini yazd�rarak ters sonucu verir.
 */
void ters(int sayi){
	while(sayi%10>0){
		printf("%d",sayi%10);
		sayi/=10;
	}
	
}
