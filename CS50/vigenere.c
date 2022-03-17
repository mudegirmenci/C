#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    
     // Eğer argv[1] tanımlanmazsa segmentation hatası veriyor.
     if(argv[1]==NULL)
     {
         printf("Usage: ./caesar\n");
         return 1;
     }
	 
     //arg1 dizi boyutunu belirt. Bütün elemanları sıfırlar.(aksi durumda cs50 HATA üretiyor. )
    char arg1[100]={0};
    //1. argüman olarak girilen kelimeyi arg1 dizisine al
   for(int i=0;strlen(argv[1])>i;i++){
       arg1[i]=argv[1][i]; 
       //printf("test:%c count%lu\n",arg1[i],strlen(arg1));
   }
  
   //tek argüman ve sadece alfabetik kelime istiyoruz.
    for(int i=0;i<strlen(arg1);i++){
        if( !isalpha(arg1[i]) || argc!=2 ) {
            printf("Usage: ./caesar\n");
            return 1;
         }
    }
 
    //kullanıcıdan şifrelenecek metni al
   string s=get_string("PLAINTEXT: ");
 
   char ciphertext[100]={0}; 
   int sayac=strlen(arg1);
 
 //metnin karakterlerini teker teker dolaş.strlen string'in kaç karakter olduğunu gösteriyor. 
  int key=0;
   for(int i=0;i<strlen(s);i++){
        if(sayac==strlen(arg1)) sayac=0;
        if(arg1[sayac]<=90 && s[i]>=90) key=arg1[sayac]+32;   //key büyük karakter, metin küçük karakter olunca oluşan sorunu düzeltmek için
        else key=arg1[sayac];

        if(s[i]<91 && s[i]>64)  {                      //büyük harfse
             ciphertext[i]=((s[i]+arg1[sayac])-130)%26+65;   
             sayac++;
        }
       else if(s[i]>=97 && s[i]<=123 )  {
            ciphertext[i]=((s[i]+key)-194)%26+97;
            sayac++;
       } else if(s[i]!='\0') ciphertext[i]=s[i];
	   
    }

	 printf("ciphertext: %s\n",ciphertext);
	return 0;
   
}
