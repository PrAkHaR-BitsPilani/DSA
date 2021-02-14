#include <stdio.h>
#include <stdlib.h>

int min(int a , int b)
{
    if(a < b)return a;
    return b;
}

int main(){
    int no_of_authors , no_of_publications , no_of_citations;
    scanf("%d %d %d%*c" , &no_of_authors , &no_of_publications , &no_of_citations);
    int* publication_author = (int*)malloc(sizeof(int) * no_of_publications);
    for (int i = 0; i < no_of_publications; i++)scanf("%d" , &publication_author[i]);
    int* citation_count = (int*)malloc(sizeof(int) * no_of_publications);
    for (int i = 0; i < no_of_publications; i++)citation_count[i] = 0;
    for (int i = 0; i < no_of_citations; i++)
    {
        int u , v;
        scanf("%d %d%*c" , &u , &v);
        citation_count[v]++;
    }
    int* ans = (int*)malloc(sizeof(int) * no_of_authors);
    for (int i = 0; i < no_of_authors; i++)ans[i] = -1;
    for (int i = 0; i < no_of_publications; i++)
    {
        if(ans[publication_author[i]] != -1)
            ans[publication_author[i]] = min(ans[publication_author[i]] , citation_count[i]);
        else
            ans[publication_author[i]] = citation_count[i];
    }
    for (int i = 0; i < no_of_authors; i++)
    {
        if(ans[i] == -1)printf("0 ");
        else printf("%d " , ans[i]);
    }
    
    
}