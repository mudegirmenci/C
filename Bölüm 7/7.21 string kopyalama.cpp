#include <stdio.h>

void kopya1(char *,const char*);
void kopya2(char *,const char*);
int main() {
	
	char string1[10],*string2="Merhaba",
	string3[10],string4[]="g�le g�le";
	
	kopya1(string1,string2);
	printf("string1=%s\n",string1);
	
	kopya2(string3,string4);
	printf("string1=%s\n",string3);
	
	return 0;
	
}

void kopya1(char *s1,const char*s2){
	for(int i=0;(s1[i]=s2[i])!='\0';i++) ;  //dongu icinde bir�ey yapma.
}


void kopya2(char *s1,const char*s2){
	for(;(*s1=*s2)!='\0';s1++,s2++) ;
}
