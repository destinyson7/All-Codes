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
 
    ll n;
    cin >> n;

    string s;
    cin >> s;

    bool f1 = false;
    bool f2 = false;

    for(ll i=0; i<sz(s); i++)
    {
        if(s[i] == 'L')
        {
            f1 = true;
        }

        else if(s[i] == 'R')
        {
            f2 = true;
        }
    }   

    if(!f1 && !f2)
    {
        cout << 1 << " " << 1 << endl;
    }

    else if(!f1)
    {
        ll start = -1;
        ll end = -1;

        for(ll i=0; i<sz(s); i++)
        {
            if(s[i] == 'R')
            {
                if(start == -1)
                {
                    start = i+1;
                }

                end = i+1;
            }
        }

        cout << start << " " << end+1 << endl;
    }

    else if(!f2)
    {
        ll start = -1;
        ll end = -1;

        for(ll i=sz(s)-1; i>=0; i--)
        {
            if(s[i] == 'L')
            {
                if(start == -1)
                {
                    start = i+1;
                }

                end = i+1;
            }
        }

        cout << start << " " << end-1 << endl;
    }

    else
    {
        ll fr = -1;
        ll fl = -1;

        for(ll i=0; i<sz(s); i++)
        {
            if(s[i] == 'R')
            {
                if(fr == -1)
                {
                    fr = i+1;
                }
            }

            else if(s[i] == 'L')
            {
                if(fl == -1)
                {
                    fl = i+1;
                }
            }

        }

        cout << fr << " " << fl-1 << endl;
    }


    return 0;
}