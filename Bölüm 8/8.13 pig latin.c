/*

strtok için görsel nasýl çalýþtýðýný gösterir.
http://pythontutor.com/c.html#mode=display


*/

#include <stdio.h>
#include <string.h>

void latinKelimeler(char *);

int main()
{
     char paragraf[]="Writers write descriptive paragraphs"
                    "because their purpose is to describe something "
                    "Their point is that something is beautiful or disgusting or strangely intriguing "
                    "Writers write persuasive and argument paragraphs because their purpose is to persuade or convince someone "
                    "Their point is that their reader should see things a particular way and possibly take action on that new way"
                    "of seeing things  Writers write paragraphs of comparison because the comparison will make their point clear to their readers";
    char *token,*temp;
    token = strtok(paragraf," ");

    while(token!=NULL) {
        //temp = strdup(token);   //token contentsi temp e kopyalamak için 1. yöntem
        sscanf(token,"%s",temp);  //  token contentsi temp e kopyalamak için 1. yöntem
        latinKelimeler(temp);
        token =strtok(NULL," ");
     }
}

void latinKelimeler(char *gelen)
{
    //token = strstr(token,temp);
    char *token=gelen;
    strlwr(token);  //küçük harf çevir
    char temp[] ={token[0],'a','y','\0'};  //ilk harf ve 'ay' birleþtir.
    token = strstr(token,&token[1]);    //ikinci harften itibaren string kes.
    strcat(token,temp);                 //ilk harf+ay parçasono sona ekle.
    printf("%s \n",token);

}
