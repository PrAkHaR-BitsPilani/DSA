#include <stdio.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define int long long

const  int MOD = 1e9 + 7;

int pos;
int big , small , x;

int fact(int n)
{
    if(n <= 1LL)return 1LL;
    int ans = 1LL;
    for(int i = 1LL; i <= n; i++)
        ans *= i , ans %= MOD;
    return ans;
}

int get(int l , int r)
{
    int ways = 1;
    int mid = (l+r) / 2;
    int newL , newR;
    //printf("%lld %lld %lld\n" , l , r , mid);
    if(mid == pos){
        ways *= 1;
        newL = mid+1;
        newR = r;
    }
    if(mid > pos){
        ways *= (big--) , ways %= MOD;
        newL = l;
        newR = mid;
    }
    if(mid < pos){
        ways *= (small--) , ways%= MOD;
        newL = mid+1;
        newR = r;
    }
    if(newL < newR)ways *= get(newL , newR) , ways%= MOD;
    return ways;
}

int main()
{
    int n;
    scanf("%lld %lld %lld" , &n , &x , &pos);
    big = n - x;
    small = x-1;
    int ans = get(0,n);
    ans *= fact(small+big) , ans %= MOD;
    printf("%lld" , ans);
    return 0;
}