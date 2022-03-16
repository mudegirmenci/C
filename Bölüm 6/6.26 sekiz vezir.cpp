/*

• Her satýrda sadece 1 vezir olabilir 
• Her satýra 1 vezir yerleþtirdikten sonra kalan satýrlarý ve sütunlarý 1 azalt. Çünkü mevcut satir ve sütunlar devre dýþý. 
• Vezir maksimum sekiz yöne gidebilir. 



1. 0-7 arasý rasgele bir sütun numarasý üret  
2. Üretilen sütunun 8 yönünde hiç 8 (vezir)  varmý kontrol et.
3. Eðer varsa 1 e dön. 
4. Yoksa üretilen satir sütun ve çapraz kareleri 1 ile doldur. Üretilen kareye 8 yazdýr  (vezir temsilen )
5. Gidilecek satir numarasini bir azaltarak alt satýra geç 
6. 1 adýmýna git.
7. 8 satir için yukarýdaki iþlemleri yap.
8. Eðer satir numarasi 8 e ulasmazsa ilk satýrdan tekrar Baþla. 
 


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 8

void diziYazdir(const int tahta[][BOYUT]);
int cakismaVarmi (const int tahta[][BOYUT],int bulunanSatir,int bulunanSutun,int boyut);
int vezirYerlestir(int tahta[][BOYUT]);
void tahtaSil(int tahta[][BOYUT]);
static int a=0; 							 //fonksiyonun kaç defa çalýþtýðýný tutmak için geçici deðiþken
int main()
{

	int tahta[BOYUT][BOYUT]={0};
	
	srand(time(NULL));

	while(vezirYerlestir(tahta)==1) ;  //1 çakýþma olduðu anlamýnda. Sonuç 0 dönene kadar döngü devam etsin.
	
}


int cakismaVarmi(const int tahta[][BOYUT],int bulunanSatir,int bulunanSutun,int boyut){
	
	  int i=0;
	  while (++i<boyut) {
	    
	  	if(bulunanSatir-i>=0 && (tahta[bulunanSatir-i][bulunanSutun]==8))  return 0;					 /* Sütunlarda vezir varmý? */
		if(bulunanSatir+i>=0 && (tahta[bulunanSatir+i][bulunanSutun]==8))  return 0;
			
    	if ( bulunanSatir-i>=0 && bulunanSutun+i>=0 && (tahta[bulunanSatir-i][bulunanSutun+i]==8)) return 0;    //çapraz sað-yukarý kontrol
	    if ( bulunanSatir-i>=0 && bulunanSutun-i>=0 && (tahta[bulunanSatir-i][bulunanSutun-i]==8)) return 0;    //çapraz sol-yukarý kontrol
	    if ( bulunanSatir+i>=0 && bulunanSutun+i>=0 && (tahta[bulunanSatir+i][bulunanSutun+i]==8)) return 0;   	//çapraz sað-aþaðý kontrol
	    if ( bulunanSatir+i>=0 && bulunanSutun-i>=0 && (tahta[bulunanSatir+i][bulunanSutun-i]==8)) return 0;    //çapraz sol-aþaðý kontrol
	 }
	return 1;
}

/* Vezirleri yerleþtirir. */
int vezirYerlestir(int tahta[][BOYUT]){
	
	int bulunanSatir,bulunanSutun,cakisma=0,i=0;  
	for(int satir=0;satir<BOYUT;satir++) { 		
	
	 bulunanSatir=satir;  
	 bulunanSutun=rand()%BOYUT;  
		
	while(cakismaVarmi(tahta,bulunanSatir,bulunanSutun,BOYUT)==0 && ++i<30) { //çakýþma olmayana kadar ara fakat sonsuz döngüye girmemek için 
	   bulunanSutun=rand()%BOYUT;
	   if(i==29) {
	   	  cakisma=1;
	      break;
		} 
	}
	
	if(cakisma==0)	 tahta[bulunanSatir][bulunanSutun]=8;  //çakýþma yoksa veziri yerleþtir.
	else {												   //çakýþma varsa, tahtayý yeni denemeler için temizle. 1 dönder. main de kullanýlacak.
		 tahtaSil(tahta);
		  a++;		//fonksiyonun çalýþma sayýsýný tutan geçici deðiþkeni artýr.
	   	  printf("Bu fonksiyonun calisma sayisi:%d\n",a);
		 return 1;	//çözüm bulmada baþarýsýz oldu.
		}
	}
	printf("\n");
	printf("Cozum Bulundu, Vezir yerlesim tablosu:\n");
	diziYazdir(tahta);
	printf("\n");
	return 0;    //çözüm bulundu.
}

void tahtaSil(int tahta[][BOYUT]){
		for(int i=0;i<BOYUT;i++)	
				for(int j=0;j<BOYUT;j++)
					tahta[i][j]={0};
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



