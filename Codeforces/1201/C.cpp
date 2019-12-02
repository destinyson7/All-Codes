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
    
    ll n, k;
    cin >> n >> k;

    vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    sort(all(a));

    ll median = a[n/2];

    // if(a[n/2 + 1] - a[n/2] >= k)
    // {
    //     cout << median + k << endl;
    // }

    // else
    // {
        ll div = 1;
        
        ll cur = n/2;

        while(cur < n-1)
        {
            // cout << k << " " << cur << " " << a[cur+1] << " " << median << " " << div << endl;
            if((a[cur+1] - median)*div >= k)
            {
                k/=div;

                cout << median + k << endl;
                return 0;
            }

            else
            {
                // cout << "oops " << a[cur+1] << " " << median << endl;
                k-=(div*(a[cur+1]-median));
                median = a[cur+1];
                div++;

                // cout << cur << " " << k << endl;
            }

            cur++;
        }

        // cout << median << " " << k << endl;

        cout << median + k/div << endl;
    // }

    return 0;
}