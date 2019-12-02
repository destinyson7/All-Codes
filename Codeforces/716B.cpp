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

ll f[30];
string s;

void print(ll end)
{
    queue <char> needed;

    for(ll i=0; i<26; i++)
    {
        if(f[i] == 0)
        {
            needed.push((char)(i+'A'));
        }
    }

    for(ll i=0; i<end-25; i++)
    {
        if(s[i]=='?')
        {
            cout << 'A';
        }

        else
        {
            cout << s[i];
        }
    }

    for(ll i=end-25; i<=end; i++)
    {
        if(s[i] == '?')
        {
            cout << needed.front();
            needed.pop();
        }

        else
        {
            cout << s[i];
        }
    }

    for(ll i=end+1; i<sz(s); i++)
    {
        if(s[i]=='?')
        {
            cout << 'A';
        }

        else
        {
            cout << s[i];
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;

    if(sz(s) < 26)
    {
        cout << -1 << endl;
        return 0;
    }

    ll start = 0;
    ll end = 0;

    ll cnt = 0;

    while(end<26)
    {
        if(s[end]=='?')
        {
            cnt++;
        }

        else
        {
            f[s[end]-'A']++;

            if(f[s[end]-'A'] == 1)
            {
                cnt++;
            }
        }

        end++;
    }

    if(cnt == 26)
    {
        queue <char> needed;

        for(ll i=0; i<26; i++)
        {
            if(f[i] == 0)
            {
                needed.push((char)(i+'A'));
            }
        }

        for(ll i=0; i<26; i++)
        {
            if(s[i]=='?')
            {
                char temp = needed.front();
                cout << temp;
                needed.pop();
            }

            else
            {
                cout << s[i];
            }
        }

        for(ll i=26; i<sz(s); i++)
        {
            if(s[i]=='?')
            {
                cout << 'A';
            }

            else
            {
                cout << s[i];
            }
        }
        cout << endl;
        
        return 0;
    }

    for(ll i=26; i<sz(s); i++)
    {
        if(s[i-26] == '?')
        {
            cnt--;
        }

        else
        {
            f[s[i-26]-'A']--;

            if(f[s[i-26]-'A'] == 0)
            {
                cnt--;
            }
        }

        if(s[i]=='?')
        {
            cnt++;
        }

        else
        {
            f[s[i]-'A']++;

            if(f[s[i]-'A'] == 1)
            {
                cnt++;
            }
        }

        if(cnt == 26)
        {
            print(i);
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}