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

    ll start = -1;

    for(ll i=0; i<=len-26; i++)
    {
        set <char> v;
        ll cnt = 0;

        for(ll j=i; j<i+26; j++)
        {
            if(s[j] == '?')
            {
                cnt++;
            }

            else
            {
                v.insert(s[j]);
            }
        }

        if(sz(v) + cnt == 26)
        {
            start = i;
            break;
        }
    }

    if(start == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    set <char> q;

    for(char i='A'; i<='Z'; i++)
    {
        q.insert(i);
    }

    for(ll i=start; i<start+26; i++)
    {
        // if(s[i] == '?')
        // {
        //     cout << *q.begin();
        //     q.erase(q.begin());
        // }

        if(s[i] != '?')
        {
            q.erase(s[i]);
        }
    }

    for(ll i=0; i<start; i++)
    {
        if(s[i] == '?')
        {
            cout << "A";
        }

        else
        {
            cout << s[i];
        }
    }

    for(ll i=start; i<start+26; i++)
    {
        if(s[i] == '?')
        {
            cout << *q.begin();
            q.erase(q.begin());
        }

        else
        {
            cout << s[i];
        }
    }

    for(ll i=start+26; i<len; i++)
    {
        if(s[i] == '?')
        {
            cout << "A";
        }

        else
        {
            cout << s[i];
        }
    }

    cout << endl;

    return 0;
}