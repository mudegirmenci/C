#include <stdio.h>
#include <string.h>
void mukemmel(int sayi);

int main()
{
	for(int i=2;i<=10000;i++){
		mukemmel(i);
		
	}
}

void mukemmel(int sayi){
	
	int toplam=1;
	long carpan[200]={'\0'};
	carpan[0]=1;
	
	for(int i=2,j=1;i<sayi;i++){
		if(sayi%i==0){
	      toplam+=i;
	       carpan[j]=i;
		   j++;
	   }
	}
	if(toplam==sayi) {
	   printf("%d bir mukemmel sayi, carpanlari:\n",sayi);
	   for(int i=0;carpan[i]!='\0';i++)
	       printf("%d.carpan=%d\n",i,carpan[i]);
   }
}
