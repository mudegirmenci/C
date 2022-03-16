/*
 * Bu program rasgele erişimli bir dosyayı açar,
 * dosyaya daha önceden yazılmış veriyi günceller,
 * dosyaya yerleştirilecek yeni veriyi oluşturur,
 * ve dosyadan önceden varolan verileri siler
 */

#include<stdio.h>
#include<stdlib.h>
struct musteriVerisi{
   int hesapNo;
   char soyisim[30];
   char isim[20];
   double bakiye;
};

int secimGir(void);
void metinDosyasi(FILE *);
void kayitGuncelle(FILE *);
void yeniKayit(FILE *);
void kayitSil(FILE *);


int main()
{

   FILE *dosya;
   int secim;     

   if((dosya=fopen("kredi.dat","r+"))==NULL)
	   printf("Dosya açılamadı\n");
   else {
      
       while((secim=secimGir())!=5){
          
	       switch(secim) {
		    case 1:
			    metinDosyasi(dosya);
			    break;
		    case 2:
			    kayitGuncelle(dosya);
			    break;
		    case 3:
			    yeniKayit(dosya);
			    break;
		    case 4:
			    kayitSil(dosya);
			    break;
	       }
       }
       fclose(dosya);
   }
   return 0;
}


void metinDosyasi(FILE *okuPtr)
{
   FILE *yazPtr;
   struct musteriVerisi musteri={0,"","",0.0};
   
   if((yazPtr=fopen("hesaplar.txt","w"))==NULL) printf("Dosya açılamadı\n");
   else {
	rewind(okuPtr);
	fprintf(yazPtr,"%-6s%-16s%-11s%10s\n","HesapNo","Soyisim","İsim","Bakiye");
 	do {
	
            fread(&musteri,sizeof(struct musteriVerisi),1,okuPtr);
	    if(musteri.hesapNo!=0)
		    fprintf(yazPtr,"%-6d%-16s%-11s%10.2f\n",musteri.hesapNo,musteri.soyisim,musteri.isim,musteri.bakiye);


	} while(!feof(okuPtr));
	fclose(yazPtr);
   }
}


void kayitGuncelle(FILE *dosya)
{
   int hesap;
   double guncelle;	
   struct musteriVerisi musteri={0,"","",0.0};

   printf("Güncellenecek hesap numarasını giriniz (1-100): ");
   scanf("%d",&hesap);
   fseek(dosya,(hesap-1)*sizeof(struct musteriVerisi),SEEK_SET); //hesap numarasının olduğu kayda gel
   fread(&musteri,sizeof(struct musteriVerisi),1,dosya);         //dosyadan müşteri bilgilerini oku

   if(musteri.hesapNo==0)
	   printf("Hesap #%d hakkında bilgi yok.\n",hesap);
   else {
	   
          printf("%-6d%-16s%-11s%10.2f\n",musteri.hesapNo,musteri.soyisim,musteri.isim,musteri.bakiye);
	  printf("borç(+) ya da ödeme(-) giriniz.\n");
	  scanf("%lf",&guncelle);
	  musteri.bakiye+=guncelle;
          printf("%-6d%-16s%-11s%10.2f\n",musteri.hesapNo,musteri.soyisim,musteri.isim,musteri.bakiye);
          fseek(dosya,(hesap-1)*sizeof(struct musteriVerisi),SEEK_SET); //hesap numarasının olduğu kayda gel
	  fwrite(&musteri,sizeof(struct musteriVerisi),1,dosya);

   }
}

void kayitSil(FILE *dosya)
{
   struct musteriVerisi musteri,bosMusteri={0,"","",0.0};
   int hesapNum;

   printf("Silinecek hesap numarasını giriniz(1-100).\n");
   scanf("%d",&hesapNum);
   fseek(dosya,(hesapNum-1)*sizeof(struct musteriVerisi),SEEK_SET);
   fread(&musteri,sizeof(struct musteriVerisi),1,dosya);

   if(musteri.hesapNo!=0)
	   printf("Hesap #%d bulunamadı.\n",hesapNum);
   else {
          fseek(dosya,(hesapNum-1)*sizeof(struct musteriVerisi),SEEK_SET);
	  fwrite(&bosMusteri,sizeof(struct musteriVerisi),1,dosya);
   }
}


void yeniKayit(FILE *dosya)
{
   int hesapNum;
   struct musteriVerisi musteri={0,"","",0.0};

   printf("Yeni hesap numarasını giriniz (1-100): ");
   scanf("%d",&hesapNum);
   fseek(dosya,(hesapNum-1)*sizeof(struct musteriVerisi),SEEK_SET); //hesap numarasının olduğu kayda gel
   fread(&musteri,sizeof(struct musteriVerisi),1,dosya);         //dosyadan müşteri bilgilerini oku

   if(musteri.hesapNo!=0)
	   printf("Hesap #%d zaten var.\n",hesapNum);
   else {
	   
          printf("Soyisim, isim ve bakiye giriniz\n");
	  scanf("%s%s%lf",&musteri.soyisim,&musteri.isim,&musteri.bakiye);
	  musteri.hesapNo=hesapNum;
          printf("%-6d%-16s%-11s%10.2f\n",musteri.hesapNo,musteri.soyisim,musteri.isim,musteri.bakiye);
          fseek(dosya,(musteri.hesapNo-1)*sizeof(struct musteriVerisi),SEEK_SET); //hesap numarasının olduğu kayda gel
          fwrite(&musteri,sizeof(struct musteriVerisi),1,dosya);
   }
}


int secimGir(void)
{
   int menuGir;

   printf("\nSeçiminiz.\n"
	  "1- Yazdırmak için \n"
	  " \"hesaplar.txt\" adında metin dosyası oluştur\n"
	  "2- Hesap Güncelle \n"
	  "3- Yeni hesap oluştur \n"
	  "4- Hesap Sil \n"
	  "5- Çıkış\n?");
   scanf("%d",&menuGir);
   return menuGir;
}
