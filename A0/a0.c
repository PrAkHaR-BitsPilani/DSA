#include <stdio.h>

int main()
{
    char a[1005];
    char b[1005];
    scanf("%s", a);
    scanf("%s", b);
    int lenA = 0, lenB = 0;
    while (a[lenA] != '\0')lenA++;
    while (b[lenB] != '\0')lenB++;
    char ans[1005];
    int carry = 0 , index = 1004;
    while ((lenA >= 1) && (lenB >= 1))
    {
        int sum = (a[lenA - 1] - '0') + (b[lenB - 1] - '0') + carry;
        ans[index--] = '0' + (sum % 10);
        carry = sum / 10;
        lenA -= 1;
        lenB -= 1;
    }
    if (lenA)
    {
        while ((lenA >= 1))
        {
            int sum = (a[lenA - 1] - '0') + carry;
            ans[index--] = '0' + (sum % 10);
            carry = sum / 10;
            lenA -= 1;
        }
    }
    else
    {
        while ((lenB >= 1))
        {
            int sum = (b[lenB - 1] - '0') + carry;
            ans[index--] = '0' + (sum % 10);
            carry = sum / 10;
            lenB -= 1;
        }
    }
    if(carry)ans[index--] = '0' + carry;
    for (int i = index + 1; i < 1005; i++)
        printf("%c", ans[i]);
}