#include <stdio.h>
#include <stdlib.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define robot struct robot

robot{
    int loc;
    int power;
};

int abs(int a)
{
    if(a < 0)return -a;
    return a;
}

int main()
{
    int n , alpha , beta;
    scanf("%d %d %d%*c" , &n , &alpha , &beta);
    robot* robots = (robot*)malloc(sizeof(robot) * n);
    rep(i,n){
        int temp;
        scanf("%d%*c" , &temp);
        robots[i].loc = i+1;
        robots[i].power = temp;
    }
    int count = n;
    while(count > 1)
    {
        int newCount = count;
        rep(i,count-1)
        {
            if(robots[i].power > robots[i+1].power)
            {
                robots[i+1].loc = -1;
                robots[i].power = abs(robots[i].power - alpha*(robots[i].power - robots[i+1].power));
                newCount -= 1;
            }
            else if(robots[i].power < robots[i+1].power)
            {
                robots[i].loc = -1;
                robots[i+1].power = abs(robots[i+1].power - alpha*(robots[i+1].power - robots[i].power));
                newCount -= 1;
            }
            else if(robots[i].power == robots[i+1].power)
            {
                robots[i].loc = robots[i+1].loc = -1;
                newCount -= 2;
            }
            i++;
        }
        if(count & 1)robots[count-1].power += beta;
        robot* temp = (robot*)malloc(sizeof(robot) * newCount);
        int j = 0;
        rep(i,count)
            if(robots[i].loc != -1)
            {
                temp[j].loc = robots[i].loc;
                temp[j].power = robots[i].power;
                j++;
            }
        robots = temp;
        count = newCount;
    }
    if(count == 1)printf("%d %d" , robots[0].loc , robots[0].power);
    else printf("-1 -1");

}