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

const ll L = 1e2+5;
const ll M = 30;

ll cnt[L][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for(ll i=0; i<n; i++)
    {
        for(ll j=n; j>1; j--)
        {
            ll t = 0;

            for(ll a=0; a<=25; a++)
            {
                t+=cnt[j-1][a];
            }

            cnt[j][s[i]-97] = t;
        }

        cnt[1][s[i]-97] = 1;
    }

    bool f = false;
    ll res = 0;

    ll temp = k;

    for(ll i=n; i>0; i--)
    {
        for(ll j=0; j<=25; j++)
        {
            if(temp>0)
            {
                if(temp>=cnt[i][j])
                {
                    res+=((n-i)*cnt[i][j]);
                    temp-=cnt[i][j];
                }

                else
                {
                    res+=((n-i)*temp);
                    temp = 0;
                    f=true;
                    break;
                }
            }

            else
            {
                f=true;
                break;
            }

            // cout << temp << endl;
        }

        if(f)
        {
            break;
        }
    }

    if(temp>1)
    {
        cout << -1 << endl;
        return 0;
    }

    res = (temp<=0) ? res : res+n;

    cout << res << endl;

    return 0;
}