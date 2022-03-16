#include <stdio.h>
#include <string.h>

int palindrom(char kelime[],int n,int index);

int main() {
	char kelime[100]="iki radar iki",copy[100];
	
	//varsa string i boþluklardan temizle
	for(int i=0,j=0;kelime[i]!='\0';i++){
		if(kelime[i]!=' ')	
			copy[j++]=kelime[i];
	}
	
	for(int i,j=strlen(copy);i<j;i++)
		printf("%c",copy[i]);
		
	printf("\n");
	
	if(palindrom(copy,strlen(copy)-1,0)==1)
		printf("Kelime bir palindrom\n");
	else printf("Kelime bir palindrom degil\n");

}

int palindrom(char kelime[],int n,int index) {
	
	if(kelime[index]!=kelime[n]) return 0;
	 
	 	 
	if(index<=n) return palindrom(kelime,n-1,index+1);
	 return 1;
	
}
