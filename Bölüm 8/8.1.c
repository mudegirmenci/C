#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char c='a';
    int x=6,y=70,z=9;
    float d,e,f;
    char *ptr;
    char s1[100]="mustafa";
    char s2[200]="gýda";

    /* Büyük harf çevirme */
    c = toupper(c);
    printf("%c\n",c);


    printf("%s %s\n","c kontrol:",
            isdigit(c) ? "c bir sayý\n" : "c bir sayi degil\n"
           );

    printf("%s %s\n","c kontrol:",
            iscntrl(c) ? "c bir kontrol karakteri\n" : "c bir kontrol karakteri degil\n"
           );

     printf("%s %s\n","c kontrol:",
            isalpha(c) ? "c bir harf\n" : "c bir harf degil\n"
           );

    printf("%s %s\n","c kontrol:",
            isprint(c) ? "c bir yazi karakteri\n" : "c bir yazi karakteri degil\n"
           );


    /*  strtol ile string-long dönüþüm iþlemleri */
    const char *string="1234567 mustafa";
    x = strtol(string,&ptr,0);
    printf("%ld %s\n",x,ptr);



    /* c deðiþkeninin s1 içerisinde en son bulunduðu konumu ptr ye ata */
    c='a';
    printf("'%c'%s\n%s\n",
           c," karakterinin son gorundugu yerden itibaren s1",
           strrchr(s1,c)
           );

    putchar(c);
    printf("\n");

    /*  strtod ile string-double dönüþüm iþlemleri */
    const char *string2="8.63582 mustafa";
    double g = strtod(string2,&ptr);
    printf("%ld %s\n",g,ptr);

    c = getchar();
    putchar(c);
    printf("\n");

    const char *cp1 = "Bilgisayar";
    const char *cp2 = "sayar";

    ptr = strstr(cp1,cp2);

     printf("%s%s\n%s%s\n%s\n%s\n",
           "s1=",cp1,"s2=",cp2,
           "s1 de s2 nin ilk görüldüðü yerden itibaren s1:",
           ptr
           );


    sscanf("1.27 20.3 9.432","%f %f %f",&d,&e,&f);
    printf("%f %f %f\n",d,e,f);


//   printf("%s%s\n%s%s\n%s\n","s1=",s1,"s2=",s2,strcpy(s1,s2) );

    ptr = strpbrk(s1,s2);
    printf("%c\n",*ptr);

    printf("%d\n",strcmp(s1,s2));

     ptr = strchr(s1,c);
    printf("%c\n",*ptr);


    strncat(s1,s2,10);
    printf("%s\n",s1);
}
