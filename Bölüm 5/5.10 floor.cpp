#include <stdio.h>
#include <math.h>

int main()
{
	float i;
	
	printf("Yuvarlanacak sayi girin(for exit -1):\n");
	
	
	while(i!=-1){
		scanf("%f",&i);
	    printf("Sayi:%.2f  Yuvarlanmis Hali:%.2f\n",i,floor(i+0.5));
	
	}
	
	return 0;
}
