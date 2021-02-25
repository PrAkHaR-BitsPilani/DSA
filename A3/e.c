#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;

int loop()
{
    int pos = 0;
    int temp = 0;
    bool cont  = true;
    while(cont)
    {
        n--;
        char command;
        scanf("%c" , &command);
        switch(command)
        {
            case 'F':
                scanf("%*c%*c%d%*c" , &temp);
                pos += temp;
            break;
            case 'L':
                scanf("%*c%*c%*c%*c%d%*c" , &temp);
                pos += temp * loop();
            break;
            case 'E':
                scanf("%*c%*c%*c");
                cont = false;
            break;
        }
    }
    return pos;
}

int main()
{
    scanf("%d%*c" , &n);
    int pos = 0;
    int temp = 0;
    while(n--)
    {
        char command;
        scanf("%c" , &command);
        switch(command)
        {
            case 'F':
                scanf("%*c%*c%d%*c" , &temp);
                pos += temp;
            break;
            case 'L':
                scanf("%*c%*c%*c%*c%d%*c" , &temp);
                pos += temp * loop();
            break;
        }
    }
    printf("%d" , pos);
}