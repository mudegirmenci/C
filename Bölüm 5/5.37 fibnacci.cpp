#include <stdio.h>

int kuvvet(int taban, int us);

int main(){
	printf("%d",kuvvet(2,6));
}

int kuvvet(int taban, int us){
	if(us<1) return 1;
	return (taban*kuvvet(taban,us-1));
}
