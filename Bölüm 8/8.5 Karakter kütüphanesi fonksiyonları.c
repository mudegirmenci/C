/*

Kullanýcýdan bir karakter alýr ve karakter kütüphanesindeki bütün
fonksiyonlarý kullanarak test eder.

*/

#include <stdio.h>
#include <ctype.h>

int main()
{

    puts("Kontrol edilecek karakteri girin:\n");
    char c = getchar();

     printf("%c:Alfanumerik bir karakter%s\n",c,
           isalnum(c) ? "dir" : " degildir");
     printf("%c:Alfabetik bir karakter%s\n",c,
           isalpha(c) ? "dir" : " degildir");
     printf("%c:Bos bir karakter%s\n",c,
           isblank(c) ? "dir" : " degildir");
     printf("%c:Bir kontrol karakteri(\\n,\\t)%s\n",c,
           iscntrl(c) ? "dir" : " degildir");
     printf("%c:Bir rakam karakter%s\n",c,
           isdigit(c) ? "dir" : " degildir");
     printf("%c:Bir grafik karakter%s\n",c,
           isgraph(c) ? "dir" : " degildir");
     printf("%c:Bir kucuk harf karakter%s\n",c,
           islower(c) ? "dir" : " degildir");
     printf("%c:Bir buyuk harf karakter%s\n",c,
           isupper(c) ? "dir" : " degildir");
     printf("%c:Bir yazdirilabilir karakter%s\n",c,
           isprint(c) ? "dir" : " degildir");
     printf("%c:Bir noktalama isareti karakter%s\n",c,
           ispunct(c) ? "dir" : " degildir");
     printf("%c:Bir bosluk karakter%s\n",c,
           isspace(c) ? "dir" : " degildir");
     printf("%c:Bir hex karakter%s\n",c,
           isxdigit(c) ? "dir" : " degildir");
     printf("%c:buyuk harf hali:%c\n",c,toupper(c));
     printf("%c:kucuk harf hali:%c\n",c,tolower(c));


}

