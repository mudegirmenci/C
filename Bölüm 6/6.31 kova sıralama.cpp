#include <stdio.h>
#define N 20

void kovaSiralama(int dizi[],int elemanSayisi);
void diziYazdir(const int dizi[9][N]);


int main(){
	int dizi[]={20,25,65,42,20,1,3,8,98,10,
				87,45,23,51,41,12,32,26,16,19};
				
	kovaSiralama(dizi,N);
}

void kovaSiralama(int dizi[],int n) {

		int kova[10][19]={0};
	
	
		for(int i=0,j=0;i<n;i++){
			j=dizi[i]%10;
			kova[j][i]=dizi[i];
		}
	
	
		for(int i=0,sayac=1;i<10;i++) {
		   printf("%\n");
		   for(int j=0;j<n-1;j++){
		   	 	printf("%3d",kova[i][j]);
		   	  sayac++;
	  		 }
		 }
	
	
}


