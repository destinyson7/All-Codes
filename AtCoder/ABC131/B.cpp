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

const ll L = 2e2+5;

ll fla[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, L;
    cin >> N >> L;

    ll res = 1e9;
    ll sum = 0;

    bool f = false;

    for(ll i=1; i<=N; i++)
    {
        fla[i] = L+i-1;

        // cout << fla[ i]<< endl;

        sum+=fla[i];
        
        // if(fla[i]>=0)
        // {
            // f = true;
            if(fla[i]<0)
            {
                f = true;
                res = min(res, abs(0LL-fla[i]));
            }

            else
            {
                res = min(res, abs(0LL-fla[i]));
            }
        // }
    }

    if(f)
    {
        res = -res;
    }

    // cout << sum << " " << res << endl;

    cout << sum-res << endl;

    return 0;
}