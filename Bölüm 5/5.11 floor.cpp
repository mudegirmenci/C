#include <stdio.h>
#include <math.h>

float tamsayiyayuvarla(float sayi);
float onlugayuvarla(float sayi);
float yuzlugeyuvarla(float sayi);
float binligeyuvarla(float sayi);

int main()
{
	float i;
	
	printf("Yuvarlanacak sayi girin(for exit -1):\n");
	scanf("%f",&i);
	printf("Sayi:%f  Tam Sayi Hali:%f\n",i,tamsayiyayuvarla(i));
	printf("Sayi:%f     Onluk Hali:%f\n",i,onlugayuvarla(i));
	printf("Sayi:%f    Yuzluk Hali:%f\n",i,yuzlugeyuvarla(i));
	printf("Sayi:%f    Binlik Hali:%f\n",i,binligeyuvarla(i));
	
	return 0;
}

float tamsayiyayuvarla(float sayi)
{
	 return floor(sayi+0.5);
}
float onlugayuvarla(float sayi)
{
	 return floor(sayi*10+0.50)/10;
}
float yuzlugeyuvarla(float sayi)
{
	 return floor(sayi*100+0.50)/100;
}
float binligeyuvarla(float sayi)
{
	 return floor(sayi*1000+0.50)/1000;
}
