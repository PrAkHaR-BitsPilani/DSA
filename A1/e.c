#include <stdio.h>

struct node
{
    int val;
    struct node *forward;
    struct node *backward;
};

int main()
{
    char inst[1005];
    scanf("%s", inst);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char command[5];
        scanf("%s", command);
        switch (command[0])
        {
        case 'L':
            if (command[1] == 'S')
            {
            }
            else
            {
            }
            break;
        case 'R':
            if (command[1] == 'S')
            {
            }
            else
            {
            }
            break;
        case 'I':
            break;
        case 'D':
            break;
        }
    }
    return 0;
}