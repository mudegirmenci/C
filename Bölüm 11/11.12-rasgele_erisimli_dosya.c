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

   if((dosya=fopen("kredi.dat","r+"))==NULL)
      printf("Dosya açılamadı\n");
   else{
      printf("Hesap Numarasını Girininz: "
	    "(1 den 100 e kadar, çıkış için 0) \n?");
      scanf("%d",&musteri.hesapNo);

      while(musteri.hesapNo!=0) {
	   printf("soyisim,isim,bakiye giriniz:\n?");
	   fscanf(stdin,"%s%s%lf",musteri.soyisim,musteri.isim,&musteri.bakiye);    //standart girişten bilgileri al ve struct elemanlarına geçir
	   /* Dosya göstericisindeki dosya işaretçisini, ikinci argümanla hesaplanan byte konumuna taşır.
	    * Bu deyime genellikle offset denir.
	    * byte konumları 0 ile başladığından ve hespaNo 1 ile başladığından
	    * kayıt 1 için dosya pozisyon göstericisi 0. konuma taşınır.
	    * SEEK_SET sembolik sabiti, dosya pozisyon göstericisinin yer değiştirmesinin dosyanın başındaki konumdan itibaren 
	    * yapılacağını belirtir.
	    * 100 kayıt için toplam dosya büyüklüğü 99*sizeof(struct musteriVerisi) kadardır.
	    * fseek prototipi: int fseek(FILE *stream, long int offset, int whence)
	    * offset, stream ile belirtilen dosyadaki whence konumundan itibaren byte sayısıdır.
	    * whence değerleri:
	    * SEEK_SET: Dosya başından
	    * SEEK_CUR: Dosyanın o anki konumundan
	    * SEEK_END: Dosyanın sonundan başlanacağını belirtir.  */
	   fseek(dosya,(musteri.hesapNo-1)*sizeof(struct musteriVerisi),SEEK_SET);  //dosya işaretçicisini ayarlar.
	   fwrite(&musteri,sizeof(struct musteriVerisi),1,dosya);
	   printf("Hesap Numarasını Giriniz: \n?");
	   scanf("%d",&musteri.hesapNo);
      }
	   
	   
	 fclose(dosya);
   }
   return 0;
}
