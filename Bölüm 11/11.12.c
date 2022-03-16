#include<stdio.h>

void init(FILE *);
int secimGir(void);
void yeniKayit(FILE *);
void kayitListele(FILE *);
void kayitGuncelle(FILE *);
void kayitSil(FILE *);

struct envanterVerisi{
   int kayitNo;
   char urun[100];
   int miktar;
   double fiyat;
};


int main()
{
   int secim;
   FILE *dosya;
 
   if((dosya=fopen("hirdavat.dat","r+"))==NULL)
      printf("Dosya açılamadı\n");

   else {

	   while((secim=secimGir())!=5){
		
	       switch(secim){
    	           case 0:    
		     init(dosya);
	  	     break;	     
		   case 1:
		     kayitListele(dosya);
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

/* dosyayı ilk kullanım için hazırlar. 
 * dosyaya 1-100 arası kayıt numaraları ile boş veri doldurur.
 * eğer dosya varsa içeriğini tamamen siler.
 * */
void init(FILE *dosya)
{
   struct envanterVerisi bosVeri={0,"",0,0.0};

   if((dosya=fopen("hirdavat.dat","w+"))==NULL)
      printf("Dosya açılamadı\n");
   else {
       for(int i=1;i<=100;i++)
           fwrite(&bosVeri,sizeof(struct envanterVerisi),1,dosya);

       fclose(dosya);
   }
}


int secimGir(void)
{
   int menuSec;

   printf("\n#### Seçiminiz.#### \n"
	  "0-Dosyayı ilk kullanım için hazırla(DİKKAT! Bütün içerik silinir)\n"
	  "1-Envanter listesini yazdırmak için \n"
	  "2-Kayıtları güncelle\n"
	  "3-Yeni kayıt ekle\n"
	  "4-Kayıt sil\n"
	  "5-Çıkış\n");
   scanf("%d",&menuSec);
   return menuSec;

}

void kayitListele(FILE *dosya)
{
   
   struct envanterVerisi envanter={0,"",0,0.0};
  
   fseek(dosya,0,SEEK_SET);  
   printf("%-6s%-30s%-10s%10s\n","ID","Ürün Adı","Miktar","Fiyat");
   
   while(!feof(dosya)) {
      fread(&envanter,sizeof(struct envanterVerisi),1,dosya);
      if(envanter.kayitNo!=0)
       printf("%-6d%-30s%-6d%10.2lf\n",envanter.kayitNo,envanter.urun,envanter.miktar,envanter.fiyat);
   }
}


void yeniKayit(FILE *dosya) 
{

   struct envanterVerisi envanter={0,"",0,0.0};
   int id;
      printf("####  Kayıt Numarası Giriniz: "
	    "(1 den 100 e kadar, çıkış için 0) \n?");
      scanf("%d",&id);
      fseek(dosya,(id-1)*sizeof(struct envanterVerisi),SEEK_SET);  
      fread(&envanter,sizeof(struct envanterVerisi),1,dosya);

       if(envanter.kayitNo!=0) 
	   printf("#### Kayıt #%d zaten mevcut\n",envanter.kayitNo);    
       else {
	   printf("#### Ürün adı,miktarı ve fiyatı giriniz:\n?");
	   scanf("%s%d%lf",&envanter.urun,&envanter.miktar,&envanter.fiyat);   
           envanter.kayitNo=id;
	   fseek(dosya,(envanter.kayitNo-1)*sizeof(struct envanterVerisi),SEEK_SET);  
           fwrite(&envanter,sizeof(struct envanterVerisi),1,dosya);
       }
	   
	   
	 
}

void kayitGuncelle(FILE *dosya)
{
   int kayit,secim,miktar;
   double fiyat;
   char isim[100];
   struct envanterVerisi envanter={0,"",0,0.0};

   printf("#### Güncellenecek kayıt numarasını girin:\n");
   scanf("%d",&kayit);
   fseek(dosya,(kayit-1)*sizeof(struct envanterVerisi),SEEK_SET);
   fread(&envanter,sizeof(struct envanterVerisi),1,dosya);
  
   if(envanter.kayitNo==0)
       printf("#### Kayit #%d hakkında bilgi yok.\n");
   else {
       printf("%-6d%-30s%-6d%10.2lf\n",envanter.kayitNo,envanter.urun,envanter.miktar,envanter.fiyat);
       printf("####  Değiştirmek istediğiniz kaydı seçin\n"
  	      "1-Ürün Adı\n"
	      "2-Ürün Miktarı\n"
	      "3-Ürün Fiyatı\n");
       scanf("%d",&secim);
       switch(secim) {
	case 1:
		printf("#### Yeni ismi giriniz: ");
		scanf("%s",&envanter.urun);
		fseek(dosya,(kayit-1)*sizeof(struct envanterVerisi),SEEK_SET);
		fwrite(&envanter,sizeof(struct envanterVerisi),1,dosya);
                printf("%-6d%-30s%-6d%10.2lf\n",envanter.kayitNo,envanter.urun,envanter.miktar,envanter.fiyat);
		break;
	case 2:
		printf("#### Yeni miktar: ");
		scanf("%d",&miktar);
		envanter.miktar=miktar;
		fwrite(&envanter,sizeof(struct envanterVerisi),1,dosya);
		fseek(dosya,(kayit-1)*sizeof(struct envanterVerisi),SEEK_SET);
		printf("%-6d%-30s%-6d%10.2lf\n",envanter.kayitNo,envanter.urun,envanter.miktar,envanter.fiyat);
		break;
	case 3:
		printf("#### Yeni fiyat giriniz: ");
		scanf("%lf",&fiyat);
		envanter.fiyat=fiyat;
		fwrite(&envanter,sizeof(struct envanterVerisi),1,dosya);
		fseek(dosya,(kayit-1)*sizeof(struct envanterVerisi),SEEK_SET);
                printf("%-6d%-30s%-6d%10.2lf\n",envanter.kayitNo,envanter.urun,envanter.miktar,envanter.fiyat);
		break;
       }
       
   }
}

void kayitSil(FILE *dosya)
{
	struct envanterVerisi envanter,bosVeri={0,"",0,0.0};
	int kayitNo;

	printf("Silinecek kayıt numarasını girin\n");
	scanf("%d",&kayitNo);
	fseek(dosya,(kayitNo-1)*sizeof(struct envanterVerisi),SEEK_SET);
	fread(&envanter,sizeof(struct envanterVerisi),1,dosya);

	if(envanter.kayitNo==0)
		printf("Kayıt #%d bulunamadı.\n",envanter.kayitNo);
	else {
	      	fseek(dosya,(kayitNo-1)*sizeof(struct envanterVerisi),SEEK_SET);
		fwrite(&bosVeri,sizeof(struct envanterVerisi),1,dosya);
	}
}

