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
 
    string s1, s2;
    cin >> s1 >> s2;

    ll req = 0;

    for(ll i=0; i<sz(s1); i++)
    {
        if(s1[i] == '+')
        {
            req++;
        }

        else
        {
            req--;
        }
    }   

    ll our = 0;

    ll any = 0;

    for(ll i=0; i<sz(s2); i++)
    {
        if(s2[i] == '+')
        {
            our++;
        }

        else if(s2[i] == '-')
        {
            our--;
        }

        else
        {
            any++;
        }
    }   

    ll toDo = abs(req - our);

    if(any < toDo || (any+toDo)&1)
    {
        cout << fixed << setprecision(12) << (double)0.0 << endl;
        
        return 0;
    }

    ll choose = toDo + (any-toDo)/2;

    // ans = C(any, choose);

    double ans = 1.0;

    for(ll i=2; i<=any; i++)
    {
        ans*=(double)i;
    }

    for(ll i=2; i<=choose; i++)
    {
        ans/=(double)i;
    }

    for(ll i=2; i<=any-choose; i++)
    {
        ans/=(double)i;
    }

    double div = (double)(1LL<<any);

    cout << fixed << setprecision(12) << ans/div << endl;

    return 0;
}