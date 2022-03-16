/*
iki yana yasla.

1. Metindeki karakterleri say
2. Metindeki karakterleri 65 e böl ve bulunan sonucu satirSayisi deðiþkenine ata.
3. kopya isminde bir dizi oluþturup, ilk 10 karakterini boþluk olarak ata.
4. kopya stringin 11. karakterinden itibaren 65 karakter olana kadar, orjinal stringten kopyala.
5. Eðer 65. karakter boþluða denk geliyorsa \n ile deðiþtir. Yoksa, son karakterden geriye doðru ilk
   boþluk karakterine denk gelene kadar sayarak gel. Kaç karakter gelindiði satýra daðýtýlacak boþluk sayýsý olacak.
   Satýrdaki boþluklarý yeni boþluklarla artýr.
6. ikinci satýra geç

Birkaç satýrlýk metin okuyan ve bu metni yazýya dayalý biçimde yazdýran bir program yazýn.
Metnin 8 1/2 inç geniþliðinde kaðýda yazdýrýlacaðýný ve yazdýrýlan sayfanýn hem sol hem de
sað taraflarýnda bir inçlik kenar boþluklarýna izin verileceðini varsayýn. Bilgisayarýn yatay
inç'e 10 karakter yazdýrdýðýný varsayýn. . Bu nedenle, programýnýz 6 1/2 inç metin veya satýr
baþýna 65 karakter yazdýrmalýdýr.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SATIRUZUNLUGU 25
#define GIRINTI 5

void justify(char *s,int ,int);

int main(int argc, char **argv)
{
	char *metin ="Have you noticed that the conditions we've used so far have been very simple, "
	"not to say, quite primitive? The conditions we use in real life are much more complex. Let's look at this sentence:"
    "If we have some free time, and the weather is good, we will go for a walk."
    "We've used the conjunction and, which means that going for a walk depends on the simultaneous"
    "fulfilment of these two conditions. In the language of logic, such a connection of conditions is called a conjunction. And now another example:"
    "If you are in the mall or I am in the mall, one of us will buy a gift for Mom."
    "The appearance of the word or means that the purchase depends on at least one of these conditions. In logic, such a compound is called a disjunction."
    "It's clear that Python must have operators to build conjunctions and disjunctions. Without them, the expressive power of the language would be substantially weakened. They're called logical operators.";

      justify(metin,SATIRUZUNLUGU,GIRINTI);
}

void justify(char *s,int satirUzunlugu,int girinti) {

   int satirBoslukSayisi=0,eksikBoslukSayisi=0,sayac=1,kalanKarakter=0,satirSayisi=0,satirBasiMi=1;
   int i,boslukBasinaEkBosluk=0,artikBosluk;

   printf("%*c",girinti,'\n');  //yukarýdan girinti býrak

	/* s stringi sonuna gelinmediği sürece ilerle */
	for(sayac=1;*s;s++,sayac++) {                  //s string sonuna kadar git
      kalanKarakter++;                            //satirUzunlugundan küçük son kalan karakterleri tutacak deðiþken

		if(isspace(*s) && satirBasiMi) {                  //Satır başıysa ve satır başında boşluklar varsa temizle
		   while(isspace(*s)) s++;
		} else if(isspace(*s)) satirBoslukSayisi++;	   //satır başı değilse boşlukları say
        satirBasiMi=0;				                   //satır başını düzelt

		/* Satır sonuysa */
		if(sayac % satirUzunlugu == 0)
		{
			printf("%*c",girinti,' ');                     /* satır başı girintilerini ayarla */

			/* Satır sonu boşluk değilde bir harfe denk gelirse,
			kelimeyi kesmeden geriye doğru boşlukları sayarak gel. */
			if(!isspace(*(s+1)))
			{
				if(isspace(*s)) {
					while(isspace(*s)) { eksikBoslukSayisi++; s--; }   //boşluk olmayana kadar geri git
				 } else {
					while(!isspace(*s)) { eksikBoslukSayisi++; s--; }	//boşluk bulana kadar geri git
				 eksikBoslukSayisi++;
				 s--;
				 }
				satirBoslukSayisi--;                      //fazladan sayılan boşlukları düzelt
			}

			s-=satirUzunlugu-eksikBoslukSayisi-1;

		/* boþluklarý orantýlý daðýtmak için her boþluða, daðýtýlacak boþluk sayýsýný hesapla */
         if(satirBoslukSayisi!=0 && eksikBoslukSayisi>0) boslukBasinaEkBosluk=(eksikBoslukSayisi/satirBoslukSayisi)==0 ? 1: eksikBoslukSayisi/satirBoslukSayisi;
          artikBosluk=eksikBoslukSayisi>satirBoslukSayisi ? eksikBoslukSayisi % satirBoslukSayisi : 0;

		  for(i=0;i<satirUzunlugu;i++,s++) {
              if(satirBoslukSayisi==0) break;               //tek kelime ve hiç boþluk yoksa, sonraki kelimeden yemesin diye döngüden çýk.
              printf("%c",*s);

              if(isspace(*s) && eksikBoslukSayisi>0) {          //boþlukla karþýlaþýnca.
                  printf("%*c",boslukBasinaEkBosluk,' ');       //boslukBasinaEkBosluk sayýsý kadar bosluk eke
                  eksikBoslukSayisi-=boslukBasinaEkBosluk;      //Eksik boþluk sayýsýný düzelt
                  i+=boslukBasinaEkBosluk;                      //sayacý düzelt

                  if(artikBosluk>0) {                           //artý boþluk varsa onlarý da ekle
                    printf("%*c",artikBosluk,' ');
                    eksikBoslukSayisi-=artikBosluk;
                    i+=artikBosluk;
                    artikBosluk=0;
                 }
              }
           }

           /* satır sonu işlemleri */
		   s--;
		   printf("%*c",girinti,' '); //satýr sonu girinti ayarlar
           printf("\n");                //yaslanmýþ satýr sonu
           satirBoslukSayisi=0;  //yeni satýr için sýfýrla
           eksikBoslukSayisi=0;
           kalanKarakter=0;
           satirBasiMi=1;
           satirSayisi++;

		} //end of main if
  	} //end of main while

/* son kalan karakterleri ve girintileri bas */
  printf("%*c",girinti,' ');
  s++;
  printf("%s",s-kalanKarakter-1);
  printf("\n");

} //end of justify



void justify1(char *s,int satirUzunlugu,int girinti) {

   int satirBoslukSayisi=0,eksikBoslukSayisi=0,sayac,kalanKarakter=0,satirSayisi=0,satirBasiBosluk,satirBasiMi=1;

  printf("%*c",girinti,'\n');  //yukarýdan girinti býrak


  /* bu döngü her bir satýr için çalýþýr */
   for(sayac=1;*s;s++,sayac++) {                  //s string sonuna kadar git
      kalanKarakter++;                            //satirUzunlugundan küçük son kalan karakterleri tutacak deðiþken

      if(isspace(*s) && satirBasiMi==1) {        //Eðer satýr baþýysa ve satýr baþýnda boþluklar varsa
         while(isspace(*s))                      //boþluk olmayana kadar
           s++;                                  //boþluklarý yok saymak için stringte ilerle
      }  satirBasiMi=0;

      if(isspace(*s) && satirBasiMi==0)      //Eðer satýr baþý deðilse kaç boþluk var?
         satirBoslukSayisi++;

       /* birinci satýr sonuna geldiyse */
      if(sayac % satirUzunlugu==0)
      {
        /* satır başı girintilerini ayarla */
         printf("%*c",girinti,' ');

        /* satýr sonu boþluk deðilde bir harfe denk gelirse, kelimeyi kesmeden geriye doðru ilk boþluðu bul */
         if(!isspace(*(s+1))) {   //son karakterden sonra boşluk yoksa(varsa satır sonu demektir zaten)

              if(isspace(*s)) {   //son karakter boşluksa geriye doğru boşlukları sayıp ilk boşluk olmayan karaktere kadar git
                 while(isspace(*s))
                    { eksikBoslukSayisi++; s--; }
               } else {
                  while(!isspace(*s)) {                       //son karakter bosluk deðilse. Boþluktan önceki karakterle satýr bitsin.
                     eksikBoslukSayisi++;                        //mevcut satýrda ihtiyaç olan boþluk sayýsýný hesapla
                     s--;                                       //stringde boþluk bulana kadar geri git.
                  }
                  eksikBoslukSayisi++;
                  s--;
               }
               satirBoslukSayisi--;   //eðer harfe denk geldiyse bir boþluk fazladan olacak. onu düzelt
         }
//if(sayac==75) { printf(" %c ",s[0]); break; }

         /* satýr baþý boþluðu 55. satýrda düzeltiliyor fakat ilk satýr için eðer son karakterden geri gelinirse bir boþluk oluþýyor.
         Bu boþluk sonraki bütün satýrlarý etkiliyor. O nedenle ilk satýr sonundaki(ki aslýnda sonraki satýrýn satýr baþý) boþluk için
         ilk satýra fazladan bir boþluk ekliyoruz. */

            s-=satirUzunlugu-eksikBoslukSayisi-1;            //satýr baþýna gel

         /* satýr baþýndan itibaren boþluklarý ara ve yerleþtir */
         int i,boslukBasinaEkBosluk=0,artikBosluk;
         /* boþluklarý orantýlý daðýtmak için her boþluða, daðýtýlacak boþluk sayýsýný hesapla */
         if(satirBoslukSayisi!=0 && eksikBoslukSayisi>0) boslukBasinaEkBosluk=(eksikBoslukSayisi/satirBoslukSayisi)==0 ? 1: eksikBoslukSayisi/satirBoslukSayisi;
            artikBosluk=eksikBoslukSayisi>satirBoslukSayisi ? eksikBoslukSayisi % satirBoslukSayisi : 0;

 //printf("    %d %d %d %d %c %c  ",eksikBoslukSayisi,satirBoslukSayisi,boslukBasinaEkBosluk,satirUzunlugu-eksikBoslukSayisi-1,*(s),s[satirUzunlugu-eksikBoslukSayisi-1]);

           for(i=0;i<satirUzunlugu;i++,s++) {
              if(satirBoslukSayisi==0) break;               //tek kelime ve hiç boþluk yoksa, sonraki kelimeden yemesin diye döngüden çýk.
              printf("%c",*s);

              if(isspace(*s) && eksikBoslukSayisi>0) {          //boþlukla karþýlaþýnca.
                  printf("%*c",boslukBasinaEkBosluk,' ');       //boslukBasinaEkBosluk sayýsý kadar bosluk eke
                  eksikBoslukSayisi-=boslukBasinaEkBosluk;      //Eksik boþluk sayýsýný düzelt
                  i+=boslukBasinaEkBosluk;                      //sayacý düzelt

                  if(artikBosluk>0) {                           //artý boþluk varsa onlarý da ekle
                    printf("%*c",artikBosluk,' ');
                    eksikBoslukSayisi-=artikBosluk;
                    i+=artikBosluk;
                    artikBosluk=0;
                 }
              }
           }

          s--;
//{ printf("  %c ",s[0]);  }


           printf("%*c",girinti,' '); //satýr sonu girinti ayarlar
           printf("\n");                //yaslanmýþ satýr sonu
           satirBoslukSayisi=0;  //yeni satýr için sýfýrla
           eksikBoslukSayisi=0;
           kalanKarakter=0;
           satirBasiMi=1;
           satirSayisi++;

         }  //end of if

   }  //end of for
  /* son kalan karakterleri bas */

  printf("%*c",girinti,' ');
  s++;
  printf("%s",s-kalanKarakter-1);
  printf("\n");

}


