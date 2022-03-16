/*
3.46  Bir þirket 4 haneli verilerini þifrelemek istiyor.
      her basamak 7 ile toplanýp 10 luk sistemdeki eþitiyle deðiþmeli.
      
      1234
      7777
    +-----
      8901
      
      ve birinci basamaklar üçüncü basamak, ikinci basamakla da dördüncü basamak yer deðiþtirmeli. 8901-->0189 
      temp
      son kodu çözen program da ayrý yazýlacak.
*/

#include<stdio.h>

int main()
{
	int veri=0,sifre=0,basamak=1,temp1=0,temp2=0,temp3,temp4;
	printf("Sifrelenecek veriri girin: ");
	scanf("%d",&veri);
	
	while(veri>0) {
	   sifre+=(veri%10)+7>9 ? ((veri%10)+7)%10*basamak : ((veri%10)+7)*basamak;  //kullanýcýnýn girdiði verinin 10 modunu al eðer mod sonucu ile 7 toplamý tek basamaksa kendi basamak deðeriyle çarp. Yoksa bir daha mod al.
	   veri=veri/10;
	   basamak*=10;
	}
	
	printf("sifre %d",sifre);
	

		temp1=sifre%10;
		sifre=sifre/10;
		temp2=sifre%10;
		sifre=sifre/10;
		temp3=sifre%10;
		sifre=sifre/10;
		temp4=sifre%10;
		sifre=sifre/10;
		
		sifre=temp1*100+temp3+temp4*10+temp2+temp2*1000;
		
	printf("sifre %d",sifre);
	
	return 0;
}
