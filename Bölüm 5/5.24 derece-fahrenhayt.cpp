#include <stdio.h>

/*
 0,556 derece 1 F eþittir.
 F=(C*1,8)+32
 C=(F-32)/1,8
*/
float derece(float);
float fahrenhayt(float);

int main(){
     printf("0-100 arasý derecelerin fahrenhayt olarak gosterimi:\n");
     for(int i=0;i<=100;i++){
     	if(i%6==0) printf("\n");
     	printf("%-2dC=%7.3fF  ",i,fahrenhayt(i));
	 }
	 printf("\n");
	  printf("2-212 arasý fahrenhayt derece olarak gosterimi:\n");
     for(int i=2;i<=212;i++){
     	if(i%6==0) printf("\n");
     	printf("%-3dF=%7.3fC  ",i,derece(i));
	 }
}

//fahrenhayt ý derece dönüþtürür.
float derece(float a){
	return (a-32)*10/18;
}

//dereceyi fahrenhayt'a dönüþtürür.
float fahrenhayt(float a){
	return (a*18/10)+32;
}
