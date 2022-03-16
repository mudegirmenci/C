#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>
#include <unistd.h>
/*
1.Kullanıcı hash değeri 1. argüman olarak girmeli. 
2.1. arguman boş veya daha fazla arguman varsa hata ver ve 1. adıma dön.
3. Şifrelerin 5 karakterden uzun olmadığını varsayıyoruz.
4. Her parola tamamen alfabetik karakter olduğunu varsayıyoruz.
5. Girilen hash kodundan ilk iki karakteri "salt" oldukları için çıkar ve geriye kalan temiz hash kod olsun.
6. Alfabenin her bir karakterini(büyük/küçük) hash'le ve girilen hash ile karşılaştır. Eğer eşleşme varsa şifremiz budur, yoksa ikinci, üçüncü..beşinci 
karakterlere kadar denemeye devam et. Örneğin: abcd..ABC..Z denedik ve şifreyi bulamadık. Bu durumda ab,ac,ad,..aB...aZ olacak şekilde şifrelerin
hash değerlerini üretip girilen hash ile karşılaştırıyoruz. Doğru sonucu bulana kadar döngü devam ediyor. 
Bes karakterli bütün kombinasyonları şifre olarak dene ve her bir şifrenin hash 
değerini oluştur.
7. eğer eşleşme olursa şifreyi ekrana yazdır

EK BİLGİLER:
-salt, hash sonucunu brute force ataklarına karı korumak için hash'e eklenen rasgele sahte karakterlerdir. Genellikle hash'in ilk iki karakteri salt olur.
-Her bir parolanın C’nin DES tabanlı (MD5 tabanlı değil) crypt fonksiyonuyla hashlendiğini varsayın.
-Her parolanın tamamen alfabetik karakterlerden (büyük ve / veya küçük) oluştuğunu varsayalım.
-crypt("LOL","50") fonksiyonu 50cI2vYkF0YU2 şeklinde hash üretir. crypt ilk argüman şifrelenecek metin, ikinci argüman iki karakter salt değeri alır.
-strcmp fonksiyonu string.h içinde, iki dizi eşitse 0 döndürür.
// Cracked passwords:
//
// anushree:50xcIMJ0y.RXo => YES
// brian:50mjprEcqC/ts => CA
// bjbrown:50GApilQSG3E2 => UPenn
// lloyd:50n0AAUD.pL8g => lloyd
// malan:50CcfIk1QrPr6 => maybe
// maria:509nVI8B9VfuA => TF
// natmelo:50JIIyhDORqMU => nope
// rob:50JGnXUgaafgc => ROFL
// stelios:51u8F0dkeDSbY => NO
// zamyla:50cI2vYkF0YU2 => LOL

/**
 * Here's how the algorithm progresses in 5 steps.
 * X is a letter placeholder, \0 is a null character.
 * 5 lines = 5 loops
 *
 *    1 2 3 4 5 6
 * 1) X\0\0\0\0\0
 * 2) X X\0\0\0\0
 * 3) X X X\0\0\0
 * 4) X X X X\0\0
 * 5) X X X X X\0
 
*/


int main(int argc,string argv[])
{
    
     // Eğer argv[1] tanımlanmazsa segmentation hatası veriyor.
	 //Programınız herhangi bir komut satırı argümanı olmadan veya birden fazla komut satırı argümanı ile yürütüldüyse, programınız bir hata (sizin seçtiğiniz) yazdırmalı ve hemen main geriye 1 döndürmelidir. (böylece bir hata belirtmiş oluruz).
     if(argv[1]==NULL || argc!=2)
     {
         printf("Arguman Hatası:\n");
         return 1;
     }
	 
     //arg1 dizi boyutunu belirt. Bütün elemanları sıfırlar.(aksi durumda cs50 HATA üretiyor. )
    char arg1[100]={0};
	char salt[2]={0};
    //1. argüman olarak girilen kelimeyi arg1 dizisine al
	//ilk iki karakteri sil(salt) (i+2) ile
   for(int i=0;strlen(argv[1])>i;i++){
       arg1[i]=argv[1][i]; 
	   if(i<2) salt[i]=arg1[i];
   }

   char hash[100]={'\0'};
   char password[6]={'\0'};    //Şifre 5 haneli. Son hane bitiş karakteri
    // TODO: possible improvement => https://en.wikipedia.org/wiki/Letter_frequency
   string harfler = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int harfSayisi=53;
   
   //test printf("harf sayısı:%d  hash:%s\n",harfSayisi,crypt("ABC","50"));
   
   //1 harfli kelimeden 5 harfli kelimelere bütün varyasyonları dene.
   
   for(int bes=0;bes<harfSayisi;bes++){
      for(int dort=0;dort<harfSayisi;dort++){
	     for(int uc=0;uc<harfSayisi;uc++) {
		    for(int iki=0;iki<harfSayisi;iki++) {
               for(int bir=1;bir<harfSayisi;bir++){
	              password[0]=harfler[bir];
		          password[1]=harfler[iki];
				  password[2]=harfler[uc];
				  password[3]=harfler[dort];
				  password[4]=harfler[bes];
				  
				  printf("password hash:%s\t Password:%s\n",crypt(password,salt),password);
				  //test için:1 saniye bekle ekranı temizle. sleep() için #include <unistd.h>
				  sleep(1);
                  system("clear");
				  
				  if(strcmp(arg1,crypt(password,salt))==0){
                       printf("Password is found!:%s\n",password);
                       return 0; 
                  } 
			   }  
            }
         }
      }
   } //end first for
   
    printf("Password couldn't be cracked!");
	
   //test printf("password hash:%s\t Password:%s\n",crypt(password,salt),password);
} //end main



