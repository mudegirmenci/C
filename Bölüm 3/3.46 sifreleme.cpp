/*
3.46  Bir �irket 4 haneli verilerini �ifrelemek istiyor.
      her basamak 7 ile toplan�p 10 luk sistemdeki e�itiyle de�i�meli.
      
      1234
      7777
    +-----
      8901
      
      ve birinci basamaklar ���nc� basamak, ikinci basamakla da d�rd�nc� basamak yer de�i�tirmeli. 8901-->0189 
      temp
      son kodu ��zen program da ayr� yaz�lacak.
*/

#include<stdio.h>

int main()
{
	int veri=0,sifre=0,basamak=1,temp1=0,temp2=0,temp3,temp4;
	printf("Sifrelenecek veriri girin: ");
	scanf("%d",&veri);
	
	while(veri>0) {
	   sifre+=(veri%10)+7>9 ? ((veri%10)+7)%10*basamak : ((veri%10)+7)*basamak;  //kullan�c�n�n girdi�i verinin 10 modunu al e�er mod sonucu ile 7 toplam� tek basamaksa kendi basamak de�eriyle �arp. Yoksa bir daha mod al.
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
