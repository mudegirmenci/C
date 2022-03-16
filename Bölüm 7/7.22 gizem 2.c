#include<stdio.h>

int gizem(const char *);

int main() {

    char string[80];

    printf("Bir string girini:");
    scanf("%s",string);
    printf("%d\n",gizem(string));

    return 0;
}


int gizem(const char *s){
    int x;
    for(x=0;*s!='\0';s++)
        ++x;

    return x;
}
