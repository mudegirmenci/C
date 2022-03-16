/*

Kablumba?a ve tav?an simülasyonu:

Hayvan          Hareket Tipi    Zaman Yüzdesi      Hareket
-----------------------------------------------------------------
Kablumbaga       Hızlı Yürümek   %50                3 kare sağa
                 Kaymak          %20                6 kare sola
                 Yavaş Yürüme    %30                1 kare sağa

Tavşan          Uyku            %20                Hareket yok
                Büyük Zıplama   %20                9 kare sağa
                Büyük kayma     %10                12 kare sola
                Küçük Zıplama   %30                1 kare sağa
                Küçük Kayma     %20                2 kare sola


- Oyun sol üst köşeden başlar ve 70 kare uzaklıkta olduğu kabul edilen sağ alt köşede biter.
- Kaymalar'da hayvanlar sola, diğerlerinde sağa veya hareket yok olurlar.
- Oyun kare 1 den başlar(sol üst köşe)
- Oyuncular başlangıçta sola kayarsa tekrar kare 1 e yerleşsinler.
- Oyuncularn konumlarını saklamak için tPoz,kPoz değişkenlerini kullan.
- Konum değişkeni ilk 70(PIST) olan oyuncu kazanır. Aynı anda ulaşırlarsa birine torpil yapılır veya BERABERE yazılır.
- Kazanan olmazsa oyun tekrar başlar ve KAZANAN YOK, OYUN TEKRARI yazılır.
- Tablodaki yüzdeler için 1<=i<=10 olmak üzere rasgele bir i sayısı oluşturulur ve:
        Kablumbağa Hızlı yürüme için: 1<=i<=5  (%50) -->3 SAĞ
                   Kayması için     : 6<=i<=7  (%20) -->6 SOL
                   Yavaş yürüme için: 8<=i<=10 (%30) -->1 SAĞ

        Tavşan     Uyuması için      :1<=i<=2   (%20) -->0
                   Büyük zıplama için:3<=i<=4   (%20) -->9 SAĞ
                   Büyük kayma için  :5<=i<=5   (%10) -->12 SOL
                   Büyük kayma için  :6<=i<=8   (%30) -->1 SAĞ
                   Küçük kayma için  :9<=i<=10  (%20) -->2 SOL
- K harfi kablumbağa, T ise tavşan.
- Yarışmacılar aynı pozisyonda olurlarsa kablumbağa tavşanı ısırsın ve tavşandan AH!!! sesi çıksın.
- Her satır yazdırma sonrası herhangi bir yarışmacının 70. kareye gelip gelmediği kontrol edilsin.
   ------------------------------------------------------------ 70 satır
1 | START
2 |  T   K
3 |         K
4 |                 T
5 |                             AHH!
6 |                                         K           T
7 |                                 K                                   T
8 |
9 |                                                                                    K
10 |
11 |                                                                          Kablumbağa kazanır
12 |
13 |
14 |

*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PIST 70

void walks(int *kPoz,int *tPoz);
void yazdir(int *k,int *t);
void skorYaz(int *kPoz,int *tPoz);

int main(void){


    int tPoz=0,kPoz=0,kontrol=1;
    int *tPtr=&tPoz,*kPtr=&kPoz;



   srand(time(NULL));

   printf("CUVV!!! YARIS BASLIYOR !!!\n");
   while(kontrol) {
     walks(kPtr,tPtr);
     yazdir(kPtr,tPtr);

    if(tPoz>=70 || kPoz>=70) {
      kontrol=0;
      skorYaz(kPtr,tPtr);
      break;
    }
      sleep(1);
   }

}
/* yarışmacıların birer hamlesi*/
void walks(int *kPoz,int *tPoz) {

  int random=1+rand()%10;

   switch(random) {

    case 1: case 2:
            *kPoz+=3;
            *tPoz+=0;
            break;
    case 3: case 4:
            *kPoz+=3;
            *tPoz+=9;
            break;
    case 5:
            *kPoz+=3;
            *tPoz-=12;
            break;
    case 6:
            *kPoz-=6;
            *tPoz+=1;
            break;
    case 7:
            *kPoz-=6;
            *tPoz+=1;
            break;
    case 8:
            *kPoz+=1;
            *tPoz+=1;
            break;
    case 9:
            *kPoz+=1;
            *tPoz-=2;
            break;
    case 10:
            *kPoz+=1;
            *tPoz-=2;
            break;

   }
    /* Oyun başlangıcında sola kaymalar olursa başlangıç pozisyonuna al. */
   *tPoz= *tPoz<0 ? 0 : *tPoz;
   *kPoz= *kPoz<0 ? 0 : *kPoz;

   //printf("K:%d  T:%d",*kPoz,*tPoz);
}

void skorYaz(int *kPoz,int *tPoz) {
    if(*kPoz>=70 && *tPoz>=70)  printf("BERABERE");
    else if(*kPoz>=70) printf("KABLUMBAĞA KAZANDI!");
    else if(*tPoz>=70) printf("TAVŞAN KAZANDI!");

}

void yazdir(int *k,int *t){

    for(int i=0;i<=70;i++) {
        if(i==*t && i==*k) printf("AHH!!!");
        else if(i==*k) printf("K",*k);
        else if(i==*t) printf("T",*t);
        else printf(" ");
    }
    printf("\n");
}

