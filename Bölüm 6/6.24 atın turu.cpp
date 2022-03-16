/*

Atýn Turu: At, satranç tahtasýndaki bütün kareleri, yani 64 kareyi birden her kareye sadece ama sadece bir kez uðrayarak gezebilir mi?

KURALLAR AÇIKLAMALAR:

-Al L þeklinde hareket eder.
-Satranç Tahtasý:tahta[8][8]
-Hamleler yani yatay ve dikey hareketler tek belirteçli yatay ve dikey dizileriyle temsil edilecek.
-Eðer at ortalarda bir yerdeyse maksimum hamle sayýsý 8 olacaktýr. Bu nedenle dikey[8] ve yatay[8] dizileri 8 olacak. 
 Hamle yapmak 0-7 arasýnda deðer alan hamle deðiþkeni ile ayarlanýr.
-Sola yatay hamleler ve yukarý dikey hamleler negatif sayýlarla gösterilsin.
-Örneðin yatay[2] =2 ve dikey [2]=-1 ise bunun anlamý yatay saða 2 birim, dikey yukarý 1 birim hareket edilmiþ.
-bulunanSatir ve bulunanSutun o anda atýn hangi satýr ve sütunda olduðunu gösterir.
	bulunanSatir+=dikey[hamle];
	bulunanSutun+=yatay[hamle];
-At her kareden bir defa geçeceði için toplam 64 kare gezinecek. sayac=64 deðiþkeni bu sayýyý tutacak. Programýmýz while(sayac>0) olduðu sürece çalýþacak.
 her kare hareketi için sayaç deðiþkeni 1 düþecek.
-Oyun baþlangýç noktasý rasgele bir yer olabilir.
-Her hamlede gidilen satýra 1-64 arasý sýra numarasý atanacak. ilk hamle üç kare deðiþtirir o halde karelere sýrayla ,2,3  girilsin.
-Eðer karedeki deðer 0 dan farklýysa hamle yapýlabilir.
	
Pseudo Code:

	1. Deðiþkenleri tanýmla, 8x8 karenin tamamýný 0 olarak ayarla.
	2- At rasgele bir kareden oyuna baþlar.
	3. While 1-63 arasý sayac sayar. toplam döngümüz sadece 63 tane(atýn rasgele ilk yerleþiminde karenin biri dolmuþtu.)
	4- Olasý 8 hamleden birini rasgele seçer.
	5- Seçilen hamle uygun mu kontrol edilir.
		-Eðer tahta sýnýrlarýna denk geliyorsa uygun deðil, rasgele yeni bir hamle seç.
			-tahta sýnýrlarýný bulunanSatir ve bulunanSutun deðiþkenleri ile kontrol et. Eðer potansiyel hamle sonucu bubulunaSatir veya bulunulanSutun deðerleri 0 dan 
			küçük veya 7 den büyükse hamle geçersiz.
		-Eðer seçilen hamle atýn daha önce geldiði karelerden birine denk geliyorsa baþka bir hamle seç.
		    -Eðer potansiyel hamlenin olduðu kare(tahta[bulunanSatir+i gibi ][bulunanSutun]) 0 dan farklý ise hamle geçersiz.
		

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define BOYUT 8
void diziYazdir(const int tahta[][BOYUT]);

int main()
{

	int tahta[BOYUT][BOYUT]={0},bulunanSatir=0,bulunanSutun=0,sayac=64,hamle=0,HamleSayisi=1 ;						//hamle 8 olasý hamle için deðiþken. HamleSayisi hamle yapýlan karelere 1,2,3... yazacak.
	int yatay[]={2,1,-1,-2,-2,-1,1,2},dikey[]={-1,-2,-2,-1,1,2,2,1}; 												//yatay pozitif sað yön,yatay negatif sol yön:dikey pozitif aþaðý yön, dikey negatif yukarý yön
diziYazdir(tahta);
	srand(time(NULL));
	bulunanSatir=rand()%BOYUT;
	bulunanSutun=rand()%BOYUT;
	tahta[bulunanSatir][bulunanSutun]=1; 																			/* At tahtada rasgele bir kareden oyuna baþlýyor.   */
	printf("Baslangic Satir:%d Baslangic Sutun %d \n",bulunanSatir,bulunanSutun);
	
		
	while(sayac>0) { 																									
	
		hamle=0;
	
		while(hamle<=7){ 																								// 8 olasý hamleyi tek tek dene. If bloguna girip hamle çalýþýrsa içteki while döngüsünden break ile çýk.Bu þekilde toplam hamle sayýsý 64 olacak 
			
			if(bulunanSatir+dikey[hamle]>=0 && bulunanSatir+dikey[hamle]<=7 && bulunanSutun+yatay[hamle]>=0 &&			//sýnýr aþýldý mý veya kareden daha önce geçildi mi? (fonksiyon olarak yap)			
			 bulunanSutun+yatay[hamle]<=7 && tahta[bulunanSatir+dikey[hamle]][bulunanSutun+yatay[hamle]]==0)	 {
			 	 HamleSayisi++;
			     bulunanSatir+=dikey[hamle];
				 bulunanSutun+=yatay[hamle];
				 tahta[bulunanSatir][bulunanSutun]=HamleSayisi;	
				 break;
				
		    }
		    hamle++;														    		  								//  printf("Sayac %d icin Hamle No:%d  ve HamleSayisi:%d\n",sayac,hamle,HamleSayisi);
		 }
		 
	   if(hamle==8){																									//Hamle yapacak yer kalmadý döngüyü bitir.
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

