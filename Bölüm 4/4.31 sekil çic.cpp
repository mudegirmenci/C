#include<stdio.h>
/*
4.31
bosluk=0, yildiz=1

satir say�s�n� birer birer azaltan en �st d�ng� 
   e�er satir==5
          bosluk++  ortaya geldiysek bo�luk artir
     De�ilse 
          satir -5;  bo�luk azalt
    D�ng�  bosluk de�i�keni kadar bo�luk ver
    D�ng� ile 9-(2*bosluk) adet y�ld�z yaz
    D�ng�  bosluk de�i�keni kadar bo�luk ver
    
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
