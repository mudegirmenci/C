#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
	Barbut:	Oyuncu iki zarý ayný anda atar. Her iki zarýn gelen sayýlarý toplanýr.  Eðer toplam ilk atýþta 7 veya 11 ise oyuncu kazanýr.
	eðer gelen zar ilk atýþta 2,3 ya da 12 ise oyuncu kaybeder. Buna barbut denir. Eðer ilk atýþta 4,5,6,8,9,10 ise bu toplam oyuncunun sayýsý haline gelir.
	Kazanmak için oyuncu sayýsýný bulana kadar zarlarý atmaya devam eder. Zarlarý atarken kendi sayýsý yerine 7 atarsa kaybeder.
*/

int zarAt(void);

int main()
{
	int toplam,kazanmaSayisi=0,kaybetmeSayisi=0,oyunDurumu=0,oyuncuPuani;
	
	srand(time(NULL));
	for(int i=1;i<=1000;i++){
			
		toplam=zarAt();       							//ilk zat atýþý
		
		if(toplam==7 || toplam==11){ 					//ilk atýþta kazanma.7 veya 11 atarsa oyuncu kazanýr.
		    oyunDurumu=1;
		    kazanmaSayisi++;
		   } 
		if(toplam==2 || toplam==3 || toplam==12){  		 //ilk atýþta kaybetme.2,3 veya 12 atarsa oyuncu kaybeder.
		     oyunDurumu=2;
		     kaybetmeSayisi++;
		} 
		oyuncuPuani=toplam;
			
		while(oyunDurumu==0){  //zar atmaya devam et
	    	toplam=zarAt();
	    	if(toplam==oyuncuPuani)	 {
	    		kazanmaSayisi++;
	    		oyunDurumu=1;
			} 
	    	else if(toplam==7) oyunDurumu=2;  //7 atma kaybettirir.
	    }
	    
	  //  if(oyunDurumu==1) printf("Oyuncu Kazanir\n");
	  //  else printf("Oyuncu Kaybeder\n");
	    
	    oyunDurumu=0;
	   
	}
	 printf("Kazanma Sayisi:%d, Kaybetme Sayisi:%d\n",kazanmaSayisi,kaybetmeSayisi);
	return 0;
}
int zarAt(void) {
	int toplam,zar1,zar2;
	zar1=1+rand()%6;
	zar2=1+rand()%6;
	toplam=zar1,zar2;
//	printf("Oyuncu %d + %d = %d atti:\n",zar1,zar2,toplam);
	return toplam;
}
