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

const ll L = 20;

vector <ll> a;

ll ans = 1;

void check(ll s, ll e)
{   
    if(e==s)
    {
        return;
    }

    bool f = false;

    for(ll i=s; i<e; i++)
    {
        if(a[i] > a[i+1])
        {   
            f = true;
            break;
        }
    }

    if(!f)
    {
        ans = max(ans, e-s+1);
    }

    ll mid = s + (e-s)/2;

    check(s, mid);
    check(mid+1, e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    check(0, n-1);

    cout << ans << endl;
    
    return 0;
}