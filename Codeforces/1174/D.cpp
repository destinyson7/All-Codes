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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, x;
    cin >> n >> x;

    ll pow2 = 1<<n;

    vector <ll> v(pow2+1, 0);

    if(x >= pow2)
    {
        ll maxl = (ll)(1<<n)- 1;

        for(ll i=1; i<=maxl; i++)
        {
            if(i==1)
            {
                cout << maxl << endl;
            }

            ll t = (i-1)^i;
            cout << t << " ";
        }

        cout << endl;
    }

    else
    {
        ll tp = pow2/2 - 1;
        cout << tp << endl;
        
        if(tp)
        {
            v[0] = 1;
            v[x] = 1;
            ll cur = 0;

            for(ll i=1; i<pow2; i++)
            {
                if(v[i]!=1)
                {
                    ll temp = cur^i;

                    cout << temp << " ";
                }

                cur = i;

                v[i] = 1;
                v[i^x] = 1;
            }            

            cout << endl;

        }
    }

    return 0;
}