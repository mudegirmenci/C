/*

� Her sat�rda sadece 1 vezir olabilir 
� Her sat�ra 1 vezir yerle�tirdikten sonra kalan sat�rlar� ve s�tunlar� 1 azalt. ��nk� mevcut satir ve s�tunlar devre d���. 
� Vezir maksimum sekiz y�ne gidebilir. 



1. 0-7 aras� rasgele bir s�tun numaras� �ret  
2. �retilen s�tunun 8 y�n�nde hi� 8 (vezir)  varm� kontrol et.
3. E�er varsa 1 e d�n. 
4. Yoksa �retilen satir s�tun ve �apraz kareleri 1 ile doldur. �retilen kareye 8 yazd�r  (vezir temsilen )
5. Gidilecek satir numarasini bir azaltarak alt sat�ra ge� 
6. 1 ad�m�na git.
7. 8 satir i�in yukar�daki i�lemleri yap.
8. E�er satir numarasi 8 e ulasmazsa ilk sat�rdan tekrar Ba�la. 
 


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 8

void diziYazdir(const int tahta[][BOYUT]);
int cakismaVarmi (const int tahta[][BOYUT],int bulunanSatir,int bulunanSutun,int boyut);
int vezirYerlestir(int tahta[][BOYUT]);
void tahtaSil(int tahta[][BOYUT]);
static int a=0; 							 //fonksiyonun ka� defa �al��t���n� tutmak i�in ge�ici de�i�ken
int main()
{

	int tahta[BOYUT][BOYUT]={0};
	
	srand(time(NULL));

	while(vezirYerlestir(tahta)==1) ;  //1 �ak��ma oldu�u anlam�nda. Sonu� 0 d�nene kadar d�ng� devam etsin.
	
}


int cakismaVarmi(const int tahta[][BOYUT],int bulunanSatir,int bulunanSutun,int boyut){
	
	  int i=0;
	  while (++i<boyut) {
	    
	  	if(bulunanSatir-i>=0 && (tahta[bulunanSatir-i][bulunanSutun]==8))  return 0;					 /* S�tunlarda vezir varm�? */
		if(bulunanSatir+i>=0 && (tahta[bulunanSatir+i][bulunanSutun]==8))  return 0;
			
    	if ( bulunanSatir-i>=0 && bulunanSutun+i>=0 && (tahta[bulunanSatir-i][bulunanSutun+i]==8)) return 0;    //�apraz sa�-yukar� kontrol
	    if ( bulunanSatir-i>=0 && bulunanSutun-i>=0 && (tahta[bulunanSatir-i][bulunanSutun-i]==8)) return 0;    //�apraz sol-yukar� kontrol
	    if ( bulunanSatir+i>=0 && bulunanSutun+i>=0 && (tahta[bulunanSatir+i][bulunanSutun+i]==8)) return 0;   	//�apraz sa�-a�a�� kontrol
	    if ( bulunanSatir+i>=0 && bulunanSutun-i>=0 && (tahta[bulunanSatir+i][bulunanSutun-i]==8)) return 0;    //�apraz sol-a�a�� kontrol
	 }
	return 1;
}

/* Vezirleri yerle�tirir. */
int vezirYerlestir(int tahta[][BOYUT]){
	
	int bulunanSatir,bulunanSutun,cakisma=0,i=0;  
	for(int satir=0;satir<BOYUT;satir++) { 		
	
	 bulunanSatir=satir;  
	 bulunanSutun=rand()%BOYUT;  
		
	while(cakismaVarmi(tahta,bulunanSatir,bulunanSutun,BOYUT)==0 && ++i<30) { //�ak��ma olmayana kadar ara fakat sonsuz d�ng�ye girmemek i�in 
	   bulunanSutun=rand()%BOYUT;
	   if(i==29) {
	   	  cakisma=1;
	      break;
		} 
	}
	
	if(cakisma==0)	 tahta[bulunanSatir][bulunanSutun]=8;  //�ak��ma yoksa veziri yerle�tir.
	else {												   //�ak��ma varsa, tahtay� yeni denemeler i�in temizle. 1 d�nder. main de kullan�lacak.
		 tahtaSil(tahta);
		  a++;		//fonksiyonun �al��ma say�s�n� tutan ge�ici de�i�keni art�r.
	   	  printf("Bu fonksiyonun calisma sayisi:%d\n",a);
		 return 1;	//��z�m bulmada ba�ar�s�z oldu.
		}
	}
	printf("\n");
	printf("Cozum Bulundu, Vezir yerlesim tablosu:\n");
	diziYazdir(tahta);
	printf("\n");
	return 0;    //��z�m bulundu.
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



