
/*

Mekanik bir kamlumbaðanýn bir odada yürüdüðünü düþünün. Kablumbaða yukarý ve aþaðý pozisyonda olmak üzere bir kalem tutmaktadýr.
Kalem yukarý pozisyonda ise, kablumbaða yürürken yürüdüðü yolu çizmektedir.Kalem aþaðý pozisyonda ise kaplumbaða hiçbir þey çizmeden yürür.

Kamlumbaðaya verilecek emirler:

1		Kalem yukarý
2		Kalem aþaðý
3   	Saða Dön
4		Sola dön
5,10	ileri 10 adým at( ya da 10 dan büyük bir sayý.
6		50 ye 50 lik diziyi yazdýr
9		verinin sonu


Kablumbaðanýn ortalarda bir yerde olduðunu kabul ederseniz aþaðýdaki program 12 ye 12 lik bir kare çizer.

2
5,12
3
5,12
3
5,12
3
5,12
1
6
9

Pseudo code:

1. 50x50 lik bir karede kablumbaða hareket ettireceðiz. Karemiz tamamen 0 dolu.Kablumbaðanýýn elinde bir kalem var.
   Eðer kablumbaða yukarý pozisyonda ise(yani 1) yol çizmektedir (* kullanalým) diðer pozisyonlarda boþluk býrakalým.
   kablumbaða oyun baþýnda 0,0 pozisyonunda bulunuyor.

2. pozisyon[1] isimli iki elemanlý bir dizimiz kablumbaðanýn konumunu saklayacak. Eðer saða 12 adým gittiyse pozisyon[]={1,12}, daha sonra aþaðý 10 adým gittiyse
   pozisyon[]={12,12} olmalý. Sað,sol sütunlar arasý hareketi, yukarý aþaðý satýrlar arasýndaki hareketi gösterir.


*/
#include <stdio.h>

void diziYazdir(const int [][50]);

int main()
{
	int yer[50][50]={0}, emirler[]={2,
									5,12,
									3,
									5,12,
									3,
									5,12,
									3,
									5,12,
									1,
									6,
									9   };
	int pozisyon=0;

	yer[0][11]=3;
	diziYazdir(yer);

}

void diziYazdir(const int yer[][50]){

	for(int i=0;i<50;i++) {
		printf("%\n");
	   for(int j=0;j<50;j++){
	   	  printf("%2d",yer[i][j]);
	   }
 }
}
