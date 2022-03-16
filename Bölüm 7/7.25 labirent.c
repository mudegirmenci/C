/*

labirentYap(dizi,start,finish)


                2. Duvar
         *************************
         *                       *
         *                       *
         *                       *
1. Duvar *                       *   3. Duvar
         *                       *
         *                       *
         *                       *
         *                       *
         *                       *
         *************************

                4. Duvar
. lar yok
# ler duvar


1. Labirent dizisinin büün elemanlarını 0 ata.
2. 1. duvar için rasgele bir giriş noktası belirle ve bu noktaya '.' ata
3. 3. duvar için rasgele bir çıkış noktası belirle ve bu noktaya '.' ata
4. Eğer 2. ve 4. duvarlar ise # yap
5. Eğer 1. ve 3. duvarlar ise ve değer . değilse # yap.
6. Giriş noktasından başlayarak çıkış noktasına kadar rasgele . lar ata. Burada labirentin çözülmüş yolunu çiziyouruz.
    - Noktalar sürekli olmalı; yani aralarında boşluk veya duvar bulunmamalı. Bu adımda sahte yollar veya duvarlar
     çizmiyoruz, sadece labirent başlangıç ve bitiş arasındaki yolu çiziyoruz. Asıl zor kısım burası.
    - 4 duvar bu çizime dahil değil. İşlemimiz 12x12 lik bir labirentte 11x11 lik alan için geçerli.

7. 4 duvarı çizdik(4 duvar en son da çizilebilir), labirent yolunu çizdik, şimdi 0 larla dolu olan kareleri
    rasgele # veya . ile doldurup sahte yollarla duvarları oluşturuyouz.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 25
#define ICBOYUT BOYUT-2

void icLabirentOlustur(char iclabirent[][ICBOYUT],int start[2],int finish[2],int boyut);
void labirentDuvarYap(char labirent[][BOYUT],int start[2],int finish[2]);
void labirentYazdir(char labirent[][BOYUT],int boyut);


int main (){

    srand(time(NULL));

    char labirent[BOYUT][BOYUT]={0};
  /* Labirent oluşuracak iç duvarı rasgele oluştur. */
    char iclabirent[ICBOYUT][ICBOYUT]= {0};


   /* giriş ve çıkış için  satırı rasgele oluştur
      (1+rand()%(BOYUT-2)) ifadesi ilk ve son satıra giriş veya çıkış atama anlamında kullanıldı.

   */
    int giris[2]={(1+rand()% (BOYUT-2)),0},cikis[2]={(1+rand()%(BOYUT-2)),BOYUT-1};

   /* giriş ve çıkış noktalarını . olarak ayarlar. */
   labirent[giris[0]][giris[1]] ='.';
   labirent[cikis[0]][cikis[1]] ='.';

 /* Duvarların içindeki labirenti oluştur. */
    icLabirentOlustur(iclabirent,giris,cikis,ICBOYUT);

  /* iç labirenti duvarların içiyle birleştir */
    for(int i=0;i<ICBOYUT;i++)
        for(int j=0;j<ICBOYUT;j++)
            labirent[i+1][j+1]=iclabirent[i][j];

 /* labirent duvarları ve giriş-çıkış noktalarını oluştur.*/
    labirentDuvarYap(labirent,giris,cikis);


    printf("\n");
    printf("\nDis labirent:\n");
    labirentYazdir(labirent,BOYUT);


}

void labirentDuvarYap(char labirent[][BOYUT],int start[2],int finish[2])
{

    /* 2. ve 4. duvarlarlara # ata  */
       for(int i=0;i<BOYUT;i++)
           for(int j=0;j<BOYUT;j++) {
           if((j==0 && labirent[i][j]!='.') || (j==BOYUT-1 && labirent[i][j]!='.') )  //ilk sütun ve konum . değilse veya son sütun ve konum . değilse.
              labirent[i][j] ='#';
           labirent[0][i] = '#';           //ilk satırı (2. duvar) yap
           labirent[BOYUT-1][i] = '#';     //son satırı (4. duvar) yap


     }


}
/*
labirentin ortası için:
    1. Giriş noktasından başla
    2. Yön ve nokta sayısı için rasgele sayılar oluştur.
        -Yönler: 1-yukarı(kuzey) 2-aşağı(guney) 3-sağ(doğu) 4-sol(batı)    yon =rand() %4;
        -Nokta sayısı: noktaSayisi = rand() % maksNoktaSayisi;
            Mevcut konuma göre maksimum nokta sayısı değişecektir.
                        Örneğin 2,3 konumu için yukarı yönde maksimum 1 nokta  (mevcut satır - 1)
                                                aşağı yönde maksimum 8 nokta   (BOYUT-2) - mevcut satır
                                                sola doğru maksimum  2 nokta    mevcut sütun-1
                                                sağa doğru maksimum  7 nokta    (BOYUT-2) - mevcut sütun



  #  #  #  #  #  #  #  #  #  #  #  #
  #                                #
  .        .                       #
  #                                #
  #                                .
  #                                #
  #                                #
  #                                #
  #                                #
  #                                #
  #                                #
  #  #  #  #  #  #  #  #  #  #  #  #


 - iç labirent dış duvarlar olmadan kalan iç bölme. Burada rasgele duvar veya yol oluşturulacak.
*/
void icLabirentOlustur(char iclabirent[][ICBOYUT],int start[2],int finish[2],int boyut)
{
     /* Yönler: yukarı 1 aşağı 2 sağ 3 sol 4

      maksNokta sayısı, seçilen yönde duvara kadar olan nokta sayısı.,
     noktaSayisi, 1 ile maksimum nokta sayısı arasında seçilecek bir sayı.
     rasgele seçilen yönde noktaSayisi kadar ilerle.
     */
    int noktaSayisi,maksNoktaSayisi,x,y,finishx,finishy,yon;

    /*Bitiş satır ve sütun indisleri.
    Tablo boyutu küçüldüğü için indisler yeni tablo boyutuna göre ayarlandı   */
    finishx=(finish[0]-1);
    finishy=(finish[1]-2);

    /* labirent girişinin ilk sağından başla
     Tablo boyutu küçüldüğü için indisler yeni tablo boyutuna göre ayarlandı   */
    iclabirent[start[0]-1][start[1]]='.';
    iclabirent[finish[0]-1][finish[1]-2]='.';

   /* Her ilerlemede mevcut konumu satır ve sütun olarak saklayacak değişkenler. */
    x =start[0]-1;
    y =start[1];


/*  Sona ulaşılmadığı sürece çalışmaya devam et.
    aşağıda labirent çıkışı x ile işaretlendi.
*/
   while(iclabirent[finishx][finishy]!='x') {

          yon =1+rand()%4;

         switch(yon) {
                    case 1:                                       //yukarı
                        maksNoktaSayisi = x;                       //en fazla satır sayısı kadar gidebilir
                        noktaSayisi = maksNoktaSayisi>0 ? 1+rand() % maksNoktaSayisi  :  0;   //maksNoktasayisi 0 dan büyükse 1 ile maksnoktasayisi arasında rasgele bir değer seç
                       // printf("yon:%d x:%d y:%d maksnokta:%d noktasayisi:%d\n",yon,x,y,maksNoktaSayisi,noktaSayisi);
                        for(int i=0;i<=noktaSayisi;i++) {                //nokta sayısı kadar seçilen yönde  ilerle
                            iclabirent[x-i][y] = (x-i==finishx && y==finishy)?  'x'  : '.';   //bitiş noktasına geldiyse x koy
                            if( x-i-1==finishx && y==finishy ) {
                              iclabirent[finishx][finishy]='x';
                              break;
                            }
                        }
                        x=x-noktaSayisi+1;
                        break;
                    case 2:                                 //aşağı
                        maksNoktaSayisi = boyut-x;
                        noktaSayisi = maksNoktaSayisi>0 ? 1+rand() % maksNoktaSayisi  :  0;
                         for(int i=0;i<=noktaSayisi;i++) {
                            iclabirent[x+i][y] = (x+i==finishx && y==finishy)?  'x'  :  '.';
                            if( x+i+1==finishx && y==finishy ){
                               iclabirent[finishx][finishy]='x';
                               break;
                            }
                        }
                         x=x+noktaSayisi-1;
                         break;
                    case 3:                                 //sağ
                        maksNoktaSayisi =  boyut-y;
                        noktaSayisi = maksNoktaSayisi>0 ? 1+rand() % maksNoktaSayisi  :  0;
                        for(int i=0;i<=noktaSayisi;i++) {
                            iclabirent[x][y+i]= (x==finishx && y+i==finishy) ? 'x' : ' .';
                            if( y+i+1==finishy && x==finishx ) {  //eğer bir sonraki hücre bitiş hücresiyse bitişe geldi olarak işaretle
                                iclabirent[finishx][finishy]='x';
                                break;
                            }
                        }
                        y=y+noktaSayisi-1;
                        break;
                    case 4:                                 //sol
                        maksNoktaSayisi = y;
                        noktaSayisi = maksNoktaSayisi>0 ? 1+rand() % maksNoktaSayisi  :  0;
                        for(int i=0;i<=noktaSayisi;i++)
                            iclabirent[x][y-i]=(x==finishx && y-i==finishy) ? 'x' :    '.';
                        y=y-noktaSayisi;
                         break;
                    default:
                        printf("Bir hata oluştu\n");
                        return 0;
                        break;

                 }

    }
    iclabirent[finishx][finishy]='.';  //bitiş hücresinin x işaretini kaldır.

        printf("ic labirent:\n");
            for(int i=0;i<boyut;i++)
                for(int j=0;j<boyut;j++) {
                   if(iclabirent[i][j]==0) {   //boş kalan hücrelere rasgele . ve # ata
                      int a=rand()%6;           //. dan çok # rasgele atasın.
                      iclabirent[i][j]= a==0 ? '.' : '#';
                    }
                   if(j%boyut==0)
                    printf("\n");
                printf("%3c",iclabirent[i][j]);
            }


}

void labirentYazdir(char labirent[][BOYUT],int boyut){

     for(int i=0;i<boyut;i++)
        for(int j=0;j<boyut;j++) {
           if(j%boyut==0)
              printf("\n");
           printf("%3c",labirent[i][j]);
    }
}


