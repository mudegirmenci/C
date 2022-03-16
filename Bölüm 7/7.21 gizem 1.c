#include<stdio.h>

void gizem(char *, const char *);

int main() {

    char string1[80],string2[80];

    printf("Ýki string girini:");
    scanf("%s%s",string1,string2);
    gizem(string1,string2);
    printf("%s\n",string1);

    return 0;
}


void gizem(char *s1, const char *s2){
    while(*s1!='\0') {
        ++s1;
        printf("%p-%c\n",s1,*s1);
    }

    for(;*s1=*s2;s1++,s2++)
        printf("*s1:%c *s2:%c\n",*s1,*s2);
}
