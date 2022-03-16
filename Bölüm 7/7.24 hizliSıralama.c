#include <stdio.h>

void hizliSiralama(int dizi[],int sol,int sag);
int takas(int dizi[],int sol,int sag);
int main() {

    int dizi[15]={37,2,6,4,89,8,10,12,68,45,-9,0,458,1,-3};

    hizliSiralama(dizi,0,15);

    for(int i=0;i<15;i++)
        printf("%4d",dizi[i]);
}

void hizliSiralama(int dizi[],int sol,int sag) {

    int pivotKonumu=0;
    if(sol<=sag)                                             //eğer sağ=sol ise eleman sayısı 1 demektir. Aranacak değer kalmadı, dizi sıralandı.
    {
        pivotKonumu=takas(dizi,sol,sag);                    // Yenilenmiş dizide orta sayı nerede?
        hizliSiralama(dizi,sol,pivotKonumu-1);              // dizinin en solundan başlayarak pivotun bir soluna kadar olan SOL diziyi sırala
        hizliSiralama(dizi,pivotKonumu+1,sag);              // pivot konumunun bir sağından başlayarak SAĞ bölümün sonuna kadar olan ikinci diziyi sırala.

    }

/*
 hizliSiralama fonksiyonunda, soldaki sayılar sağdaki sayılardan küçük olduğu sürece.

 - Takas dizi, dizi değerinin başladığı son ve sonlandığı sağ parametlerini alır.
 - pivot olarak ilk eleman, son eleman veya rasgele seçilen bir eleman alınması sonucu etkilemez.
 - toplam 15 sayılık bir dizi sıralanacak diyelim. Dizinin sonundan başlayarak elemanların pivot değer olan 37 den büyük olup olmadığına bakıyor.
 - -3 37 den büyük mü? Hayır
 -  1 37 den büyük mü? Hayır
 -  458 37 den büyük mü? Evet.
     458 j değişkeninin işaret ettiği yerde. i değişkeni ise -3 ün sağında, yani 14+1=15. indiste ilk konumu.
     şimdi i değişkenini 1 azaltıp dizinin son elemanına denk gelecek şekilde ayarlıyoruz. Artık j nin işaret ettiği değerle
     i nin işaret ettiği değeri yer değiştirebiliriz. Yani 458 ve -3 ün yerleri değişti.
 -  j ile sola kayarak pivottan büyük değerler aramaya devam et, ta ki pivot değere dayanana kadar. i ise sadece j pivottan
    büyük bir değer bulduğunda bir sola kaysın. Bu şekilde pivottan büyük değerler sağ tarafta, küçükler ise sol tarafta yuvalanmış olacak.
    j nin işi de bitince for döngüsü bitmiş olacak. Artık pivot değeri kendi yerine koyabiliriz, yani sol ve sağ yığınların ortasına.
    Bunu yapmak için, i nin nerede durduğunu anlamak önemli. i şu anda en son pivottan büyük sayının takas edilği noktada
    bu noktanın bir basamak solunda ise pivottan küçük sayılar başlıyor. İşte biz pivot değerimizi i nin şu an olduğu konumun bir solundaki
    değerle takas ediyoruz. Yani i-1 ile. Böylece pivot ait olduğu yere gelmiş oluyor.
-  return i-1 ile pivot değerimizin konum bilgisini gönderiyoruz. Böylece hizliSiralama fonksiyonu sağ ve sol taraflarda oluşan dizileri
    ayrı ayrı ele alabilecek.


*/
}
//int dizi[10]={37,2,6,4,89,8,10,12,68,45,-9,0,458,1,-3};
int takas(int dizi[],int sol,int sag)
{
       int i,j,temp,pivot=dizi[sol];

        for(i=sag+1,j=sag;j>sol;j--) {
            if(dizi[j]>pivot) {
                i--;
                temp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=temp;

              }
          }

          temp=dizi[i-1];
          dizi[i-1] = dizi[sol];
          dizi[sol] = temp;

      return i-1;

}

