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

const ll L = 3e3+5;

vector <string> v(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> v[i];
    }

    bool f = true;

    char h = v[0][0];

    for(ll i=0; i<n; i++)
    {
        if(v[i][i] == h && v[i][n-i-1] == h)
        {
            continue;
        }

        // cout << i << " " << n-i-1 << endl;
        f = false;
        break;
    }

    // cout << f << endl;
    char t = v[0][1];

    if(t == h)
    {
        f = false;
    }

    if(f)
    {

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(i==j || i==n-j-1)
                {
                    continue;
                }

                else if(v[i][j]!=t)
                {
                    f = false;
                    break;
                }
            }

            if(!f)
            {
                break;
            }
        }
    }

    if(f)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }



    return 0;
}