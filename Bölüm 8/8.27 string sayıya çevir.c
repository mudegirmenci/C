/*

Sstringleri sayýya çevir
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* n stringini int e dönüºtürür. */
int myatoi(const char *nPtr);
/* n stringini double e dönüºtürür. */
double myatof(const char *nPtr);
/* n stringini long e dönüºtürür. */
long myatol(const char *nPtr);
/* n stringini double e ve kalan stringi  dönüºtürür. */
double mystrtod(const char *nPtr, char **stringPtr);
/* n stringini long dönüºtürür ve kalan stringi verir. */
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
 '0' çýkarmamýzýn nedeni ascii tablosu. Öneðin 98 i int e çevirmek istiyoruz.
 ilk önce 9, daha sonra 90+8 almamýz gerekecek fakat ilk turda nPtr[0] ifadedesi
 beklediðimiz gibi 9 yerine 57 veriyor. Çünkü hala bir string ve ascii tablodaki karþýlýðý
 neyse onu dönderiyor. Bu nedenle sonuç 626 çýkýyor. 0 ascii tabloda 48. sýrada, 57. sýradaki
 9dan bu deðeri çýkarýrsak: 57-48=9 çýkacaktýr. Bu þekilde doðru sonuca ulaþýrýz.
 negatif sayýlar için sign deðiþkeni kullanýyoruz. Eðer ilk karakter '-' ise, döngüden sonra
 negatif e dönüþtür.


*/
int myatoi(const char *nPtr)
{
    int a=0,sign=0;

    sign = (*nPtr=='-') ? 1: 0;
    nPtr += (sign == 1) ? 1 : 0;    //sayý negatifse string göstergesini bir ileri taþý

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //sayý deðilse programý bitir.
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

    sign = (*nPtr=='-') ? 0 : 1;  //negatifle mi baþlýyor?
    nPtr += sign == 0 ? 1 : 0;    //sayý negatifse string göstergesini bir ileri taþý

    for(;*nPtr!='\0';nPtr++) {

    if(*nPtr<48 || *nPtr>57 ) {  //sayý deðilse programý bitir.
        break;
     }
     else
        a=a*10.0+*nPtr-'0';
    }

    nPtr += (*nPtr=='.') ? 1 : 0;
      for(;*nPtr!='\0';nPtr++) {
        if(*nPtr<48 || *nPtr>57 ) {  //sayý deðilse programý bitir.
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
    nPtr += (sign == 1) ? 1 : 0;    //sayý negatifse string göstergesini bir ileri taþý

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //sayý deðilse programý bitir.
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

    sign = (*nPtr=='-') ? 0 : 1;  //negatifle mi baþlýyor?
    nPtr += sign == 0 ? 1 : 0;    //sayý negatifse string göstergesini bir ileri taþý


    for(;*nPtr!='\0';nPtr++) {

    if(*nPtr<48 || *nPtr>57 ) {  //sayý deðilse programý bitir.
        break;
     }
     else
        a=a*10.0+*nPtr-'0';
     }

    nPtr += (*nPtr=='.') ? 1 : 0;
      for(;*nPtr!='\0';nPtr++) {
        if(*nPtr<48 || *nPtr>57 ) {  //sayý deðilse programý bitir.
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
    nPtr += (sign == 1) ? 1 : 0;    //sayý negatifse string göstergesini bir ileri taþý

    for(;*nPtr!='\0';nPtr++) {

     if(*nPtr<48 || *nPtr>57) {  //sayý deðilse programý bitir.
        break;
     }
     else
        a=a*10+(*nPtr-'0');
    }
    a = (sign==1) ? -1*a : a;

    *stringPtr = nPtr;

     return a;

}
