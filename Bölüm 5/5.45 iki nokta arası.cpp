#include <stdio.h>
#include <math.h>


/*
iki nokta arasý mesafe bul.(x1,y1)-(x2,y2)

https://www.wikihow.com.tr/%C4%B0ki-Nokta-Aras%C4%B1ndaki-Mesafe-Nas%C4%B1l-Bulunur
*/
float ikiNoktaMesafe(float x1,float x2,float y1,float y2);

int main(){

  printf("Uzaklýk:%f\n",ikiNoktaMesafe(3,7,2,8));

}

float ikiNoktaMesafe(float x1,float x2,float y1,float y2){
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

