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

    ll cnt = 0;

    while(n--)
    {
        string s;
        cin >> s;

        bool f = true;

        map <ll, ll> m;

        for(ll i=0; i<sz(s); i++)
        {
            // if(s[i]-48 > k)
            // {
            //     f = false;
            //     break;
            // }

            m[s[i]-48] = 1;
        }   

        if(f)
        {
            // cout << m[0] << endl;
            bool g = true;

            for(ll i=0; i<=k; i++)
            {
                if(m[i]!=1)
                {
                    g = false;
                    break;
                }
            }

            if(g)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;


    return 0;
}