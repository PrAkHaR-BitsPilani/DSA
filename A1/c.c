#include<stdio.h>
#include<stdbool.h>

int main(){
    int T;
    scanf("%d%*c" , &T);
    int maxSeat  =  0;
    int current = 0;
    char command;
    int x;
    while(T--){
        scanf("%c%*c" , &command);
        if(command == 'E'){
            scanf("%d%*c" , &x);
            current += x;
        }else{
            scanf("%d%*c" , &x);
            current -= x;
            while(x--){
                int p;
                scanf("%d%*c" , &p);
            }
        }
        if(current > maxSeat)maxSeat = current;
    }
    printf("%d\n" , maxSeat);
    return 0;
}