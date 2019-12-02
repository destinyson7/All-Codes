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

ll xi, yi, xf, yf, n;

vector <pll> pref(L);

bool check(ll days)
{
    ll xWind = (days/n)*pref[n-1].ff; 
    ll yWind = (days/n)*pref[n-1].ss;

    if(days%n)
    {
        xWind+=pref[days%n - 1].ff;
        yWind+=pref[days%n - 1].ss;
    }

    ll xCur = xi;
    ll yCur = yi;
    
    xCur+=xWind;
    yCur+=yWind;

    // cout << "days: " << days << " " << xWind << " " << yWind << " " << xCur << " " << yCur << endl;

    if(abs(xf - xCur) + abs(yf - yCur) <= days)
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> xi >> yi;
    cin >> xf >> yf;

    // ll n;
    cin >> n;

    string s;
    cin >> s;

    if(s[0] == 'U')
    {
        pref[0].ff = 0;
        pref[0].ss = 1;
    }

    else if(s[0] == 'D')
    {
        pref[0].ff = 0;
        pref[0].ss = -1;
    }

    else if(s[0] == 'L')
    {
        pref[0].ff = -1;
        pref[0].ss = 0;
    }

    else
    {
        pref[0].ff = 1;
        pref[0].ss = 0;
    }

    for(ll i=1; i<sz(s); i++)
    {
        if(s[i] == 'U')
        {
            pref[i].ff = pref[i-1].ff;
            pref[i].ss = pref[i-1].ss + 1;
        }

        else if(s[i] == 'D')
        {
            pref[i].ff = pref[i-1].ff;
            pref[i].ss = pref[i-1].ss - 1;
        }

        else if(s[i] == 'L')
        {
            pref[i].ff = pref[i-1].ff - 1;
            pref[i].ss = pref[i-1].ss;
        }

        else
        {
            pref[i].ff = pref[i-1].ff + 1;
            pref[i].ss = pref[i-1].ss;
        }
    }

    // for(ll i=0; i<n; i++)
    // {
    //     cout << pref[i].ff << " " << pref[i].ss << endl;
    // }

    ll low = 0;
    ll high = n*(abs(yi-yf) + abs(xi-xf));

    ll m = high;
    ll ans = 2*high;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        if(check(mid))
        {
            ans = mid;
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }
    }

    if(ans == 2*m)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << ans << endl;
    }


    return 0;
}