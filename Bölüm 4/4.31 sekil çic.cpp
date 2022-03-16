#include<stdio.h>
/*
4.31
bosluk=0, yildiz=1

satir sayýsýný birer birer azaltan en üst döngü 
   eðer satir==5
          bosluk++  ortaya geldiysek boþluk artir
     Deðilse 
          satir -5;  boþluk azalt
    Döngü  bosluk deðiþkeni kadar boþluk ver
    Döngü ile 9-(2*bosluk) adet yýldýz yaz
    Döngü  bosluk deðiþkeni kadar boþluk ver
    
*/
int main()
{
   int bosluk=5,satir,i;
   
   for(satir=9;satir>0;satir--){
   	   if(satir==5)
   	      bosluk=0;
   	   else
   	      bosluk--;
   	    
   	   
   	    for(i=bosluk;i>0;i--)
   	       printf(" ");
   	    for(i=9-(2*bosluk);i>0;i--)
   	       printf("*");
   	    for(i=bosluk;i>0;i--)
   	       printf(" ");
   	    
   	    printf("%d",bosluk);
   	    printf("\n");
   }
   
  

}
