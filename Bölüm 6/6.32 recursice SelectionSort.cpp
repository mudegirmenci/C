#include <stdio.h>
#define N 30
void selectionSort(int dizi[],int n,int baslangic);


int main(){
	int dizi[]={20,25,65,42,20,1,3,8,98,10,
				87,45,23,51,41,12,32,26,16,19,
				15,2,0,3,65,95,798,154,54,51};
				
				
	//sýralanacak dizi,dizi eleman sayýsý, dizi baþlangýç indis(varsayýlan olarak 0)
	selectionSort(dizi,N,0);
	
	for(int i=0;i<N;i++)
		printf("%4d",dizi[i]);
}

void selectionSort(int dizi[],int n,int baslangic=0){
	int temp=0;
	for(int i=baslangic;i<n;i++){
	   if(dizi[i]<dizi[baslangic]){
		   temp=dizi[baslangic];
		   dizi[baslangic]=dizi[i]; 
		   dizi[i]=temp;
	   }
   }
   printf("baslangic:%d\n",baslangic);
   if(baslangic<n-1)
   	selectionSort(dizi,n,++baslangic);
   
}
