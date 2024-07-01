#include<stdio.h>

int freq(char *p,char c);

int main()
{
    int count;
    char str[50],c; 
    printf("Enter the character whose frequency has to find : ");
    scanf("%c",&c);
    printf("Enter the String : ");
    scanf("%s",str);
    count=freq(str,c);
    printf("\n%d is the frequency",count);
    return 0;
}

int freq(char *p,char c)
{
    int count=0;
    while(*p!='\0')
    {
        if(*p==c)
         count++;
        p++;
    }
    return count;
}
