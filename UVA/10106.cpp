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
    
    string x, y;

    while(cin >> x)
    {
        cin >> y;

        ll lenx = sz(x);
        ll leny = sz(y);
        
        vector <ll> ans(lenx+leny+10, 0);

        reverse(all(x));
        reverse(all(y));

        ll last = lenx+leny+9;

        for(ll i=0; i<lenx; i++)
        {
            for(ll j=0; j<leny; j++)
            {
                ans[last-j-i]+=((x[i]-48)*(y[j]-48));
                ans[last-j-i-1]+=(ans[last-j-i]/10);
                ans[last-j-i]%=10;
            }
        }

        ll i = 0;
        
        for(i=0; i<lenx+leny+10; i++)
        {
            if(ans[i] != 0)
            {
                break;
            }
        }

        // cout << i << endl;

        if(i == lenx+leny+10)
        {
            cout << 0;
        }

        for(ll j=i; j<lenx+leny+10; j++)
        {
            cout << ans[j];
        }
        cout << endl;

    }


    return 0;
}