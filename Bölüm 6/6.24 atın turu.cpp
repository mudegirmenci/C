/*

At�n Turu: At, satran� tahtas�ndaki b�t�n kareleri, yani 64 kareyi birden her kareye sadece ama sadece bir kez u�rayarak gezebilir mi?

KURALLAR A�IKLAMALAR:

-Al L �eklinde hareket eder.
-Satran� Tahtas�:tahta[8][8]
-Hamleler yani yatay ve dikey hareketler tek belirte�li yatay ve dikey dizileriyle temsil edilecek.
-E�er at ortalarda bir yerdeyse maksimum hamle say�s� 8 olacakt�r. Bu nedenle dikey[8] ve yatay[8] dizileri 8 olacak. 
 Hamle yapmak 0-7 aras�nda de�er alan hamle de�i�keni ile ayarlan�r.
-Sola yatay hamleler ve yukar� dikey hamleler negatif say�larla g�sterilsin.
-�rne�in yatay[2] =2 ve dikey [2]=-1 ise bunun anlam� yatay sa�a 2 birim, dikey yukar� 1 birim hareket edilmi�.
-bulunanSatir ve bulunanSutun o anda at�n hangi sat�r ve s�tunda oldu�unu g�sterir.
	bulunanSatir+=dikey[hamle];
	bulunanSutun+=yatay[hamle];
-At her kareden bir defa ge�ece�i i�in toplam 64 kare gezinecek. sayac=64 de�i�keni bu say�y� tutacak. Program�m�z while(sayac>0) oldu�u s�rece �al��acak.
 her kare hareketi i�in saya� de�i�keni 1 d��ecek.
-Oyun ba�lang�� noktas� rasgele bir yer olabilir.
-Her hamlede gidilen sat�ra 1-64 aras� s�ra numaras� atanacak. ilk hamle �� kare de�i�tirir o halde karelere s�rayla ,2,3  girilsin.
-E�er karedeki de�er 0 dan farkl�ysa hamle yap�labilir.
	
Pseudo Code:

	1. De�i�kenleri tan�mla, 8x8 karenin tamam�n� 0 olarak ayarla.
	2- At rasgele bir kareden oyuna ba�lar.
	3. While 1-63 aras� sayac sayar. toplam d�ng�m�z sadece 63 tane(at�n rasgele ilk yerle�iminde karenin biri dolmu�tu.)
	4- Olas� 8 hamleden birini rasgele se�er.
	5- Se�ilen hamle uygun mu kontrol edilir.
		-E�er tahta s�n�rlar�na denk geliyorsa uygun de�il, rasgele yeni bir hamle se�.
			-tahta s�n�rlar�n� bulunanSatir ve bulunanSutun de�i�kenleri ile kontrol et. E�er potansiyel hamle sonucu bubulunaSatir veya bulunulanSutun de�erleri 0 dan 
			k���k veya 7 den b�y�kse hamle ge�ersiz.
		-E�er se�ilen hamle at�n daha �nce geldi�i karelerden birine denk geliyorsa ba�ka bir hamle se�.
		    -E�er potansiyel hamlenin oldu�u kare(tahta[bulunanSatir+i gibi ][bulunanSutun]) 0 dan farkl� ise hamle ge�ersiz.
		

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define BOYUT 8
void diziYazdir(const int tahta[][BOYUT]);

int main()
{

	int tahta[BOYUT][BOYUT]={0},bulunanSatir=0,bulunanSutun=0,sayac=64,hamle=0,HamleSayisi=1 ;						//hamle 8 olas� hamle i�in de�i�ken. HamleSayisi hamle yap�lan karelere 1,2,3... yazacak.
	int yatay[]={2,1,-1,-2,-2,-1,1,2},dikey[]={-1,-2,-2,-1,1,2,2,1}; 												//yatay pozitif sa� y�n,yatay negatif sol y�n:dikey pozitif a�a�� y�n, dikey negatif yukar� y�n
diziYazdir(tahta);
	srand(time(NULL));
	bulunanSatir=rand()%BOYUT;
	bulunanSutun=rand()%BOYUT;
	tahta[bulunanSatir][bulunanSutun]=1; 																			/* At tahtada rasgele bir kareden oyuna ba�l�yor.   */
	printf("Baslangic Satir:%d Baslangic Sutun %d \n",bulunanSatir,bulunanSutun);
	
		
	while(sayac>0) { 																									
	
		hamle=0;
	
		while(hamle<=7){ 																								// 8 olas� hamleyi tek tek dene. If bloguna girip hamle �al���rsa i�teki while d�ng�s�nden break ile ��k.Bu �ekilde toplam hamle say�s� 64 olacak 
			
			if(bulunanSatir+dikey[hamle]>=0 && bulunanSatir+dikey[hamle]<=7 && bulunanSutun+yatay[hamle]>=0 &&			//s�n�r a��ld� m� veya kareden daha �nce ge�ildi mi? (fonksiyon olarak yap)			
			 bulunanSutun+yatay[hamle]<=7 && tahta[bulunanSatir+dikey[hamle]][bulunanSutun+yatay[hamle]]==0)	 {
			 	 HamleSayisi++;
			     bulunanSatir+=dikey[hamle];
				 bulunanSutun+=yatay[hamle];
				 tahta[bulunanSatir][bulunanSutun]=HamleSayisi;	
				 break;
				
		    }
		    hamle++;														    		  								//  printf("Sayac %d icin Hamle No:%d  ve HamleSayisi:%d\n",sayac,hamle,HamleSayisi);
		 }
		 
	   if(hamle==8){																									//Hamle yapacak yer kalmad� d�ng�y� bitir.
	   		printf("Hamleniz Kalmadi.Toplam %d hamle yaptiniz\n",HamleSayisi);
			break;	}	
       sayac--;
	}
	
	diziYazdir(tahta);
}


void diziYazdir(const int tahta[][BOYUT]){

	for(int i=0,sayac=1;i<BOYUT;i++) {
		printf("%\n");
	   for(int j=0;j<BOYUT;j++){
	   	  printf("%3d",tahta[i][j]);
	   	  sayac++;
	   }
 }
}

