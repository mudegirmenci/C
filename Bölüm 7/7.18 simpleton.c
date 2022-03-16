/*
    Simpletron (SMD) bir bilgisayar simülatörüdür.Makina dilini simüle eder. Sadece kendi anlayacağı
    dilde yazılan programları çalıştırabilmektedir.
    -Simpletron bir akümülatör(SMD hesaplamalarda kullanacağı bilgiyi buraya koyar) içermektedir.
    -SMD, word ile işlenir. Bir word onluk sistemde dört basamaklı bir sayıdır. +3364,-6359,+0007 vb.
    -SMD 100 word kapasiteli bir hafızaya sahiptir ve tüm wordler konum numarasıyla ifade edilirler: 00,01..99.
    -Bir SMD programı çalıştırılmadan önce hafızaya yüklenmelidir. İlk komut ya da ifade 00 konumundan başlar.
    -SMD de yazılan her komut hafızada bir word yer tutar.
    -SMD hafızasındaki her word; bir komut, program tarafından kullanılacak bir veri veya
    kullanılmamış(tanımlanmamış) bir hafıza alanını içerebilir.
    -SMD komutunun ilk iki basamağı hangi işlemin yapılacağını gösterir. Örneğin 1007 --> oku ve hafızada 07 konumuna yaz.
    -SMD komutunun son iki basamağı ise işlenecek bilginin hafıza konumunu gösterir.

    7.18 a 10 sayının toplamı(nöbetci sayıcı ile)

    1.    00  +1009 A OKU ve girilen değeri 09 hafıza konumuna yaz.
    2.    01  +2009 A YUKLE: 09 hafıza konumundaki A değerini akümülatöre yükle
    3.    02  +4107 Negatifse sonuç yaz(07 konumuna git)
    4.    03  +2010 C YUKLE
    5.    04  +3009 Toplama A ekle
    6.    05  +2110 Toplamı C de SAKLA
    7.    06  +4000 00 konumuna git, tekrar yeni değer al.
    8.    07  +1110 Sonuç(C) YAZ
    9.    08  +4300 BITIR
    10.   09  +0000 A
    11.   10  +0000 C

    7.18 b 7 sayı alıp ortalamasnı yazan program

    1- Hafızanın 00 konumuna ortalama için 7 yaz, 01 ve 02 konumlarına da sayaç
       için sırasıyla 7 ve 1 yaz. Bunun için program komutu 7,7,1 yazmak yeterli.
    2- 01 konumdaki değeri YUKLE ve  02 konumdaki değeri çıkar ve sonucu 01 konumunda SAKLA
    3- 01 konumundaki değer negatif ise 7. adıma git.
    4- Terminalden bir sayı OKU ve akümülatöre YUKLE
    5- xx konumundaki C ile TOPLA (C ilk değer 0) ve sonucu xx konumunda SAKLA
    6- 2. adıma git (DALLAN: 40 ile)
    7- C'yi akümülatöre YUKLE ve hafıza 00 konumundaki değere BOL
    8- Sonucu yazdır.
    9- BITIR.


    00   7	     Bölüm işlemi için 7 ata
    01   7       Sayaç için 7 ata
    02   1       Sayaç için 1 ata
    03   +2001   01 konumdaki 7 yi YUKLE
    04   +3102   01-02 (7-1) CIKAR
    05   +2101   Hafıza 01 şimdi 6 oldu.Bunu 01 de SAKLA
    06   +2001   01 konumdaki yeni değeri akümülatöre YUKLE
    07   +4113   01 konumdaki değer negatif ise 13 konumuna DALLAN
    08   +1018   terminalden bir değer OKU ve 18 konumuna yaz
    09   +2018   terminalden okunan değeri akümülatöre YUKLE
    10   +3019   18 konumundaki C ile TOPLA
    11   +2119   sonucu 19 konumundaki C de SAKLA
    12   +4003   03 hafıza konumuna DALLAN
    13   +2019   C yi akümülatöre YUKLE
    14   +3200   C yi 00 konumdaki değere BOL
    15   +2119   Bölüm değerini C yerine SAKLA
    16   +1119   C yi(artık ortalama olan sonuç) YAZ
    17   +4300   BITIR
    18   +0000   A
    19   +0000   C

    7.18 c  - Birkaç sayı okuyup en büyüğüne karar verir. İlk sayı kaç sayı okunacağıdır.

    1.  Terminalden bir sayı OKU ve SAYAC konumuna yaz. Bu değer kaç sayı okunacağı bilgisidir.
    2.  01 hafıza konumuna sayaç olarak kullanılacak ikinci değer olan 1 yaz.
    3.  SAYAC konumundaki sayıdan 01 konumundaki sayacı ÇIKAR ve bunu SAYAC konumuna SAKLA
    4.  SAYAC değerini akümülatöre yükle.Eğer değer negatif ise 12. adıma DALLAN
    5.  Terminalden bir sayı OKU ve A konumuna yaz.
    6.  A yı akümülatöre YUKLE
    7.  A dan B yi CIKAR
    8.  Akümülatör negatif ise B büyük olan sayıdır. 10. adıma DALLAN
    9.  A nın büyük sayı olduğunu farzet ve sonuçların tutulacağı B ye A değerini SAKLA
    10. B büyük değer ise B ye B değerini SAKLA (B konumu büyük sayıyı saklar)
    11. 3. adıma DALLAN
    12. B yi YAZ
    13. BITIR.


    00  +1018  	Kaç sayı okunacağını tutan sayaç
    01  1	   	Sayaç için kullanılacak ikinci sayımız.
    02  +2018       SAYAC değişkenini akümülatöre YUKLE
    03  +3101	SAYAC - 01 konum değeri CIKAR
    04  +4116	SAYAC negatifse sonuc yazma adımına DALLAN
    05  +2118	SAYAC-1 sonucunu SAKLA
    06  +1019	Terminalden bir sayı oku ve A konumuna yaz.
    07  +2019	A akümülatöre YUKLE
    08  +3120	A dan B CIKAR
    09  +4113	Akümülatör negatif ise B büyük sayıdır. B yi B konumuna yazacak yere DALLAN
    10  +2019	A akümülatöre YUKLE
    11  +2120	A yı B ye SAKLA (Büyük olan A dır)
    12  +4014	Sonraki aşamaya DALLAN. A nın üzerine B yazmasın
    13  +2020	B akümülatöre YUKLE
    14  +2120	B yi B konumuna SAKLA(Büyük olan B dir)
    15  +4002	02 konumuna DALLAN
    16  +1120	B yi YAZ
    17  +4300	BITIR
    18  +0000	SAYAC
    19  +0000	A
    20  +0000   B
*/



#include<stdio.h>

#define OKU 10          //Terminalden 1 word bilgi oku ve hafızadaki belli bir konuma yaz
#define YAZ 11          //Hafızadan belli bir konumdaki bilgiyi terminalde yaz.
#define YUKLE 20        //Akümülatorü belli bir hafıza konumundan alınan bir word bilgi ile yükle
#define SAKLA 21        //Akümülatörden bir word bilgi al ve hafızanın belli bir konumunda sakla.
#define TOPLA 30        //Akümülatördeki bir word bilgi ile belli bir hafıza konumundaki bir word bilgiyi topla(sonucu akümülatörde sakla)
#define CIKAR 31        //Akümülatördeki bir word bilgi ile belli bir hafıza konumundaki bir word bilgiyi çıkar(sonucu akümülatörde sakla)
#define BOL   32        //Akümülatördeki bir word bilgi ile belli bir hafıza konumundaki bir word bilgiye böl(sonucu akümülatörde sakla)
#define CARP  33        //Akümülatördeki bir word bilgi ile belli bir hafıza konumundaki bir word bilgiyle çarp(sonucu akümülatörde sakla)
#define DALLAN 40       //Hafızadaki belli bir konuma dallan.(if yapıları gibi)
#define DALLANNEG 41    //Akümülatör negatif ise hafızadaki belli bir konuma dallan.
#define DALLANSIFIR  42 //Akümülatör sıfır ise hafızadaki belli bir konuma dallan.
#define BITIR  43       //Program görevini tamamladı.

#define COMMANDCOUNT 25
#define MEMSIZE 100

void komutIsle(int komut,int hafiza[],int *aPtr);

int main(void) {

    int hafiza[100]={0},i=0;  //Simpleton 100 word kapasiteli hafızası.
    int komut=0,akumulator=0;  //akumulator sadece 1 word bilgi tutar. SMD hesaplama yaparken buradaki bilgiyi kullanır.

        int program[COMMANDCOUNT]={

            /* Birkaç sayı okuyup en büyüğüne karar verir. İlk sayı kaç sayı okunacağıdır.  */
            +1018,1,+2018,+3101,+4116,+2118,
            +1019,+2019,+3120,+4113,+2019,
            +2120,+4014,+2020,+2120,+4002,+1120,
            +4300,+0000,+0000,+0000


            /* Sayıcı kontrollü pozitif veya negatif 7 sayı al, ortalamasını yazdır
           7,7,1,+2001,+3102,
           +2101,+2001,+4113,+1018,+2018,
           +3019,+2119,+4003,+2019,+3200,
           +2119,+1119,+4300,+0000,+0000
            */

            /* Nöbetçi kontrollü bir dizi ile 10 sayı al toplamını yaz.
           +1009,+2009,+4107,+2010,
           +3009,+2110,+4000,+1110,
           +4300,+0000,+0000
            */

          /* Calculate the sum of 2 numbers
           +1009, +1010, +2009, +3110,
           +4107, +1109, +4300, +1110,
           +4300, +0000, +0000
         */
      };


    /* programı SMD memory'e yükle */
    for(int i=0;i<COMMANDCOUNT;i++) {
        hafiza[i] = program[i];
    }

    for(int i=0;i<MEMSIZE;i++) {

        int emir=hafiza[i]/100;                 //4 basamaklı sayının ilk iki basamağını al.
        int hafizaKonum=hafiza[i]%100;          //son iki basamak hangi hafıza konumunda işlem yapılacağı


        switch(emir) {
        case 10:                             //terminalden bilgi oku.
            printf("Bir sayi giriniz:");
            scanf("%d",&hafiza[hafizaKonum]);
            break;
        case 11:
            printf("\nMemory location: %d\nSonuc(Word):%d",hafizaKonum,hafiza[hafizaKonum]);
            break;
        case 20:
            akumulator=hafiza[hafizaKonum];
            break;
        case 21:
            hafiza[hafizaKonum] = akumulator;         //SAKLA komutu ile akümülatörde saklanan aritmetik işlem sonucunu hafızada sakla.
            break;
        case 30:                                    //30 toplama emri, hafıza konumundaki sayı ile akümülatördeki sayıyı toplar.
            akumulator += hafiza[hafizaKonum];      //SMD bütün aritmetik işlem komutları ve sonuçlarını akümülatörde saklar.
            break;
        case 31:                                    //CIKAR
            akumulator -= hafiza[hafizaKonum];     //case 30 a bak.
            break;
        case 32:                                    //BOL
            akumulator /= hafiza[hafizaKonum];
            break;
        case 33:                                    //CARP
            akumulator *= hafiza[hafizaKonum];
            break;

           /*    40 ve üstü kontrol durumlarında eğer hafiza konumunu i ye olduğu gibi atarsak
            döngünün başında i 1 arttığı için çalıştırmayı istediğimiz komuttan bir sonrki
            komut çalışacağı için progrm yanlış çalışacak. Bu nedenle i ye atama yaptığımız
            bütün komutlarda bir eksik daha alıyoruz.          */


        case 40:                                    //DALLAN
             i=hafizaKonum-1;
            break;
        case 41:                                    //akümülatör negatifse hafızadaki belli bir konuma dallan
            if(akumulator<0)
            i=hafizaKonum-1;
            break;
        case 42:                                    //akümülatör 0 ise hafızadaki belli bir konuma dallan
            if(akumulator==0)
            i=hafizaKonum-1;
            break;
        case 43:
            return 0;                               //Programi bitir.
        case 0:
            break;
        default:
            printf("Bilinmeyen hata\n");
            exit(-1);
        }
    }


   /*
    printf("SMD komutlari giriniz(for exit 4300)\n");

    while(komut!=4300) {                //43 BITIR girilmediği sürece komut almaya devam et.
        scanf("%d",&komut);
        printf("%d.komut:%d\n",i+1,komut);
        hafiza[i]=komut;
        komutIsle(komut,hafiza,aPtr);
        i++;
    }

*/
 return 0;

}


/*
void komutIsle(int hafiza[],int *aPtr) {


    return 1;
}

*/
