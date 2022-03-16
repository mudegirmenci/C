/*
string karþýlaþtýrma fonksiyonlarý
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcmp(const char *s1,const char *s2);
char *mystrncmp(const char *s1,const char *s2,size_t n);


int main()
{
   char s1[100] = "String";
   char s2[100] ="Stringhj";

   strcmp(s1,s2);
   printf("%d\n",  mystrcmp(s1,s2));

    printf("%d\n",mystrncmp(s1,s2,6));


}

char *mystrcmp(const char *s1,const char *s2)
{
    int a=0,b=0;
    for(;(*s1!='\0' || *s2!='\0');s1++,s2++) {
        a+=*s1;
        b+=*s2;
    }
  if(a==b) return 0;
  else if(a<b) return -1;
  else return 1;
}

char *mystrncmp(const char *s1,const char *s2,size_t n)
{
    int a=0,b=0;
    for(int i=n-1;(*s1!='\0' || *s2!='\0'),i>=0;i--,s1++,s2++) {
        a+=*s1;
        b+=*s2;
    }
  if(a==b) return 0;
  else if(a<b) return -1;
  else return 1;
}

