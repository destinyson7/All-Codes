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
 
    while(true)
    {
        ll n, m, c;
        cin >> n >> m >> c;

        if(n+m+c == 0)
        {
            break;
        }

        if(c == 1)
        {
            ll f = (m-8)/2 + 1;
            ll s = (n-8)/2 + 1;
            
            n--;
            m--;

            ll t = (m-8)/2 + 1;
            ll fo = (n-8)/2 + 1;
            
            ll ans = f*s + t*fo;

            if(n<8 || m<8)
            {
                ans = f*s;
            }

            cout << ans << endl;
        }

        else
        {
            ll f = (m-9)/2 + 1;
            ll s = (n-8)/2 + 1;

            ll t = (m-8)/2 + 1;
            ll fo = (n-9)/2 + 1;

            ll ans = f*s + t*fo;

            if(m<9)
            {
                ans-=f*s;
            }

            if(n<9)
            {
                ans-=t*fo;
            }

            cout << ans << endl;
        }
    }   


    return 0;
}