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

ll modexp(ll a, ll b, ll c)
{
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;

    ll n = sz(s);

    vector <ll> r(n+5), l(n+5);
    vector <ll> ans(n+5, 0);

    ll cur = n-1;

    for(ll i=n-2; i>=0; i--)
    {
        if(s[i] == 'R')
        {
            l[i] = cur;
        }

        else
        {
            cur = i;
        }
    }

    cur = 0;

    for(ll i=1; i<n; i++)
    {
        if(s[i] == 'L')
        {
            r[i] = cur;
        }

        else
        {
            cur = i;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(s[i] == 'R')
        {
            if((l[i]-i)%2 == 0)
            {   
                ans[l[i]]++;
            }

            else
            {
                ans[l[i]-1]++;
            }
        }

        else
        {
            if((i-r[i])%2 == 0)
            {
                ans[r[i]]++;
            }

            else
            {
                ans[r[i]+1]++;
            }
        }
    }

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}