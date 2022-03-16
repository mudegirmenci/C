/*

Sstringleri say�ya �evir
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* n stringini int e d�n��t�r�r. */
int myatoi(const char *nPtr);
/* n stringini double e d�n��t�r�r. */
double myatof(const char *nPtr);
/* n stringini long e d�n��t�r�r. */
long myatol(const char *nPtr);
/* n stringini double e ve kalan stringi  d�n��t�r�r. */
double mystrtod(const char *nPtr, char **stringPtr);
/* n stringini long d�n��t�r�r ve kalan stringi verir. */
long mystrtol(const char *nPtr, char **stringPtr,int base);

int main()
{

 printf("%d\n",myatoi("-984sd54a"));
 printf("%f\n",myatof("-984.5168774"));
 printf("%ld\n",myatol("98458"));

 printf("\n");

 /* strtod */

 char *string ="52.8 string kabul edildi.";
 char *stringPtr;
 double d;
 d =mystrtod(string,&stringPtr);
 printf("string icindeki double:%.2f, kalan string:%s\n",d,stringPtr);
 printf("\n");

 /* strtod */

 char *string2 ="584 string kabul edildi.";
 char *stringPtr2;
 long l;
 l =mystrtol(string2,&stringPtr2,0);
 printf("string icindeki long:%ld, kalan string:%s\n",l,stringPtr2);

}

/*
 '0' ��karmam�z�n nedeni ascii tablosu. �ne�in 98 i int e �evirmek istiyoruz.
 ilk �nce 9, daha sonra 90+8 almam�z gerekecek fakat ilk turda nPtr[0] ifadedesi
 bekledi�imiz gibi 9 yerine 57 veriyor. ��nk� hala bir string ve ascii tablodaki kar��l���
 neyse onu d�nderiyor. Bu nedenle sonu� 626 ��k�yor. 0 ascii tabloda 48. s�rada, 57. s�radaki
 9dan bu de�eri ��kar�rsak: 57-48=9 ��kacakt�r. Bu �ekilde do�ru sonuca ula��r�z.
 negatif say�lar i�in sign de�i�keni kullan�yoruz. E�er ilk karakter '-' ise, d�ng�den sonra
 negatif e d�n��t�r.


*/
int myatoi(const char *nPtr)
{
    int a=0,sign=0;

    sign = (*nPtr=='-') ? 1: 0;
    nPtr += (sign == 1) ? 1 : 0;    //say� negatifse string g�stergesini bir ileri ta��

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //say� de�ilse program� bitir.
        break;
     }
     else
        a=a*10+(*nPtr-'0');
    }
    a = (sign==1) ? -1*a : a;
   return a;
}

double myatof(const char *nPtr)
{
    double a=0,decimal_digit=1.0;
    int sign=0;

    sign = (*nPtr=='-') ? 0 : 1;  //negatifle mi ba�l�yor?
    nPtr += sign == 0 ? 1 : 0;    //say� negatifse string g�stergesini bir ileri ta��

    for(;*nPtr!='\0';nPtr++) {

    if(*nPtr<48 || *nPtr>57 ) {  //say� de�ilse program� bitir.
        break;
     }
     else
        a=a*10.0+*nPtr-'0';
    }

    nPtr += (*nPtr=='.') ? 1 : 0;
      for(;*nPtr!='\0';nPtr++) {
        if(*nPtr<48 || *nPtr>57 ) {  //say� de�ilse program� bitir.
           break;
        }
        else {
           a=a*10.0+*nPtr-'0';
           decimal_digit*=10.0;
        }
       }

    a = (sign==1) ? a : -1*a;
    return a/decimal_digit;
}

long myatol(const char *nPtr)
{
    long a=0;
    int sign=0;

    sign = (*nPtr=='-') ? 1: 0;
    nPtr += (sign == 1) ? 1 : 0;    //say� negatifse string g�stergesini bir ileri ta��

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //say� de�ilse program� bitir.
        break;
     }
     else
        a=a*10+(*nPtr-'0');
    }
    a = (sign==1) ? -1*a : a;
   return a;
}

double mystrtod(const char *nPtr, char **stringPtr)
{


    double a=0,decimal_digit=1.0;
    int sign=0;

    sign = (*nPtr=='-') ? 0 : 1;  //negatifle mi ba�l�yor?
    nPtr += sign == 0 ? 1 : 0;    //say� negatifse string g�stergesini bir ileri ta��


    for(;*nPtr!='\0';nPtr++) {

    if(*nPtr<48 || *nPtr>57 ) {  //say� de�ilse program� bitir.
        break;
     }
     else
        a=a*10.0+*nPtr-'0';
     }

    nPtr += (*nPtr=='.') ? 1 : 0;
      for(;*nPtr!='\0';nPtr++) {
        if(*nPtr<48 || *nPtr>57 ) {  //say� de�ilse program� bitir.
           break;
        }
        else {
           a=a*10.0+*nPtr-'0';
           decimal_digit*=10.0;
        }
       }


    *stringPtr = nPtr;
/*
for(int i=0;i<strlen(nPtr);i++)
 printf("%c",*(*stringPtr+i));

*/
    a = (sign==1) ? -1*a : a;
    return a/decimal_digit;
}

long mystrtol(const char *nPtr, char **stringPtr,int base)
{
    long a=0;
    int sign=0;

    sign = (*nPtr=='-') ? 1: 0;
    nPtr += (sign == 1) ? 1 : 0;    //say� negatifse string g�stergesini bir ileri ta��

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //say� de�ilse program� bitir.
        break;
     }
     else
        a=a*10+(*nPtr-'0');
    }
    a = (sign==1) ? -1*a : a;

    *stringPtr = nPtr;

     return a;

}
