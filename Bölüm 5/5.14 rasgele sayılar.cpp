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
	return 2*(1+rand()%4);     //1-4 aras� rasgele say�n�n iki kat� 2,4,6,8 k�mesini verir.
}
int rasgele2(){
	return 2*(1+rand()%5)+1;     //1-5 aras� rasgele say�n�n iki kat�n�n 1 fazlas�  3,5,7,9,11  k�mesini verir.
}
int rasgele3(){
	return 2*(2*(1+rand()%5)+1);     //1-5 aras� rasgele say�n�n iki kat�n�n 1 fazlas�n�n iki kat�  6,10,14,18,22 k�mesini verir.
}
