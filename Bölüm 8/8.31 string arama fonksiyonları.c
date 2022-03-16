/*
string karţýlaţtýrma fonksiyonlarý
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ikinci arguman olarak verilen bir karakterin ilk argumanda verilen dizide
   olup olmadığını arar. Bulursa c yi gösteren bir gösterici döner.
   */
char *mystrchr(const char *s1,int c);

/* c karakterinin s1 içinde son görüldüğü yerden itibaren
s1 stringine ait işaretçiyi alır.
*/
char *mystrrchr(const char *s1,int c);
/* Program strcspn() fonksiyonu ile bir karakter dizisi içindeki
 karakterlerin herhangi birinin diğer karakter dizisi içinde bulunduğu
 ilk yerin indeksini hesaplayarak elde ettiği sonucu ekrana yazar.
 */
size_t mystrcspn(const char *s1,const char *s2);

/* Birinci stringin ilk karakterinden itibaren ikinci string
 karakterlerinden kaç tane var */
size_t mystrspn(const char *s1,const char *s2);

/*s2 içindeki herhangi bir karakterin s1 içinde yer aldığı ilk konumu bulur. */
char *mystrpbrk(const char *s1,const char *s2);

/* s1 içinde s2 ninilk konumunu belirler. s2 stringi bulunduğu
yerden itibaren s1 değerini dönderir.*/
char *mystrstr(const char *s1,const char *s2);

char *mystrtok( char *s1,const char *s2);

int main()
{
   char s1[100] = "Bu string icinde arama yap";
   char s2[100] ="Bu str varsa";
   char c1='r';
   char c2='a';
   int index;

   printf("strchr> mystrchr\n");
   if(mystrchr(s1,c1)!=NULL)
        printf("%c karakterinin ilk gorundugu yerden itibaren s1 stringi:%s\n",c1,mystrchr(s1,c1));
    else
        printf("%c bu stringte bulunamadi:%s\n",c1,s1);

   printf("\n");

   printf("strrchr> mystrrchr\n");
   if(mystrrchr(s1,c1)!=NULL)
        printf("%c karakterinin son gorundugu yerden itibaren s1 stringi:%s\n",c1,mystrrchr(s1,c1));
    else
        printf("%c bu stringte bulunamadi:%s\n",c1,s1);

  printf("\n");


  printf("strcspn> mystrcspn \n");
  index = mystrcspn(s1,s2);
  printf("\n\"%s\" icinde, \"%s\" stringinin bulundugu ilk index:%d\n",s1,s2,index);

  printf("\n");

  printf("strspn> mystrspn ** s1 icinde s2 dizisindeki karakterlerden kac tane var **\n");
  index = mystrspn(s1,s2);
  printf("\n\"%s\" icinde, \"%s\" stringinin karakterlerinden %d var\n",s1,s2,index);

  printf("\n");

  printf("strpbrk> mystrpbrk ** s1 içerisinde s2 dizisindeki karakterlerden ilk hangisine raslandi **\n");
  printf("\n\"%s\" icinde, \"%s\" stringinin karakterlerinden ilk \"%c\" karakterine rastlandi\n",s1,s2, mystrpbrk(s1,s2));

  printf("\n");

  printf("strstr> mystrstr ** s1 icerisinde s2 dizisine ilk raslandigi yerden itibaren s1 **\n");
  printf("%s\n",mystrstr(s1,"string"));

  printf("\n");

  printf("strtok> mystrtok ** s1 atomlara bolunmus hali **\n");
  printf("\"%s\" atomlar:%s\n",s1, mystrtok(s1,", "));

}

char *mystrchr(const char *s1,int c)
{

    for(;*s1!='\0';s1++) {
        if(*s1==c)
            return s1;
    }
  return 0;
}

char *mystrrchr(const char *s1,int c)
{
    char *son;
    for(;*s1!='\0';s1++) {
        if(*s1==c)
            son= s1;
    }
  return son;
}

size_t mystrcspn(const char *s1,const char *s2)
{
    int bulunanilkKarakter=0,i=0,k=strlen(s1);
    for(;*s2;s2++) {
        for( i=0;*s1;s1++,i++){
            if(*s1==*s2) {
              bulunanilkKarakter = bulunanilkKarakter==0 ? i :bulunanilkKarakter;       //bulunanilkKarakter değişkeni ilk defa mı deger alacak?
              bulunanilkKarakter = i < bulunanilkKarakter ? i : bulunanilkKarakter;    //string içinde ilk sırada hangi karakter var?
              break;
            }
        }
        s1 =s1-i;  //işaretciyi sıfırla (dizinin bellekteki başlangıç konumuna git)
    }
    if(bulunanilkKarakter==0)
        return k;
    return bulunanilkKarakter;
}

/* https://www.2braces.com/c-programming/c-strspn
   -s1 s2 ile başlamalı
   - s1=Bu string içinde arama yap ve s2= Bu strspn fonksiyonu ise
   s1 içinde ikinci stringin karakterlerini sayar. sonuç 6.
   */
size_t mystrspn(const char *s1,const char *s2)
{
    int i=0;

    if(*s1!=*s2) return 0;  //ilk karakterler farklıysa 0 sonucu donder
        for(;*s1;s1++,s2++){  //s1 ve s2 esleştirme yapmaya başla
            if(*s1==*s2)       //eşleşen karakterleri say
               i++;
        }

    return i;
}

/*s2 içindeki herhangi bir karakterin s1 içinde yer aldığı ilk konumu bulur. */
char *mystrpbrk(const char *s1,const char *s2)
{
    int i=strlen(s1);

    for(;*s2!='\0';s2++) {
        for(;*s1!='\0';s1++){
            if(*s1==*s2)
               return *s2;
        }
        s1 =s1-i;  //işaretciyi sıfırla (dizinin bellekteki başlangıç konumuna git)
    }
    return 0;
}
/* s1 içinde s2 ninilk konumunu belirler. s2 stringi bulunduğu
yerden itibaren s1 değerini dönderir.*/
char *mystrstr(const char *s1,const char *s2)
{
    char *s1Adres;          //gecici string 1 adresi tutacağı
    for(;*s1!='\0';s1++) {  //string 1 içerisinde yürümeye başla
        if(*s1==*s2){       //s2 nin ilk karakterini bulursan
            s1Adres=s1;     //s2 nin ilk karakterini bulduğun s1 adres konumunu yedekle
            while(*s2){        //s2 nin sonuna ulasana kadar s1 ile eslesme oluyor mu kontrol et
                if(*s1!=*s2)    //eşleşme bozulursa
                    return 0; //s2 s1 icinde bulunamadi
                s2++;         //stringler içinde yürümeye devam et
                s1++;
            }
            break;
        }
    }
  return s1Adres;
}


char *mystrtok( char *s1,const char *s2)
{
    int i=strlen(s2),j=strlen(s1);
    char *stringKonum;

    stringKonum = s1;           //s1 in güncel konumunu yedekle

    for(;*s1;s1++) {                //s1 içinde yürümeye başla
       while(*s2) {                //s2 deki karakterleri tek tek s1 le eşleştir
          if(*s1==*s2) {          //eşleşme bulunursa
                *s1 ='\0';          //atom sonuna null ekle
              //  return stringKonum; //bulunan atomu geri gönder
            }
            s2++;                   //eşleşme bulunamazsa s2 de sonraki ayırıcı karaktere geç
        }
        s2-=i;                      //bir sonraki s1 akrakteri için s2 konum düzenle.
    }
    return stringKonum;
}
