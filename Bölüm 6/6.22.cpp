#include <stdio.h>
/*

Bir þirkette 4 satýþ temsilcisi vardýr ve bu temsilciler 5 farklý ürünü pazarlamaktadýrlar. 
Günlük olarak her satýþ temsilcisi satýlan farklý tipte her ürün için bir fiþ düzenlemektedirler. Her fiþte:
  1. Satýþ temsilcisi numarasý
  2. Ürün Numarasý
  3. O gün içerisinde satýlan ürünün dolar cinsinden miktarý
Her temsilci günlük 0-5 arasý fiþ düzenlemektedir. Son ayýn tüm fiþlerini kullanarak, geçen ay yapýlan tüm satýþlarýn özetini çýkaran bir 
program yazýnýz. 
- Yapýlan tüm satýþlar sales isminde iki boyutlu bir dizide saklanmalý.
- Geçen ayýn satýþlarýný iþledikten sonra, sonuçlarý bir tablo halinde yazdýrýn.Tablo,ilk satýrda satýþ
temsilcileri, ilk sütunda da ürünler olacak þekilde düzenlenmelidir. Herhangi bir satýrýn toplamý, o üründen geçen ay içerisinde yapýlan
satýþýn hesaplanmasýný, her sütunun toplamý da, satýþ temsilcilerinin o ay içerisinde yapmýþ olduðu satýþýn hesaplanmasýný saðlamaktadýr.
- Çýktýnýzda her satýrýn saðýnda ve her sütunun altýnda toplamlarýn yazýlacaðý bir hücre olsun.

*/

int main(){
	int sales[4][5]={2,5,9,8,   //4 satýþ temsilcisi 5 ürün. 
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
