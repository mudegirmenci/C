#include <stdio.h>

void sekilCiz(int);
int main(){

  int kenar;
  printf("Kenar Girin:\n");
  scanf("%d",&kenar);
  
  sekilCiz(kenar);
}

void sekilCiz(int kenar){
	for(int i=kenar*kenar;i>0;i--){
		if(i%kenar==0)
			printf("\n");
	   printf("%10*");
	}
}
