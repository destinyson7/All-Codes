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
    
    ll t;
    cin >> t;

    while(t--)
    {
        ll N, C;
        cin >> N >> C;

        vector <ll> x;

        for(ll i=0; i<N; i++)
        {
            ll a;
            cin >> a;

            x.pb(a);
        }

        sort(all(x));

        ll low = 0;
        ll high = x[N-1] - x[0];

        ll ans = 0;

        while(low <= high)
        {
            ll mid = low + (high-low)/2;


            ll temp = C-1;

            ll prev = x[0];

            for(ll i=1; i<N; i++)
            {
                if(x[i]-prev >= mid)
                {
                    temp--;
                    prev  = x[i];
                }
            }

            if(temp <= 0)
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


    return 0;
}