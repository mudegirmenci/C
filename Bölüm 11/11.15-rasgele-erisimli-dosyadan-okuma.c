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
   struct musteriVerisi musteri={0,"","",0.0};
   FILE *dosya;

   if((dosya=fopen("kredi.dat","r"))==NULL)
      printf("Dosya açılamadı\n");
   else{
      printf("%-6s%-16s%-11s%10s\n","HspNo","Soyisim","İsim","Bakiye");

      while(!feof(dosya)) {

	/* fread;dosya işaretcisinin işaret ettiği dosyadan ikinci parametre boyutunda aldığı 1 veriyi, musteri yapısına depolar.*/
        fread(&musteri,sizeof(struct musteriVerisi),1,dosya);
	
	if(musteri.hesapNo!=0)
            printf("%-6d%-16s%-11s%10.2f\n",musteri.hesapNo,musteri.soyisim,musteri.isim,musteri.bakiye);
      }
	   
	   
	 fclose(dosya);
   }
   return 0;
}
