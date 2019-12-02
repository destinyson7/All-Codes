#include<stdio.h>

long long int PnC(long long int n)
{
    long long int pr;
    
    pr=((n*(n-1))/2);

    return pr;
}

int main()
{
    long long int n, m;
    scanf("%lld %lld", &n, &m);

    long long int kmin=0, kmax=0;

    kmax=PnC(n-m+1);

    long long int a=n%m;
    long long int b=m-a;

    kmin=a*PnC(n/m + 1) + b*PnC(n/m);

    printf("%lld %lld", kmin, kmax);

    return 0;
}
