#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b;
    cin >> a >> b;

    vector <ll> div1(3, 0);
    vector <ll> div2(3, 0);

    while(a%2 == 0)
    {
        div1[0]++;
        a>>=1;
    }

    while(a%3 == 0)
    {
        div1[1]++;
        a/=3;
    }

    while(a%5 == 0)
    {
        div1[2]++;
        a/=5;
    }

    while(b%2 == 0)
    {
        div2[0]++;
        b>>=1;
    }

    while(b%3 == 0)
    {
        div2[1]++;
        b/=3;
    }

    while(b%5 == 0)
    {
        div2[2]++;
        b/=5;
    }

    if(a == b)
    {
        cout << abs(div1[0] - div2[0]) + abs(div1[1] - div2[1]) + abs(div1[2] - div2[2]) << endl;
    }

    else
    {
        cout << -1 << endl;
    }

    return 0;
}