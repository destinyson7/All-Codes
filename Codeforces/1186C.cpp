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
    
    string a, b;
    cin >> a;
    cin >> b;

    ll cntb = 0, cnta = 0;

    for(ll i=0; i<sz(b); i++)
    {
        if(b[i] == '1')
        {
            cntb++;
        }

        if(a[i] == '1')
        {
            cnta++;
        }
    }

    ll lenb = sz(b);

    ll ans = 0;

    if((cnta+cntb)%2 == 0)
    {
        ans++;
    }

    for(ll i=lenb; i<sz(a); i++)
    {
        if(a[i-lenb] == '1')
        {
            cnta--;
        }

        if(a[i] == '1')
        {
            cnta++;
        }

        if((cnta+cntb)%2 == 0)
        {
            ans++;
        }
    }

    cout << ans << endl;


    return 0;
}