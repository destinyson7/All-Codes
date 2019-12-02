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

    ll all = sz(s);

    ll a = 0, b = 0;

    for(ll i=0; i<all; i++)
    {
        if(s[i] == '|')
        {
            a = i;
            b = all-i-1;
            break;
        }
    }

    string rem;
    cin >> rem;

    ll d = sz(rem);
    ll e = d;

    if(a<=b)
    {
        if(b-a > d)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        
        d-=(b-a);
        ll cnt = b-a;

        if(d&1)
        {
            cout << "Impossible" << endl;
            return 0;
        }

        else
        {
            cnt+=d/2;

            bool f = false;
            ll cur = 0;

            for(ll i=0; i<all; i++)
            {
                if(!f && s[i]=='|')
                {
                    for(ll t=0; t<cnt; t++)
                    {
                        cout << rem[t];
                    }
                }

                cout << s[i];
            }

            for(ll t=cnt; t<e; t++)
            {
                cout << rem[t];
            }
            cout << endl;
        }
    }

    else
    {
        // cout << "here1" << endl;
        if(a-b > d)
        {
            // cout << "here2" << endl;
            cout << "Impossible" << endl;
            return 0;
        }
        
        d-=(a-b);
        ll cnt = a-b;

        if(d&1)
        {
            // cout << d << " here3" << endl;
            cout << "Impossible" << endl;
            return 0;
        }

        else
        {
            cnt+=d/2;

            bool f = false;
            ll cur = 0;

            // cout << d << " " << cnt << endl;    

            cnt = e - cnt;

            // cout << cnt << endl;

            for(ll i=0; i<all; i++)
            {
                if(!f && s[i]=='|')
                {
                    for(ll t=0; t<cnt; t++)
                    {
                        cout << rem[t];
                    }
                }

                cout << s[i];
            }

            for(ll t=cnt; t<e; t++)
            {
                cout << rem[t];
            }
            cout << endl;
        }
    }


    return 0;
}