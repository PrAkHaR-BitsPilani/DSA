#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char a[210];
    char b[210];
    scanf("%s\n%s%*c" , a , b);
    int i_a = 0 , i_b = 0;
    while(true)
    {
        char c_a = a[i_a];
        char c_b = b[i_b];
        if(c_b >= c_a)printf("%c" , c_b) , i_b++;
        if(c_a > c_b)printf("%c" , c_a) , i_a++;
        if(i_a == strlen(a))break;
        if(i_b == strlen(b))break;
    }   
    while (i_a < strlen(a))
    {
        printf("%c" , a[i_a]);
        i_a++;
    }
    while (i_b < strlen(b))
    {
        printf("%c" , b[i_b]);
        i_b++;
    }
}