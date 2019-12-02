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

    ll len = sz(s);

    for(ll i=0; i<len; i++)
    {
        if((s[i]-48)%8 == 0)
        {
            cout << "YES" << endl;
            cout << s[i]-48 << endl;

            return 0;
        }
    }

    for(ll i=0; i<len; i++)
    {
        for(ll j=i+1; j<len; j++)
        {
            if((10*(s[i]-48) + s[j]-48)%8 == 0)
            {
                cout << "YES" << endl;
                cout << 10*(s[i]-48) + s[j]-48 << endl;
                
                return 0;
            }
        }
    }

    for(ll i=0; i<len; i++)
    {
        for(ll j=i+1; j<len; j++)
        {
            for(ll k=j+1; k<len; k++)
            {
                if((100*(s[i]-48) + 10*(s[j]-48) + s[k]-48)%8 == 0)
                {
                    cout << "YES" << endl;
                    cout << 100*(s[i]-48) + 10*(s[j]-48) + s[k]-48 << endl;

                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}