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
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;

        if(k > n*a)
        {
            cout << n << endl;
        }

        else if(k < b*n)
        {
            cout << -1 << endl;
        }

        else
        {
            ll low = 0;
            ll high = n+5;

            ll ans = -1;

            while(low<=high)
            {
                ll mid = low + (high-low)/2;

                if(a*mid + (n-mid)*b < k)
                {
                    ans = mid;
                    low = mid+1;
                }

                else
                {
                    high = mid-1;
                }
            } 

            cout << ans << endl;
        }
    }

    return 0;
}