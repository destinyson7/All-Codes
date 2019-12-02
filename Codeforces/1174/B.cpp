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
    
    ll n;
    cin >> n;

    ll odd = 0, even = 0;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        
        if(a[i]&1)
        {
            odd++;
        }

        else
        {
            even++;
        }
    }

    if(odd && even)
    {
        sort(a, a+n);
    }    

    for(ll i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}