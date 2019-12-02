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

ll a[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll w, l;
    cin >> w >> l;

    ll sum = 0;
    for(ll i=0; i<w-1; i++)
    {
        cin >> a[i];

        if(i<l)
        {
            sum+=a[i];
        }
    }

    ll m = sum;

    for(ll i=l; i<w-1; i++)
    {
        // if(i+l > w)
        // {
        //     break;
        // }

        sum-=a[i-l];
        sum+=a[i];

        m = min(m, sum);
    }

    cout << m << endl;
    
    return 0;
}