#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int check(char a , char b)
{
    if(a > b)return 1;
    if(b > a)return 0;
    if(a == b)return -1;
}

int main()
{
    char a[210];
    char b[210];
    scanf("%s\n%s%*c" , a , b);
    int i_a = 0 , i_b = 0;
    int dir = 0;
    while(true)
    {
        char c_a = a[i_a];
        char c_b = b[i_b];
        if(c_b > c_a)printf("%c" , c_b) , i_b++ , dir = 0;
        if(c_a > c_b)printf("%c" , c_a) , i_a++ , dir = 0;
        if(c_a == c_b)
        {
            if(dir == 1)
            {
                printf("%c" , c_a) , i_a++;
            }
            if(dir == 2)
            {
                printf("%c" , c_b) , i_b++;
            }
            if(dir == 0)
            {
                int ans = check(c_a , c_b);
                int index_a = i_a;
                int index_b = i_b;
                while(ans == -1)
                {
                    index_a++;
                    index_b++;
                    if(index_a >= strlen(a) && index_b >= strlen(b))
                    {
                        ans = 1;
                        break;
                    }
                    if(index_a >= strlen(a))
                        c_a = '0';
                    else c_a = a[index_a];
                    if(index_b >= strlen(b))
                        c_b = '0';
                    else c_b = b[index_b];
                    ans = check(c_a , c_b);
                }
                if(ans == 1)
                {
                    dir = 1;
                    c_a = a[i_a];
                    printf("%c" , c_a) , i_a++;
                }
                if(ans == 0)
                {
                    dir = 2;
                    c_b = b[i_b];
                    printf("%c" , c_b) , i_b++;
                }

            }
        }
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