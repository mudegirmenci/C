#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];

    puts("iki string giriniz:");

    gets(s1);
    gets(s2);

    printf("%s\n",strncmp(s1,s2,2)==0 ? "stringler ayni" : "stringler farkli");

}
