/*

Enter bas�l�ncaya kadar s[100] karakter dizisine metin giri�i
yapt�rmak.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[100],c;
    int i=0;

    while((c=getchar())!='\n'){
        s[i++] = toupper(c);

    }
   s[i] = '\0';
    puts(s);

    return 0;
}
