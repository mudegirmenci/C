#include <stdio.h>
/*

Bir �irkette 4 sat�� temsilcisi vard�r ve bu temsilciler 5 farkl� �r�n� pazarlamaktad�rlar. 
G�nl�k olarak her sat�� temsilcisi sat�lan farkl� tipte her �r�n i�in bir fi� d�zenlemektedirler. Her fi�te:
  1. Sat�� temsilcisi numaras�
  2. �r�n Numaras�
  3. O g�n i�erisinde sat�lan �r�n�n dolar cinsinden miktar�
Her temsilci g�nl�k 0-5 aras� fi� d�zenlemektedir. Son ay�n t�m fi�lerini kullanarak, ge�en ay yap�lan t�m sat��lar�n �zetini ��karan bir 
program yaz�n�z. 
- Yap�lan t�m sat��lar sales isminde iki boyutlu bir dizide saklanmal�.
- Ge�en ay�n sat��lar�n� i�ledikten sonra, sonu�lar� bir tablo halinde yazd�r�n.Tablo,ilk sat�rda sat��
temsilcileri, ilk s�tunda da �r�nler olacak �ekilde d�zenlenmelidir. Herhangi bir sat�r�n toplam�, o �r�nden ge�en ay i�erisinde yap�lan
sat���n hesaplanmas�n�, her s�tunun toplam� da, sat�� temsilcilerinin o ay i�erisinde yapm�� oldu�u sat���n hesaplanmas�n� sa�lamaktad�r.
- ��kt�n�zda her sat�r�n sa��nda ve her s�tunun alt�nda toplamlar�n yaz�laca�� bir h�cre olsun.

*/

int main(){
	int sales[4][5]={2,5,9,8,   //4 sat�� temsilcisi 5 �r�n. 
					4,7,6,8,
					5,4,5,7,
					6,9,7,2,
					3,6,8,4};   
	
	
	for(int i=0;i<4;i++){
		printf("Urun No:%2d -> ",i+1);
	  for(int j=0;j<5;j++){
	   	printf("%d ",sales[i][j]);
	   }
	   printf("\n");
   }
}
