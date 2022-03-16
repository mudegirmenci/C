#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	printf("1<n<2 arasi rasgele bir sayi:%.2f\n",1+((float)rand()/(float)(RAND_MAX) ));
	printf("1<n<100 arasi rasgele bir sayi:%d\n",1+rand()%100);	
	printf("0<n<9 arasi rasgele bir sayi:%d\n",1+rand()%9);
	printf("1000<n<1012 arasi rasgele bir sayi:%d\n",1001+rand()%11);
	printf("-1<n<1 arasi rasgele bir sayi:%f\n",-1+((float)rand()/RAND_MAX)*2);
	printf("-3<n<11 arasi rasgele bir sayi:%f\n",-1+((float)rand()/RAND_MAX)*13);
	return 0;
}
