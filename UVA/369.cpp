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

const ll L = 1e2+5;

ll p[L][L];

void init()
{
    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            p[i][j] = -1;
        }
    }
}

ll C(ll n, ll r)
{
    if(p[n][r] != -1)
    {
        return p[n][r];
    }

    if(n<0 || r<0)
    {
        return 0;
    }

    if(n<r)
    {
        return 0;
    }

    if(!r)
    {
        return 1;
    }

    if(n == r)
    {
        return 1;
    }

    p[n][r] = C(n-1, r-1) + C(n-1, r);

    return p[n][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();

    while(true)
    {
        ll N, M;
        cin >> N >> M;

        if(N+M == 0)
        {
            break;
        }

        cout << N << " things taken " << M << " at a time is " << C(N, M) << " exactly." << endl;
    }



    return 0;
}