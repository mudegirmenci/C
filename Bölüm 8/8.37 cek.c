/* çek koruma */

#include<stdio.h>
#include<string.h>

int main()
{
   char *cek;
   printf("Çek miktarını giriniz: ");
   scanf("%s",cek);
   
   int kacBasamak=strlen(cek);
    
   
   for(int i=0;i<9-kacBasamak;i++)
	printf("*");
 
   printf("%s\n",cek);

   

}
