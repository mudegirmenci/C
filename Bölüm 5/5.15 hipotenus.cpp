#include <stdio.h>
#include <math.h>

double hipotenus(double,double);

int main(){
	printf("Hipotenus:%.2f:\n",hipotenus(8,15));
}
double hipotenus(double kenar1,double kenar2){
	return sqrt(kenar1*kenar1+kenar2*kenar2);
}
