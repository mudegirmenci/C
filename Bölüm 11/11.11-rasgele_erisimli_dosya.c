#include<stdio.h>

struct musteriVerisi{
   int hesapNo;
   char soyisim[15];
   char isim[10];
   double bakiye;
};

int main() 
{
   int i;
   struct musteriVerisi bosVeri={0,"","",0.0};
   FILE *dosya;

   if((dosya=fopen("kredi.dat","w"))==NULL)
      printf("Dosya açılamadı\n");
   else{
      for(i=1;i<=100;i++) 
          fwrite(&bosVeri,sizeof(struct musteriVerisi),1,dosya);
      fclose(dosya);
   }
   return 0;
}
