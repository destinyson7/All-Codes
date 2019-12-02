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

const ll L = 3e5+5;

ll a[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    if(n==3 || n==4)
    {
        cout << -1 << endl;
        return 0;
    }

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        // a[i]--;
    }

    for(ll i=0; i<n; i+=2)
    {
        cout << a[i] << " ";
    }

    if(n&1)
    {
        for(ll i=1; i<n; i+=2)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    else
    {
        swap(a[n-1], a[n-3]);

        for(ll i=1; i<n; i+=2)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }



    return 0;
}