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
-Eri�ilebilirlik, ilgili kareye ka� kareden eri�ilebilece�ini g�sterir.Eri�ilebilirli�i d���k olan karelere �ncelikli hamle yapar�z.
	
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
void erisilebilirlikAyarla(int erisilebilirlik[][BOYUT]);


int main()
{

	int tahta[BOYUT][BOYUT]={0},bulunanSatir=0,bulunanSutun=0,sayac=64,hamle=0,HamleSayisi=1,enUygunHamle=-1;			//hamle 8 olas� hamle i�in de�i�ken. HamleSayisi hamle yap�lan karelere 1,2,3... yazacak.
	int yatay[]={2,1,-1,-2,-2,-1,1,2},dikey[]={-1,-2,-2,-1,1,2,2,1};													//yatay sa� pozitif,yatay sol negatif :dikey a�a�� y�n pozitif,  dikey negatif yukar� y�n			 
	int erisilebilirlik[BOYUT][BOYUT]={0};

	erisilebilirlikAyarla(erisilebilirlik);    //eri�ilebilirlik tablosunu ayarlar. 
	
	/* At tahtada rasgele bir kareden oyuna ba�l�yor.   */
	srand(time(NULL));
	bulunanSatir=rand()%BOYUT;  //6
	bulunanSutun=rand()%BOYUT;  //0 degerlerinde at tam tur yapiyor.
	tahta[bulunanSatir][bulunanSutun]=1; //Ba�lad���m�z kareyi oradan ge�ildi olarak i�aretliyoruz.
														
	printf("Baslangic Satir:%d Baslangic Sutun %d \n",bulunanSatir,bulunanSutun);
	
		
	while(--sayac>0) { 		//Toplam 64 hamle yapmak istiyoruz.																							
	
		for(int hamle=0;hamle<=7;hamle++){ 																				// 8 olas� hamleyi tek tek dene. If bloguna girip hamle �al���rsa i�teki while d�ng�s�nden break ile ��k.Bu �ekilde toplam hamle say�s� 64 olacak 
			
			if(bulunanSatir+dikey[hamle]>=0 && bulunanSatir+dikey[hamle]<=7 && bulunanSutun+yatay[hamle]>=0 &&			//s�n�r a��ld� m� veya kareden daha �nce ge�ildi mi? (fonksiyon olarak yap)			
			 bulunanSutun+yatay[hamle]<=7 && tahta[bulunanSatir+dikey[hamle]][bulunanSutun+yatay[hamle]]==0)	 {
			 			 	
				if (enUygunHamle==-1)  //ilk de�er ayarla
				       enUygunHamle=hamle;
				if (erisilebilirlik[bulunanSatir+dikey [hamle]][bulunanSutun+yatay[hamle]]==erisilebilirlik[bulunanSatir+dikey [enUygunHamle]][bulunanSutun+yatay[enUygunHamle]]){
					if (erisilebilirlik[bulunanSatir+dikey [hamle+1]][bulunanSutun+yatay[hamle+1]]<erisilebilirlik[bulunanSatir+dikey [enUygunHamle]][bulunanSutun+yatay[enUygunHamle]])
					  		enUygunHamle=hamle;
					}else if (erisilebilirlik[bulunanSatir+dikey [hamle]][bulunanSutun+yatay[hamle]]<=erisilebilirlik[bulunanSatir+dikey [enUygunHamle]][bulunanSutun+yatay[enUygunHamle]])
				    	 enUygunHamle=hamle;
				
			}
			
		}
		if(enUygunHamle!=-1){
			HamleSayisi++;
		    bulunanSatir+=dikey[enUygunHamle];
		    bulunanSutun+=yatay[enUygunHamle];
		    tahta[bulunanSatir][bulunanSutun]=HamleSayisi;
		   --erisilebilirlik[bulunanSatir][bulunanSutun];
		    enUygunHamle=-1;
		}
	
  
	}
	printf("Hamleniz Kalmadi.Toplam %d hamle yaptiniz\n",HamleSayisi);
	printf("\n");
	printf("At Turu Tablosu:\n");
	diziYazdir(tahta);
	printf("\n");
	printf("Erisilebilirlik Degisim Tablosu:\n");
	diziYazdir(erisilebilirlik);
	printf("\n");
}


void diziYazdir(const int tahta[][BOYUT]){

	for(int i=0,sayac=1;i<BOYUT;i++) {
		printf("%\n");
	   for(int j=0;j<BOYUT;j++){
	   	  printf("%3d",tahta[i][j]);
	   	  sayac++;
	   }
    }
    printf("\n");
}

/* 
istenilen boyutlarda tahta �izmek i�in. Yoksa elle de dizi de�eri atanabilirdi. Veya bu diziyi olu�turman�n belki daha kolay yolu vard�r.
 */
void erisilebilirlikAyarla(int erisilebilirlik[][BOYUT]){

		for(int i=0;i<BOYUT;i++){
				for(int j=0;j<BOYUT;j++){
					if(i==0 || i==BOYUT-1){
						erisilebilirlik[i][0]=2;
						erisilebilirlik[i][BOYUT-1]=2;
						erisilebilirlik[i][1]=3;
						erisilebilirlik[i][BOYUT-2]=3;
						if(erisilebilirlik[i][j]==0) erisilebilirlik[i][j]=4;
					}
						if(i==1  || i==BOYUT-2){
						erisilebilirlik[i][0]=3;
						erisilebilirlik[i][BOYUT-1]=3;
						erisilebilirlik[i][1]=4;
						erisilebilirlik[i][BOYUT-2]=4;
						if(erisilebilirlik[i][j]==0) erisilebilirlik[i][j]=6;
					} else if(i>1 && j<BOYUT-1) {
						erisilebilirlik[i][0]=4;
						erisilebilirlik[i][BOYUT-1]=4;
						erisilebilirlik[i][1]=6;
						erisilebilirlik[i][BOYUT-2]=6;
						if(erisilebilirlik[i][j]==0) erisilebilirlik[i][j]=8;
					}
			}
		}
	printf("Erisilebilirlik Tablosu:\n");
	diziYazdir(erisilebilirlik);
}




