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
    
    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    vector <ll> left(n+5, 0);
    set <pll> waste;

    for(ll i=0; i<k; i++)
    {
        ll a, b;
        cin >> a >> b;

        a--, b--;

        left[a]++;
        waste.insert(mp(a, b));
    }

    vector <string> ans = {"Carrots", "Kiwis", "Grapes"};

    while(t--)
    {
        ll i, j;
        cin >> i >> j;

        i--, j--;

        // cout << "i " << i << " " << j << endl;

        if(waste.find(mp(i, j)) != waste.end())
        {
            cout << "Waste" << endl;
        }

        else
        {
            ll cnt = 0;

            for(ll p=0; p<i; p++)
            {
                cnt+=(m-left[p]);
            }

            // cout << cnt << " ";

            for(ll q=0; q<j; q++)
            {
                // cout << i << " " << q << endl;
                if(waste.find(mp(i, q)) ==  waste.end())
                {
                    cnt++;
                }
            }

            cnt%=3;
            cout << ans[cnt] << endl;
        }
    }


    return 0;
}