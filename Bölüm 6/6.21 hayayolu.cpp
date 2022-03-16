#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void koltukGoster(int koltuk[],int);
int koltukSec(int,int);

int main() {
	int koltuk[10]={0},bolum=0,rezerve=0;
	srand(time(NULL));
	
   koltukGoster(koltuk,10);
   
   printf("Sigara icilen bolum icin 1 e basiniz:\nSigara icilmeyen bolum icin 2 ye basiniz:\n");
   scanf(" %d",&bolum);
   
   if(bolum==1){
 		for(int i=1;i<=5;i++) {
 			if(koltuk[i]==0) {
 				koltuk[i]=1;
				 break;
				 rezerve=1;
			 }
		 }
		 if(rezerve==0) printf("Uzgunum. Bos koltuk bulamadik.\n");
   }
     if(bolum==2){
 		for(int i=5;i<=10;i++) {
 			if(koltuk[i]==0) {
 				koltuk[i]=1;
				 break;
				 rezerve=1;
			 }
		 }
		 if(rezerve==0) printf("Uzgunum. Bos koltuk bulamadik.\n");
   }  else printf("Yanlis veya hatali secim\n");
   
   koltukGoster(koltuk,10);
   
   return 0;
    
   
}
int koltukSec(int a,int b){
	return a+rand()%b;
}
void koltukGoster(int koltuk[],int a){
	printf("Su anki bos/dolu koltuklar\n");
	for(int i=1;i<=a;i++){
		printf("%2d koltuk %d\n",i,koltuk[i-1]);
	}
}
