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
    
    ll n, k, l, r, total, few;
    cin >> n >> k >> l >> r >> total >> few;

    ll rest = total - few;

    ll more = few/k;

    few%=k;

    ll less = 0;

    if(n!=k)
    {
        less = rest/(n-k);

        rest%=(n-k);
    }
     
    for(ll i=0; i<k; i++)
    {
        if(few)
        {
            cout << more+1 << " ";
            few--;
        }

        else
        {
            cout << more << " ";
        }
    }

    for(ll i=k; i<n; i++)
    {
        if(rest)
        {
            cout << less+1 << " ";
            rest--;
        }

        else
        {
            cout << less << " ";
        }
    }

    cout << endl;

    return 0;
}