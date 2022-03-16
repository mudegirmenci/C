/*
string kopyalama ve ekleme fonksiyonlarý
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy(char *s1,const char *s2);
char *mystrncpy(char *s1,const char *s2,size_t n);
char *mystrcat(char *s1,const char *s2);
char *mystrncat(char *s1,const char *s2,size_t n);

int main()
{
   char s1[100] = "Birinci String";
   char s2[100] ="ikinci String";

   mystrcpy(s1,s2);
   printf("%s\n",s1);

   mystrncpy(s1,s2,6);
   s1[6]='\0';
   printf("%s\n",s1);

   mystrcat(s1,s2);
   printf("%s\n",s1);

   mystrncat(s1,s2,6);
   printf("%s\n",s1);
}

char *mystrcpy(char *s1,const char *s2)
{
/*
    *s1=*s2 karakter karakter s2 yi s1 e atar. s2 de null karakter bulunca
    s1 e atar ve döngü sona erer. Bir atama ifadesinin değeri , sol argumana atanan deger oladuğu
    için s1=\0 gören while döngüyü bitirir.
*/
  while((*s1=*s2)!='\0') {
    s1++;
    s2++;
  }
}

char *mystrncpy(char *s1,const char *s2,size_t n)
{
   for(int i=n;((*s1=*s2)!='\0' && i>=0);i--,s1++,s2++);
}
char *mystrcat(char *s1,const char *s2)
{
    for(;*s1!='\0';s1++);
    for(;(*s1=*s2)!='\0';s1++,s2++);

}
/* s2 den n sayıda karakteri s1 e ekle*/
char *mystrncat(char *s1,const char *s2,size_t n)
{
    int i=0;

    /* s1 in sonuna kadar gel*/
    for(;*s1!='\0';s1++);
    /* s1 sonlandırıcı karakterinden itibaren s2 elemanlarını teker teker
       s1 e ekle. eğer s2 de karakter biter veya eklenecek karakter sayısı dolarsa
       döngüden çık.
       */
    for(i=n;((*s1=*s2)!='\0' && i>=0);i--,s1++,s2++);
    /* yeni s1 stringi sonuna null karakteri ekle*/
    *s1='\0';

}
