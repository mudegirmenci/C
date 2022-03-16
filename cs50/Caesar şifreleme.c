#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,string argv[])
{
    
     // Eğer argv[1] tanımlanmazsa segmentation hatası veriyor.
     if(argv[1]==NULL)
     {
         printf("Usage: ./caesar\n");
         return 1;
     }
     //argüman 1 i int tipine çevir.
    int arguman1=atoi(argv[1]);
    
    //eğer argüman 1-123 arası değilse, argüman sayısı ikiden farklıysa  programdan çık
    if( arguman1<1 || arguman1>123 || argc!=2 ) {
      printf("Usage: ./caesar\n");
      return 1;
  }
    //kullanıcıdan şifrelenecek metni al
   string s=get_string("PLAINTEXT: ");
 
   char ciphertext[100]; 
    
   //metnin karakterlerini teker teker dolaş.strlen string'in kaç karakter olduğunu gösteriyor. 
   for(int i=0;i<strlen(s);i++){
      if(s[i]<='Z' && s[i]>='A')                        //büyük harfse
      /*
        (s[i]+arguman1)-65 ==>0-26 arası bir değer verir. Bu değerin mod 26 sı kaydırılacak harfin kaçıncı olduğunu gösterir. 65 ekleyerek ascii kodunu alırız. Örneğin A harfi 1 birim kaydırmak için (65+1)-65=1  mod 26=1 65 eklenmiş hali 66. ascii 66 B
      */
            ciphertext[i]=((s[i]-'A')+arguman1)%26+'A';   
       else if(s[i]>='a' && s[i]<='z' ) 
            ciphertext[i]=((s[i]-'a')+arguman1)%26+'a';
       else if(s[i]!='\0') ciphertext[i]=s[i];
       else return 0;

     }
   printf("ciphertext: %s\n",ciphertext);
   
}
