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

char v[] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll k;
    cin >> k;

    ll r = 0, c = 0;
    for(ll i=5; i*i<=k; i++)
    {
        if(k%i==0)
        {
            r = i;
            c = k/i;
        }
    }

    if(r>=5 && c>=5)
    {
        for(ll i=0; i<c; i++)
        {
            for(ll j=0; j<r; j++)
            {
                ll t = (i+j)%5;
                cout << v[t];
            }
        }
        cout << endl;
    }

    else
    {
        cout << -1 << endl;
    }


    return 0;
}