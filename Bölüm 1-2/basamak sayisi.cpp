#include <stdio.h>
int main()
{
    long long n;
    int count = 0;

    printf("Bir tamsay� girin: ");
    scanf("%lld", &n);

    while(n != 0)
    {
        // n = n/10
        n /= 10;
        ++count;
    }

    printf("Basamak say�s�: %d", count);
}
