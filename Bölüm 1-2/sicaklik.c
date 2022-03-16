// Code 2.4.1: Code2_4_1.c
// Tür Dönüþümü Örneði (Sýcaklýk Birimleri)

#include <stdio.h>

int main()
{
    float fahrenheit, kelvin;

    printf("Lutfen sicakligi Fahrenheit cinsinden girin: ");
    scanf("%f", &fahrenheit);

    float sonucCelcius = (fahrenheit - 32)/1.8;
    printf("Girdiginiz sicakligin Celcius karsiligi: %f\n", sonucCelcius);

    printf("Lutfen sicakligi Kelvin cinsinden girin: ");
    scanf("%f", &kelvin);

    float sonucFahrenheit = (kelvin) * (float)9/5 - 459.67;
    printf("Girdiginiz sicakligin Fahrenheit karsiligi: %f\n", sonucFahrenheit);

    return 0;
}
