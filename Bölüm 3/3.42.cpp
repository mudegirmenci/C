/*
 3.42 bir �emberin yar��ap�n� float t�r�nden alan ve �evre, alan, �ap hesaplayan program
*/
#include<stdio.h>

int main(){
   
   float yaricap=0,pi=3.14159;
   
   printf("Yaricap girin:\n");
   scanf("%f",&yaricap);
   
   printf("Cap: %f\n",yaricap*2);
   printf("Cevre: %f\n",yaricap*2*pi);
   printf("Alan: %f\n",pi*yaricap*yaricap);
   


   return 0;
}
