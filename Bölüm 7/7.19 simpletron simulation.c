/*
    Simpletron (SMD) bir bilgisayar sim�lat�r�d�r.Makina dilini sim�le eder. Sadece kendi anlayaca��
    dilde yaz�lan programlar� �al��t�rabilmektedir.
    -Simpletron bir ak�m�lat�r(SMD hesaplamalarda kullanaca�� bilgiyi buraya koyar) i�ermektedir.
    -SMD, word ile i�lenir. Bir word onluk sistemde d�rt basamakl� bir say�d�r. +3364,-6359,+0007 vb.
    -SMD 100 word kapasiteli bir haf�zaya sahiptir ve t�m wordler konum numaras�yla ifade edilirler: 00,01..99.
    -Bir SMD program� �al��t�r�lmadan �nce haf�zaya y�klenmelidir. �lk komut ya da ifade 00 konumundan ba�lar.
    -SMD de yaz�lan her komut haf�zada bir word yer tutar.
    -SMD haf�zas�ndaki her word; bir komut, program taraf�ndan kullan�lacak bir veri veya
    kullan�lmam��(tan�mlanmam��) bir haf�za alan�n� i�erebilir.
    -SMD komutunun ilk iki basama�� hangi i�lemin yap�laca��n� g�sterir. �rne�in 1007 --> oku ve haf�zada 07 konumuna yaz.
    -SMD komutunun son iki basama�� ise i�lenecek bilginin haf�za konumunu g�sterir.


*/



#include<stdio.h>

#define OKU 10          //Terminalden 1 word bilgi oku ve haf�zadaki belli bir konuma yaz
#define YAZ 11          //Haf�zadan belli bir konumdaki bilgiyi terminalde yaz.
#define YUKLE 20        //Ak�m�lator� belli bir haf�za konumundan al�nan bir word bilgi ile y�kle
#define SAKLA 21        //Ak�m�lat�rden bir word bilgi al ve haf�zan�n belli bir konumunda sakla.
#define TOPLA 30        //Ak�m�lat�rdeki bir word bilgi ile belli bir haf�za konumundaki bir word bilgiyi topla(sonucu ak�m�lat�rde sakla)
#define CIKAR 31        //Ak�m�lat�rdeki bir word bilgi ile belli bir haf�za konumundaki bir word bilgiyi ��kar(sonucu ak�m�lat�rde sakla)
#define BOL   32        //Ak�m�lat�rdeki bir word bilgi ile belli bir haf�za konumundaki bir word bilgiye b�l(sonucu ak�m�lat�rde sakla)
#define CARP  33        //Ak�m�lat�rdeki bir word bilgi ile belli bir haf�za konumundaki bir word bilgiyle �arp(sonucu ak�m�lat�rde sakla)
#define DALLAN 40       //Haf�zadaki belli bir konuma dallan.(if yap�lar� gibi)
#define DALLANNEG 41    //Ak�m�lat�r negatif ise haf�zadaki belli bir konuma dallan.
#define DALLANSIFIR  42 //Ak�m�lat�r s�f�r ise haf�zadaki belli bir konuma dallan.
#define BITIR  43       //Program g�revini tamamlad�.

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

/* Terminalden +1009 gibi SMD kodlar�n� al�r. */
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

    int hafiza[100]={0};      //Simpleton 100 word kapasiteli haf�zas�.
    int komut=0,akumulator=+0000;     //akumulator sadece 1 word bilgi tutar. SMD hesaplama yaparken buradaki bilgiyi kullan�r.
    int komutSayici=00;            //�al��t�r�lacak komutun haf�zadaki konumu
    int isletimKodu=+0000;            //O anda yap�lan islemi g�sterir.  (komut word'un sol iki basama��)
    int operand=00;                //o anda i�lenen kodun hangi haf�za konumuyla ilgili i�lem yapt���n� g�sterir. .komut word'un sa� iki basama��


    // Terminalden program y�kle
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
            hafiza[operand] = akumulator;         //SAKLA komutu ile ak�m�lat�rde saklanan aritmetik i�lem sonucunu haf�zada sakla.
            break;
        case 30:                                    //30 toplama emri, haf�za konumundaki say� ile ak�m�lat�rdeki say�y� toplar.
            akumulator += hafiza[operand];      //SMD b�t�n aritmetik i�lem komutlar� ve sonu�lar�n� ak�m�lat�rde saklar.
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

           /*    40 ve �st� kontrol durumlar�nda e�er hafiza konumunu i ye oldu�u gibi atarsak
            d�ng�n�n ba��nda i 1 artt��� i�in �al��t�rmay� istedi�imiz komuttan bir sonrki
            komut �al��aca�� i�in progrm yanl�� �al��acak. Bu nedenle i ye atama yapt���m�z
            b�t�n komutlarda bir eksik daha al�yoruz.          */


        case 40:                                    //DALLAN
             komutSayici=operand-1;
            break;
        case 41:                                    //ak�m�lat�r negatifse haf�zadaki belli bir konuma dallan
            if(akumulator<0)
            komutSayici=operand-1;
            break;
        case 42:                                    //ak�m�lat�r 0 ise haf�zadaki belli bir konuma dallan
            if(akumulator==0)
            komutSayici=operand-1;
            break;
        case 43:
            /* A�a��daki ��kt�ya bilgisayar ��pl��� denir.
               Bir Simpletron program� �al��t�r�ld�ktan sonra ��pl�k ��kt�s�
               ��k��tan hemen sonraki komut de�erlerini ve verilerini i�erir.
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

