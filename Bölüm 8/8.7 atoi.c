#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("4 tam sayi girin:");

    char s1[10],s2[10],s3[10],s4[10];

    scanf("%s%s%s%s",s1,s2,s3,s4);

    printf("toplam:%d\n",atoi(s1)+atoi(s2)+atoi(s3)+atoi(s4));
}
