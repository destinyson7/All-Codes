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
    
    string s;
    cin >> s;

    ll lower = 0;
    ll upper = 0;

    for(ll i=0; i<sz(s); i++)
    {
        if(s[i] < 97)
        {
            upper++;
        }

        else
        {
            lower++;
        }
    }

    if(upper>lower)
    {
        for(ll i=0; i<sz(s); i++)
        {
            if(s[i]>=97)
            {
                s[i]-=32;
            }

            cout << s[i];
        }

        cout << endl;
    }

    else
    {
        for(ll i=0; i<sz(s); i++)
        {
            if(s[i]<97)
            {
                s[i]+=32;
            }

            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}