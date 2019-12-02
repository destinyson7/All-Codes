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

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    ll k, r;
    cin >> k >> r;

    ll cur = 1;

    while(true)
    {
        if(cur*k >= r && (cur*k - r)%10 == 0)
        {
            cout << cur << endl;
            return 0;
        }

        if((cur*k)%10 == 0)
        {
            cout << cur << endl;
            return 0;
        }

        cur++;
    }


    return 0;
}