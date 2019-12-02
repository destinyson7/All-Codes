#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll e, f, g;

    if(a>b && a>c)
    {
        if(b>c)
        {
            e = c;
            f = b;
            g = a;
        }

        else
        {
            e = b;
            f = c;
            g = a;
        }
    }   

    else if(b>a && b>c)
    {
        if(a>c)
        {
            e = c;
            f = a;
            g = b;
        }

        else
        {
            e = a;
            f = c;
            g = b;
        }
    } 

    else
    {
        if(b>a)
        {
            e = a;
            f = b;
            g = c;
        }

        else
        {
            e = b;
            f = a;
            g = c;
        }
    }

    ll ans = 0;
    if(abs(e-f) < d)
    {
        ans+=(d-abs(e-f));
    }

    if(abs(f-g)<d)
    {
        ans+=(d-abs(f-g));
    }
    cout << ans << endl;

    


    return 0;
}