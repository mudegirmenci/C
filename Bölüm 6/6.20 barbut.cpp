#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
	Barbut:	Oyuncu iki zar� ayn� anda atar. Her iki zar�n gelen say�lar� toplan�r.  E�er toplam ilk at��ta 7 veya 11 ise oyuncu kazan�r.
	e�er gelen zar ilk at��ta 2,3 ya da 12 ise oyuncu kaybeder. Buna barbut denir. E�er ilk at��ta 4,5,6,8,9,10 ise bu toplam oyuncunun say�s� haline gelir.
	Kazanmak i�in oyuncu say�s�n� bulana kadar zarlar� atmaya devam eder. Zarlar� atarken kendi say�s� yerine 7 atarsa kaybeder.
*/

int zarAt(void);

int main()
{
	int toplam,kazanmaSayisi=0,kaybetmeSayisi=0,oyunDurumu=0,oyuncuPuani;
	
	srand(time(NULL));
	for(int i=1;i<=1000;i++){
			
		toplam=zarAt();       							//ilk zat at���
		
		if(toplam==7 || toplam==11){ 					//ilk at��ta kazanma.7 veya 11 atarsa oyuncu kazan�r.
		    oyunDurumu=1;
		    kazanmaSayisi++;
		   } 
		if(toplam==2 || toplam==3 || toplam==12){  		 //ilk at��ta kaybetme.2,3 veya 12 atarsa oyuncu kaybeder.
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
