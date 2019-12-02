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

vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // ll n, m;
    // cin >> n >> m;

    string a, b;
    cin >> a;
    cin >> b;

    ll cur = 0;

    ll ans = 0;

    ll c1 = 0;
    ll c2 = 0;

    ll lena = sz(a);
    ll lenb = sz(b);

    for(ll i=0; i<lenb-1; i++)
    {
        if(b[i+1]!=b[i])
        {
            v.pb(i);
        }
    }    

    for(ll i=0; i<lenb; i++)
    {
        if(a[i]!=b[i])
        {
            cur++;
        }
    }

    if(!(cur&1))
    {
        ans = 1;
    }

    ll len = sz(v);

    for(ll i=0; i<len; i++)
    {
        if(a[i]!=b[v[i]])
        {
            c1++;
        }
    }

    c2 = len-c1;

    for(ll i=1; i<lena+1-lenb; i++)
    {
        cur-=c1;

        if(b[0]!=a[i-1])
        {
            cur--;
        }

        cur+=c2;
    
        swap(c2, c1);

        if(b[lenb-1]!=a[i-1+lenb])
        {
            cur++;
        }

        if(!(cur&1))
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}