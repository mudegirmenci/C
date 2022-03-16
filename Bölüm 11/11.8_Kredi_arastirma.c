#include<stdio.h>

int main()
{
   int secim,hesap;
   double bakiye;
   char isim[30];
   FILE *dosya;

   if((dosya=fopen("musteri.dat","r"))==NULL) printf("Dosya açılamdı\n");
   else {
       printf("Seçiminiz: \n"
	      "1- Sıfır bakiyesi olan hesapları listele \n"
	      "2- Kredili hesapları listele \n"
	      "3- Borcu olan hesapları listele \n"
	      "4- Çıkış \n?");
       scanf("%d",&secim);

       while(secim!=4) {
	   fscanf(dosya,"%d%s%lf",&hesap,isim,&bakiye);

	   switch(secim){
	      case 1:
		      printf("\nSıfır bakiyesi olan hesaplar:\n");

		      while(!feof(dosya)) {
 		         
			      if(bakiye==0)
				      printf("%-10d%-13s%7.2lf\n", hesap,isim,bakiye);
			      	fscanf(dosya,"%d%s%d",&hesap,isim,&bakiye);
		      }
		      break;
	
	      case 2:
		      printf("\nKredili hesapları listele:\n");

		      while(!feof(dosya)) {
 		         
			      if(bakiye<0)
				      printf("%-10d%-13s%7.2lf\n", hesap,isim,bakiye);
			      	fscanf(dosya,"%d%s%d",&hesap,isim,&bakiye);
		      }
		      break;
	      case 3:
		      printf("\nBorcu olan hesaplar:\n");

		      while(!feof(dosya)) {
 		         
			      if(bakiye>0)
				      printf("%-10d%-13s%7.2lf\n", hesap,isim,bakiye);
			      	fscanf(dosya,"%d%s%d",&hesap,isim,&bakiye);
		      }
		      break;
	   }//end of switch

	   rewind(dosya); //dosya işaretçisini dosya başına al
	   printf("?\n");
	   scanf("%d",&secim);
       }//end of while

       printf("Çıkış \n");
       fclose(dosya);

   } //end of else

   return 0;

} //end main
