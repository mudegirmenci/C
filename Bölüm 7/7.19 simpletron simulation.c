/*
    Simpletron (SMD) bir bilgisayar simülatörüdür.Makina dilini simüle eder. Sadece kendi anlayacaðý
    dilde yazýlan programlarý çalýþtýrabilmektedir.
    -Simpletron bir akümülatör(SMD hesaplamalarda kullanacaðý bilgiyi buraya koyar) içermektedir.
    -SMD, word ile iþlenir. Bir word onluk sistemde dört basamaklý bir sayýdýr. +3364,-6359,+0007 vb.
    -SMD 100 word kapasiteli bir hafýzaya sahiptir ve tüm wordler konum numarasýyla ifade edilirler: 00,01..99.
    -Bir SMD programý çalýþtýrýlmadan önce hafýzaya yüklenmelidir. Ýlk komut ya da ifade 00 konumundan baþlar.
    -SMD de yazýlan her komut hafýzada bir word yer tutar.
    -SMD hafýzasýndaki her word; bir komut, program tarafýndan kullanýlacak bir veri veya
    kullanýlmamýþ(tanýmlanmamýþ) bir hafýza alanýný içerebilir.
    -SMD komutunun ilk iki basamaðý hangi iþlemin yapýlacaðýný gösterir. Örneðin 1007 --> oku ve hafýzada 07 konumuna yaz.
    -SMD komutunun son iki basamaðý ise iþlenecek bilginin hafýza konumunu gösterir.


*/



#include<stdio.h>

#define OKU 10          //Terminalden 1 word bilgi oku ve hafýzadaki belli bir konuma yaz
#define YAZ 11          //Hafýzadan belli bir konumdaki bilgiyi terminalde yaz.
#define YUKLE 20        //Akümülatorü belli bir hafýza konumundan alýnan bir word bilgi ile yükle
#define SAKLA 21        //Akümülatörden bir word bilgi al ve hafýzanýn belli bir konumunda sakla.
#define TOPLA 30        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyi topla(sonucu akümülatörde sakla)
#define CIKAR 31        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyi çýkar(sonucu akümülatörde sakla)
#define BOL   32        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiye böl(sonucu akümülatörde sakla)
#define CARP  33        //Akümülatördeki bir word bilgi ile belli bir hafýza konumundaki bir word bilgiyle çarp(sonucu akümülatörde sakla)
#define DALLAN 40       //Hafýzadaki belli bir konuma dallan.(if yapýlarý gibi)
#define DALLANNEG 41    //Akümülatör negatif ise hafýzadaki belli bir konuma dallan.
#define DALLANSIFIR  42 //Akümülatör sýfýr ise hafýzadaki belli bir konuma dallan.
#define BITIR  43       //Program görevini tamamladý.

#define COMMANDCOUNT 25
#define MEMSIZE 100


void programYukle(int hafiza[]);
void programCalistir(void);
void hafizaDump(int hafiza[],int boyut);

int main(void) {


    int program[COMMANDCOUNT]={0};



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

    int hafiza[100]={0};      //Simpleton 100 word kapasiteli hafýzasý.
    int komut=0,akumulator=+0000;     //akumulator sadece 1 word bilgi tutar. SMD hesaplama yaparken buradaki bilgiyi kullanýr.
    int komutSayici=00;            //Çalýþtýrýlacak komutun hafýzadaki konumu
    int isletimKodu=+0000;            //O anda yapýlan islemi gösterir.  (komut word'un sol iki basamaðý)
    int operand=00;                //o anda iþlenen kodun hangi hafýza konumuyla ilgili iþlem yaptýðýný gösterir. .komut word'un sað iki basamaðý


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
        case 20:
            akumulator=hafiza[operand];
            break;
        case 21:
            hafiza[operand] = akumulator;         //SAKLA komutu ile akümülatörde saklanan aritmetik iþlem sonucunu hafýzada sakla.
            break;
        case 30:                                    //30 toplama emri, hafýza konumundaki sayý ile akümülatördeki sayýyý toplar.
            akumulator += hafiza[operand];      //SMD bütün aritmetik iþlem komutlarý ve sonuçlarýný akümülatörde saklar.
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

           /*    40 ve üstü kontrol durumlarýnda eðer hafiza konumunu i ye olduðu gibi atarsak
            döngünün baþýnda i 1 arttýðý için çalýþtýrmayý istediðimiz komuttan bir sonrki
            komut çalýþacaðý için progrm yanlýþ çalýþacak. Bu nedenle i ye atama yaptýðýmýz
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
            /* Aþaðýdaki çýktýya bilgisayar çöplüðü denir.
               Bir Simpletron programý çalýþtýrýldýktan sonra çöplük çýktýsý
               çýkýþtan hemen sonraki komut deðerlerini ve verilerini içerir.
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

