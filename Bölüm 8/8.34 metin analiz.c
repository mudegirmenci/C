/*

a- Birkaç satýrlýk bir metni okuyan ve metinde geçen her harfin kaç defa geçtiđini bulan bir program.
b- Birkaç satýrlýk bir metni okuyan ve metinde iki harften, üç harften, dört harften vb. oluţan kaç kelime oludđunu
bulan bir program yazýn. Sonucu çizelge olarak yazdýrýn.
    Kelime uzunluđu     Kaç kez kullanýldýđý
     2                      0
     3                      5
     4                      4
c-

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void harfHesapla(const char *s);
void kelimedeHarfSayisiHesapla(const char *s);
void bubbleSort(char *dizi[],int indis);

int main()
{
    const char *s="Writers write descriptive paragraphs because their purpose is to describe something. "
                "Their point is that something is beautiful or disgusting or strangely intriguing. "
                "Writers write persuasive and argument paragraphs because their purpose is to persuade or convince someone."
                "Their point is that their reader should see things a particular way and possibly take action on that new way of seeing things. "
                "Writers write paragraphs of comparison because the comparison will make their point clear to their readers.";

    harfHesapla(s);
    kelimedeHarfSayisiHesapla(s);
    herKelimeKacDefa(s);

}

void harfHesapla(const char *s) {


    int count[26]={0};

    for(;*s;s++) {
        if(*s>64 && *s<91)
            count[(*s-65)]++;
        else if(*s>96 && *s<123)
           count[*s-97] ++;
     }

    for(int i=0;i<26;i++)
        printf("%c:%d\n",i+65,count[i]);

    return 0;

}

void kelimedeHarfSayisiHesapla(const char *s)
{
    int kelimeMi=0;  //kelime olduguna dair sinyal
    int kelimedeHarfSayisi=0;
    int kelimeler[50]={0};

    for(;*s;s++) {
        if(isalpha(*s) || *s=="'") {   //bir harf mi?
           kelimedeHarfSayisi++;
        }
        else if(kelimedeHarfSayisi>1) {
            kelimeler[kelimedeHarfSayisi]++;
            kelimedeHarfSayisi=0;
        }
    }
      for(int i=0;i<26;i++)
        printf("%d harfli kelime sayisi:%d\n",i,kelimeler[i]);

    return 0;
}

void herKelimeKacDefa(const char *s)
{
    /* dizi üzerinde işlem yapılacağı için dizinin kopyasını al*/
    char *kopya = strdup(s);
    char *kelimeler[300];  //atomları toplamak icin dizi olustur
    /* boşluklarına göre atomlara ayır */
    char *atom = strtok(kopya," ,.");

    int i,kelimeSayac=0;
    kelimeler[0]=atom;   //ilk atomu kelimeler dizisine ekle
    for(i=0;atom;atom=strtok(NULL," ,."),i++) //islem apilacak dizideki kelimeleri al
       kelimeler[i]=atom;
    kelimeler[i] ='\0';  //kelimeler dizisinin sonunu belirle

    printf("\n");
    bubbleSort(kelimeler,i+1);  //diziyi sirala, dizi indesi i+1

    for(int i=0;kelimeler[i];i++) {      //kelimeleri say ve yaz
       for(int j=1;kelimeler[j];j++) {
          if(strcmp(kelimeler[i],kelimeler[j])==0)  //iki kelime esitse k sayacini artir
            kelimeSayac++;
       }
       printf("%s kelime sayisi:%d\n",kelimeler[i],kelimeSayac);  //kelime sayisini yaz
       if(kelimeler[i+kelimeSayac]) i+=kelimeSayac;    //siralanmis dizide islem yaptigimiz icin her defasinda ayni eleman olmasin diye dizi sonu degilse diziyi ileri kaydir.
       else break;                  //dizide eleman kalmadiysa donguyu bitir.
       kelimeSayac=0;                         //kelime sayaci sifirla
    }
    /* NOT: Buyuk hatfler ASCII den ilk geldikleri icin siralamada ilk geliyorlar */
}


void bubbleSort(char *dizi[],int indis)
{


  int kontrol=0,k;
  char *temp;


	for(int tur=1;*dizi;tur++,kontrol=0) {		 //tur sayýsý
	   for(int i=0;i<indis-(tur+1);i++){
			k = strcmp(dizi[i],dizi[i+1]);

			if(k>0){
				temp=dizi[i];
				dizi[i]=dizi[i+1];
				dizi[i+1]=temp;
				kontrol=1;
			}
        }
   if(kontrol==0) break;  //herhangi bir yer deđiţikliđi yapýlmamýţsa, dizi sýralýdýr. Bu durumda döngüye devam etmeye gerek yok.

   }



}
