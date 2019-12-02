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

const ll L = 2e5+5;

ll a[L];
ll b[L];
ll h[L];
ll ch[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll flag = 1;
    
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        h[a[i]]++;

        // cout << h[a[i]] << endl;
    }

    for(ll i=0; i<n; i++)
    {
        cin >> b[i];

        if(b[i] != i+1)
        {
            flag = 0;
        }

        ch[b[i]] = i+1;

    }

    if(flag)
    {
        cout << 0 << endl;
        return 0;
    }

    ll a = b[n-1];
    if(h[1]==0)
    {
        a = ch[1];

        ll f = 0;
        for(ll i=a+1; i<=n; i++)
        {
            if(ch[i+1-a]!=i)
            {
                f = 1;
                break;
            }
        }

        if(!f)
        {
            for(ll i=n+2-a; i<=n; i++)
            {
                if(h[i]==1)
                {
                    continue;
                }

                else
                {
                    if(ch[i] <= i-1-(n+1-a))
                    {
                        continue;
                    }

                    else
                    {
                        f = 1;
                        break;
                    }
                }
            }
        }

        if(!f)
        {
            cout << a-1 << endl;
            return 0;
        }
    }

    ll ok = 0;

    for(ll i=1; i<=n; i++)
    {
        if(h[i]==1)
        {
            continue;
        }

        else
        {
            if(ch[i]<i+ok);

            else
            {
                ok+=ch[i]-i-ok+1;
            }
        }
    }

    cout << ok+n << endl;



    return 0;
}