/*

4.28

M�d�rler sabit �cret al�rlar
Vardiyal� i�ciler 40 saate kadar sabit saatlik �cret, sonras�nda saatlik �cretin 1.5 kat�
Komisyon i��ileri sabit 250$ve haftal�k br�t sat��lar�n %5.7 sini al�rlar.
Par�a i��ilerine malzeme ba�� sabit �cret, her i��i tek par�a �zerine �al���r.

- Her �al��an tipinin haftal�k maa��n� hesaplayan bir program yaz. 
- Ka� �al��an var bilinmiyor.
- Her tip �al��an�n kendi kodu var. M�d�r 1, vardiyal� 2, komisyon 3, par�a 4

1. De�i�kenleri tan�mla: calisanTip,haftalikCalismaSaati,haftalikBrutSatis,parcaUcreti
2. switch yap�s� ile calisanTip kontrol et
3. �al��an tiplerine g�re her case i�erisinde maa� hesaplay�p ekrana yazd�r.

*/

#include<stdio.h>

int main()
{
	int calisanTip,haftalikCalismaSaati=61,parcaSayisi=15;
	float haftalikBrutSatis=10000,parcaUcreti=20,saatlikUcret=15;
	
	printf("Calisan tipi girin:");
	scanf("%d",&calisanTip);
	switch(calisanTip){
		
		case 1:
		   printf("Mudur haftalik maas:$1000\n");
		   break;
		
		case 2:
		   printf("Vardiyali isci haftalik maas:%f\n",(haftalikCalismaSaati*saatlikUcret)+(haftalikCalismaSaati-40)*saatlikUcret*1.5);
		  break;
		case 3:
		   printf("Komisyon iscisi haftalik mass:%f\n",250+(haftalikBrutSatis*5.7)/100);
		   break;
		case 4:
		   printf("Parca iscisi haftalik maas:%f\n",parcaSayisi*parcaUcreti);
		   break;
		default:
			break;
	}
}
