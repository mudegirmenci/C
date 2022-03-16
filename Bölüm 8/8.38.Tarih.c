
/*
 06/21/55 şeklinde verilen bir tarihi, Haziran 21,1955 şeklinde çeviren bir
program yazın.

1. Verilen stringin ilk iki karakterini al ve 1-12 arasında ise
   ay bilgisini belirleyip, geçici string değişkenine ata.
2. stringin 4. ve 5. karakterlerini gün bilgisi olarak al.
3. 7. ve 8. karakterleri al ve 19 ile birleştirip tarih olarak 
geçici değişkene ata.


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
   char *s="04/21/55",ay[10];

   int i=atoi(s);

printf("%d\n",i);

   switch(i) {
      case 1:
         strcpy(ay,"Ocak");
         break;
      case 2:
         strcpy(ay,"Ocak");
 	 break;
      case 3:
         strcpy(ay,"Ocak");
	break;
      case 4:
         strcpy(ay,"Ocak");
	break;
      case 5:
         strcpy(ay,"Ocak");
	break;
	default:
	break;
   }

  printf("%s %c%c 19%c%c",ay,s[3],s[4],s[6],s[7]);
}
