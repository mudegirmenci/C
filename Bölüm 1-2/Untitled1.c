
/*

Mekanik bir kamlumba�an�n bir odada y�r�d���n� d���n�n. Kablumba�a yukar� ve a�a�� pozisyonda olmak �zere bir kalem tutmaktad�r.
Kalem yukar� pozisyonda ise, kablumba�a y�r�rken y�r�d��� yolu �izmektedir.Kalem a�a�� pozisyonda ise kaplumba�a hi�bir �ey �izmeden y�r�r.

Kamlumba�aya verilecek emirler:

1		Kalem yukar�
2		Kalem a�a��
3   	Sa�a D�n
4		Sola d�n
5,10	ileri 10 ad�m at( ya da 10 dan b�y�k bir say�.
6		50 ye 50 lik diziyi yazd�r
9		verinin sonu


Kablumba�an�n ortalarda bir yerde oldu�unu kabul ederseniz a�a��daki program 12 ye 12 lik bir kare �izer.

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

1. 50x50 lik bir karede kablumba�a hareket ettirece�iz. Karemiz tamamen 0 dolu.Kablumba�an��n elinde bir kalem var.
   E�er kablumba�a yukar� pozisyonda ise(yani 1) yol �izmektedir (* kullanal�m) di�er pozisyonlarda bo�luk b�rakal�m.
   kablumba�a oyun ba��nda 0,0 pozisyonunda bulunuyor.

2. pozisyon[1] isimli iki elemanl� bir dizimiz kablumba�an�n konumunu saklayacak. E�er sa�a 12 ad�m gittiyse pozisyon[]={1,12}, daha sonra a�a�� 10 ad�m gittiyse
   pozisyon[]={12,12} olmal�. Sa�,sol s�tunlar aras� hareketi, yukar� a�a�� sat�rlar aras�ndaki hareketi g�sterir.


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
