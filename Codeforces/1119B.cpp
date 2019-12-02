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

vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, h;
    cin >> n >> h;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    for(ll i=0; i<n; i++)
    {
        sort(a.begin(), a.begin()+i+1);
        reverse(a.begin(), a.begin()+i+1);

        // for(ll j=0; j<=i; j++)
        // {
        //     cout << a[j] << " ";
        // }
        // cout << endl;

        ll temp = h;

        if(i&1)
        {
            for(ll j=0; j<i; j+=2)
            {
                temp-=a[j];
            }

            // temp-=a[i];

            if(temp<0)
            {
                cout << i << endl;
                return 0;
            }
        }

        else
        {
            for(ll j=0; j<=i; j+=2)
            {
                temp-=a[j];

                // cout << i << " " << temp << endl;
            }

            // temp-=a[i];

            if(temp<0)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << n << endl;

    return 0;
}