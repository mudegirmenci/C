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
-Eriþilebilirlik, ilgili kareye kaç kareden eriþilebileceðini gösterir.Eriþilebilirliði düþük olan karelere öncelikli hamle yaparýz.
	
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
void erisilebilirlikAyarla(int erisilebilirlik[][BOYUT]);


int main()
{

	int tahta[BOYUT][BOYUT]={0},bulunanSatir=0,bulunanSutun=0,sayac=64,hamle=0,HamleSayisi=1,enUygunHamle=-1;			//hamle 8 olasý hamle için deðiþken. HamleSayisi hamle yapýlan karelere 1,2,3... yazacak.
	int yatay[]={2,1,-1,-2,-2,-1,1,2},dikey[]={-1,-2,-2,-1,1,2,2,1};													//yatay sað pozitif,yatay sol negatif :dikey aþaðý yön pozitif,  dikey negatif yukarý yön			 
	int erisilebilirlik[BOYUT][BOYUT]={0};

	erisilebilirlikAyarla(erisilebilirlik);    //eriþilebilirlik tablosunu ayarlar. 
	
	/* At tahtada rasgele bir kareden oyuna baþlýyor.   */
	srand(time(NULL));
	bulunanSatir=rand()%BOYUT;  //6
	bulunanSutun=rand()%BOYUT;  //0 degerlerinde at tam tur yapiyor.
	tahta[bulunanSatir][bulunanSutun]=1; //Baþladýðýmýz kareyi oradan geçildi olarak iþaretliyoruz.
														
	printf("Baslangic Satir:%d Baslangic Sutun %d \n",bulunanSatir,bulunanSutun);
	
		
	while(--sayac>0) { 		//Toplam 64 hamle yapmak istiyoruz.																							
	
		for(int hamle=0;hamle<=7;hamle++){ 																				// 8 olasý hamleyi tek tek dene. If bloguna girip hamle çalýþýrsa içteki while döngüsünden break ile çýk.Bu þekilde toplam hamle sayýsý 64 olacak 
			
			if(bulunanSatir+dikey[hamle]>=0 && bulunanSatir+dikey[hamle]<=7 && bulunanSutun+yatay[hamle]>=0 &&			//sýnýr aþýldý mý veya kareden daha önce geçildi mi? (fonksiyon olarak yap)			
			 bulunanSutun+yatay[hamle]<=7 && tahta[bulunanSatir+dikey[hamle]][bulunanSutun+yatay[hamle]]==0)	 {
			 			 	
				if (enUygunHamle==-1)  //ilk deðer ayarla
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
istenilen boyutlarda tahta çizmek için. Yoksa elle de dizi deðeri atanabilirdi. Veya bu diziyi oluþturmanýn belki daha kolay yolu vardýr.
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




