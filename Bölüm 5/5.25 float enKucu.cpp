#include <stdio.h>

/*
float tipinde üç sayýnýn en küçüðü
*/

float enKucuk(float,float,float);

int main(){
	printf("%.3f\n",enKucuk(4.4,2.3,2.1));
}

//float tipinde 3 sayýnýn en küçüðü

float enKucuk(float a,float b, float c){
	float enKucuk;
	
	if(a<b && a<c) enKucuk=a;
	else if(b<c && b<a) enKucuk=b;
	else enKucuk=c;
	
	return enKucuk;
}
