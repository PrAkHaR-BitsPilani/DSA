#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

int main()
{
    int n;
    scanf("%d%*c" , &n);
    char* song = (char*)malloc(sizeof(char) * n);
    scanf("%s%*c" , song);
    int freq[7];
    rep(i,7)freq[i] = 0;
    rep(i,n)
        freq[song[i] - 'A']++;
    int l = 0;
    int r = n-1;
    bool cont = true;
    while(l <= r && cont)
    {
        cont = false; 
        if(freq[song[l] - 'A'] > 1)
        {
            freq[song[l] - 'A']--;
            l++;
            cont = true;
        }
        if(freq[song[r] - 'A'] > 1)
        {
            freq[song[r] - 'A']--;
            r--;
            cont = true;
        }
    }
    printf("%d" , r - l + 1);
}