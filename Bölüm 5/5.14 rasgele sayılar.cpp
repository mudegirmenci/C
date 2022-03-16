#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rasgele1();
int rasgele2();
int rasgele3();

int main()
{
	srand(time(NULL));
	
	printf("2,4,6,8 kumesinden rasgele bir sayi:%d\n",rasgele1());
	printf("3,5,7,9,11 kumesinden rasgele bir sayi:%d\n",rasgele2());
    printf("6,10,14,18,22 kumesinden rasgele bir sayi:%d\n",rasgele3());

}

int rasgele1(){
	return 2*(1+rand()%4);     //1-4 arası rasgele sayının iki katı 2,4,6,8 kümesini verir.
}
int rasgele2(){
	return 2*(1+rand()%5)+1;     //1-5 arası rasgele sayının iki katının 1 fazlası  3,5,7,9,11  kümesini verir.
}
int rasgele3(){
	return 2*(2*(1+rand()%5)+1);     //1-5 arası rasgele sayının iki katının 1 fazlasının iki katı  6,10,14,18,22 kümesini verir.
}
