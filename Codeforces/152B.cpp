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
    
    ll n, m;
    cin >> n >> m;

    pll cur;

    cin >> cur.ff >> cur.ss;

    ll steps = 0;

    ll k;
    cin >> k;

    while(k--)
    {
        ll x, y;
        cin >> x >> y;

        ll low = 0, high = 1e9;

        ll ok = 0;

        while(low <= high)
        {
            ll mid = low + (high - low)/2;

            // cout << mid << " " << cur.ff << " " << cur.ss << endl;

            if(cur.ff + x*mid <= n && cur.ff + x*mid >= 1 && cur.ss + y*mid <= m && cur.ss + y*mid >= 1)
            {
                low = mid+1;
                ok = mid;

                // cout << "here at " << mid  << " " << cur.ff+mid*x << " " << cur.ss+y*mid << endl;
            }

            else
            {
                high = mid-1;
            }
        }

        steps+=ok;

        cur = mp(cur.ff + ok*x, cur.ss + ok*y);
    }

    cout << steps << endl;

    return 0;
}