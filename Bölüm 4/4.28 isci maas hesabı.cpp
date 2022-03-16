/*

4.28

Müdürler sabit ücret alýrlar
Vardiyalý iþciler 40 saate kadar sabit saatlik ücret, sonrasýnda saatlik ücretin 1.5 katý
Komisyon iþçileri sabit 250$ve haftalýk brüt satýþlarýn %5.7 sini alýrlar.
Parça iþçilerine malzeme baþý sabit ücret, her iþçi tek parça üzerine çalýþýr.

- Her çalýþan tipinin haftalýk maaþýný hesaplayan bir program yaz. 
- Kaç çalýþan var bilinmiyor.
- Her tip çalýþanýn kendi kodu var. Müdür 1, vardiyalý 2, komisyon 3, parça 4

1. Deðiþkenleri tanýmla: calisanTip,haftalikCalismaSaati,haftalikBrutSatis,parcaUcreti
2. switch yapýsý ile calisanTip kontrol et
3. Çalýþan tiplerine göre her case içerisinde maaþ hesaplayýp ekrana yazdýr.

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
