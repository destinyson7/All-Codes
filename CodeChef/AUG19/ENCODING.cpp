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

const ll L = 1e5+5;
const ll mod = 1e9+7;

ll cur[L], fin[L];

string sub(string num)
{
    string toRet;

    ll len = sz(num);

    bool f = false;

    for(ll i=len-1; i>=0; i--)
    {
        if(f)
        {
            toRet+=num[i];
        }

        else
        {
            if(num[i] == '0')
            {
                toRet+='9';
            }

            else
            {
                f = true;
                toRet+=(num[i]-1);
            }
        }
    }

    reverse(all(toRet));

    return toRet;
}

ll dp(ll dig, ll l, ll r)
{
    if(l > r)
    {
        return 0;
    }

    ll temp = modexp(10, dig-l-1, mod);
    temp = (temp*temp)%mod;

    ll t = cur[l-1]%mod;
    t = ((t*(t-1))/2)%mod;

    temp = (t*temp)%mod;

    if(r > l)
    {
        ll add = modexp(10, dig-l-2, mod);
        add = (add*cur[l-1])%mod;
        add = (add*5)%mod;

        ll ag = modexp(10, dig-l-1, mod)-1;
        ag = (ag+mod)%mod;

        add = (add*ag)%mod;

        temp+=add;
        temp%=mod;
    }

    if(cur[l] > cur[l-1])
    {
        ll add = modexp(10, dig-l-1, mod);
        add = (add*add)%mod;
        add = (add*cur[l-1])%mod;

        temp+=add;
        temp%=mod;
    }

    else if(cur[l-1] == cur[l])
    {
        ll add = modexp(10, dig-l-1, mod);
        add = (add*cur[l])%mod;

        add = (add*((fin[l+1]+1)%mod))%mod;

        temp+=add;
        temp%=mod;
    }

    ll res = dp(dig, l+1, r);

    temp = (temp+res)%mod;

    return temp;
}

ll ini(string num, ll dig)
{
    if(!dig)
    {
        return 0;
    }

    // cout << "dig " << dig << endl;

    for(ll i=0; i<dig; i++)
    {
        cur[i] = num[i] - '0';
    }

    ll mul = 1;

    // cout << "num " << num << endl;

    for(ll i = dig-1; i>=0; i--)
    {
        if(i == dig-1)
        {
            fin[i] = num[i] - '0';
        }

        else
        {
            fin[i] = fin[i+1] + mul*(num[i] - '0');
            fin[i]%=mod;
        }

        // cout << fin[i] << " ";
        mul = (mul*10)%mod;
    }
    // cout << endl;

    ll temp = (((fin[0]+1)*fin[0])/2)%mod;

    ll ans = dp(dig, 1, dig-1);

    // cout << ans << " " << temp << endl;

    temp = (temp-ans+mod)%mod;

    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        for(ll i=0; i<L; i++)
        {
            cur[i] = 0;
            fin[i] = 0;
        }

        ll nl, nr;
        string l, r;

        cin >> nl >> l;
        cin >> nr >> r;

        l = sub(l);
        nl = sz(l);

        // cout << l << " " << nl << endl;

        // ll ans = ini(r, nr);
        ll sub = ini(l, nl);

        // ans = (ans - ini(l, nl) + mod)%mod;

        cout << (ini(r, nr) - sub + mod)%mod << endl;

    }

    return 0;
}