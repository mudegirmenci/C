/*
    Simpletron (SMD) bir bilgisayar simülatörüdür.Makina dilini simüle eder. Sadece kendi anlayacađý
    dilde yazýlan programlarý çalýţtýrabilmektedir.
    -Simpletron bir akümülatör(SMD hesaplamalarda kullanacađý bilgiyi buraya koyar) içermektedir.
    -SMD, word ile iţlenir. Bir word onluk sistemde dört basamaklý bir sayýdýr. +3364,-6359,+0007 vb.
    -SMD 100 word kapasiteli bir hafýzaya sahiptir ve tüm wordler konum numarasýyla ifade edilirler: 00,01..99.
    -Bir SMD programý çalýţtýrýlmadan önce hafýzaya yüklenmelidir. Ýlk komut ya da ifade 00 konumundan baţlar.
    -SMD de yazýlan her komut hafýzada bir word yer tutar.
    -SMD hafýzasýndaki her word; bir komut, program tarafýndan kullanýlacak bir veri veya
    kullanýlmamýţ(tanýmlanmamýţ) bir hafýza alanýný içerebilir.
    -SMD komutunun ilk iki basamađý hangi iţlemin yapýlacađýný gösterir. Örneđin 1007 --> oku ve hafýzada 07 konumuna yaz.
    -SMD komutunun son iki basamađý ise iţlenecek bilginin hafýza konumunu gösterir.


*/



#include<stdio.h>
#include<math.h>

#define OKU 10          //Terminalden 1 word bilgi oku ve hafýzadaki belli bir konuma yaz
#define YAZ 11          //Hafýzadan belli bir konumdaki bilgiyi terminalde yaz.
#define NEWLINE 12      //Yeni satıra geçer
#define YUKLE 20        //Akümülatorü belli bir hafýza konumundan alýnan bir word bilgi ile yükle
#define SAKLA 21        //Akümülatörden bir word bilgi al ve hafýzanýn belli bir konumunda sakla.


#define TOPLA   30        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyi topla(sonucu akümülatörde sakla)
#define CIKAR   31        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyi çýkar(sonucu akümülatörde sakla)
#define BOL     32        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiye böl(sonucu akümülatörde sakla)
#define CARP    33        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyle çarp(sonucu akümülatörde sakla)
#define MOD     34        //Akümülatördeki bir word bilgi ile belli bir hafıza konumundaki bir word bilgiye bölümünden kalanı bul(sonucu akümülatörde sakla)
#define USSEL   35        //Akümülatördeki bir word bilginin belli bir hafıza konumundaki bir word bilgiye üssünü alır(sonucu akümülatörde sakla)


#define DALLAN 40       //Hafýzadaki belli bir konuma dallan.(if yapýlarý gibi)
#define DALLANNEG 41    //Akümülatör negatif ise hafýzadaki belli bir konuma dallan.
#define DALLANSIFIR  42 //Akümülatör sýfýr ise hafýzadaki belli bir konuma dallan.
#define BITIR  43       //Program görevini tamamladý.


#define COMMANDCOUNT 25
#define MEMSIZE 1000


void programYukle(int hafiza[]);
void programCalistir(void);
void hafizaDump(int hafiza[],int boyut);

int main(void) {


    //int program[COMMANDCOUNT]={0};



    printf( "*************************************************\n"
            "***  Simpletrona hosgeldiniz !                ***\n"
            "***  Lutfen her seferind bir komut ya da      ***\n"
            "*** (bir word) giriniz. Hafiza konumunu       ***\n"
            "***  ve soru isaretini(?) ekrana yazdiracagim ***\n"
            "***  Siz daha sonra o konum icin word'u girin ***\n"
            "***  Programinizi girmeyi sonlandirmak icin   ***\n"
            "***  -99999 nobetci degerini girin.           ***\n"
            "*************************************************\n"
            );

  programCalistir();





 return 0;

}

/* Terminalden +1009 gibi SMD kodlarýný alýr. */
void programYukle(int hafiza[]) {

    printf("SMD komutlari giriniz(for exit -99999)\n");
    int i=0,komut=0;

    while(komut!=-99999) {
        if(i<10) printf("0%d ? +",i);
        else printf("0%d ? +",i);
        scanf("%d",&komut);
        hafiza[i]=komut;
        i++;
    }
    printf("*** Program yuklenmesi bitti ***\n");
    return 0;
}

void programCalistir(void) {

    int hafiza[MEMSIZE]={0};      //Simpleton 1000 word kapasiteli hafýzasý.
    int akumulator=+0000;         //akumulator sadece 1 word bilgi tutar. SMD hesaplama yaparken buradaki bilgiyi kullanýr.
    int komutSayici=00;           //Çalýţtýrýlacak komutun hafýzadaki konumu
    int isletimKodu=+0000;        //O anda yapýlan islemi gösterir.  (komut word'un sol iki basamađý)
    int operand=00;               //o anda iţlenen kodun hangi hafýza konumuyla ilgili iţlem yaptýđýný gösterir. .komut word'un sađ iki basamađý


    // Terminalden program yükle
    programYukle(hafiza);
    printf("*** Program calistiriliyor   ***\n");


    for(int komutSayici=0;komutSayici<MEMSIZE;komutSayici++) {

       int komutRegister = hafiza[komutSayici];
       isletimKodu=komutRegister/100;
       operand=komutRegister%100;

        switch(isletimKodu) {
        case 10:                             //terminalden bilgi oku.
            printf("Bir sayi giriniz:");
            scanf("%d",&hafiza[operand]);
            break;
        case 11:
            printf("\nMemory location: %d\nSonuc(Word):%d",operand,hafiza[operand]);
            break;
        case 12:
            printf("\n");
            break;
        case 20:
            akumulator=hafiza[operand];
            break;
        case 21:
            hafiza[operand] = akumulator;         //SAKLA komutu ile akümülatörde saklanan aritmetik iţlem sonucunu hafýzada sakla.
            break;
        case 30:                                    //30 toplama emri, hafýza konumundaki sayý ile akümülatördeki sayýyý toplar.
            akumulator += hafiza[operand];      //SMD bütün aritmetik iţlem komutlarý ve sonuçlarýný akümülatörde saklar.
            break;
        case 31:                                    //CIKAR
            akumulator -= hafiza[operand];     //case 30 a bak.
            break;
        case 32:                                    //BOL
            akumulator /= hafiza[operand];
            break;
        case 33:                                    //CARP
            akumulator *= hafiza[operand];
            break;
        case 34:                                    //MOD
            akumulator %= hafiza[operand];
            break;
        case 35:                                    //USSEL
            akumulator = pow(akumulator,hafiza[operand]);
            break;

           /*    40 ve üstü kontrol durumlarýnda eđer hafiza konumunu i ye olduđu gibi atarsak
            döngünün baţýnda i 1 arttýđý için çalýţtýrmayý istediđimiz komuttan bir sonrki
            komut çalýţacađý için progrm yanlýţ çalýţacak. Bu nedenle i ye atama yaptýđýmýz
            bütün komutlarda bir eksik daha alýyoruz.          */


        case 40:                                    //DALLAN
             komutSayici=operand-1;
            break;
        case 41:                                    //akümülatör negatifse hafýzadaki belli bir konuma dallan
            if(akumulator<0)
            komutSayici=operand-1;
            break;
        case 42:                                    //akümülatör 0 ise hafýzadaki belli bir konuma dallan
            if(akumulator==0)
            komutSayici=operand-1;
            break;
        case 43:
            /* Aţađýdaki çýktýya bilgisayar çöplüđü denir.
               Bir Simpletron programý çalýţtýrýldýktan sonra çöplük çýktýsý
               çýkýţtan hemen sonraki komut deđerlerini ve verilerini içerir.
               */
            printf("***\n\n Simpletron calismasi durduruldu ***\n\n");
            printf("Akumulator:%d\n"
                   "komutSayici:%d\n"
                   "komutRegister:%d\n"
                   "isletimKodu:%d\n"
                   "operand:%d\n",akumulator,komutSayici,komutRegister,isletimKodu,operand );
                   hafizaDump(hafiza,MEMSIZE);
            return 0;
        case 0:
            break;
        default:
            printf("Bilinmeyen hata\n");
            exit(-1);
        }
    }
    return 0;
}

void hafizaDump(int hafiza[],int boyut) {

    printf("\n\nHAFIZ DOKUMU\n");
    for(int i=0;i<boyut;i++) {
        if(i%10==0) printf("\n");
        printf("%+8d",hafiza[i]);


    }

}

