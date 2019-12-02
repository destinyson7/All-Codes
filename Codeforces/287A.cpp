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
    
    vector <string> v(5);

    for(ll i=0; i<4; i++)
    {
        cin >> v[i];
    }

    for(ll i=0; i<3; i++)
    {
        for(ll j=0; j<3; j++)
        {
            ll cnt = 0;

            if(v[i][j] == '.')
            {
                cnt++;
            }

            if(v[i][j+1] == '.')
            {
                cnt++;
            }

            if(v[i+1][j+1] == '.')
            {
                cnt++;
            }

            if(v[i+1][j] == '.')
            {
                cnt++;
            }

            if(cnt!=2)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    
    return 0;
}