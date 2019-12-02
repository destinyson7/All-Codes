#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <char> op = {'|', '&', '^'};

char evaluate(char E1, char O, char E2)
{
    ll first = 0;

    if(E1 == '1')
    {
        first = 1;
    }

    else if(E1 == 'x')
    {
        first = 7;
    }

    else if(E1 == 'X')
    {
        first = -8;
    }    

    ll second = 0;

    if(E2 == '1')
    {
        second = 1;
    }

    else if(E2 == 'x')
    {
        second = 7;
    }

    else if(E2 == 'X')
    {
        second = -8;
    }

    ll res = 0;

    if(O == '|')
    {
        res = (first | second);
    }

    else if(O == '&')
    {
        res = (first & second);
    }

    else
    {
        res = (first^second);
    }

    if(res == 7)
    {
        return 'x';
    }

    else if(res == -8)
    {
        return 'X';
    }

    else if(res == 0)
    {
        return '0';
    }

    else
    {
        return '1';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll i=1; i<=T; i++)
    {
        string s;
        cin >> s;

        ll len = sz(s);

        // cout << i << " len: " << len << endl;

        if(len == 1)
        {
            if(s == "1" || s == "0")
            {
                cout << "Case #" << i << ": " << 0 << endl;
            }

            else
            {
                cout << "Case #" << i << ": " << 1 << endl;            
            }

            continue;
        }

        vector <char> ans;

        for(ll j=0; j<len; j++)
        {
            ans.pb(s[j]);

            ll cur = sz(ans);

            if(s[j] == ')')
            {
                ans[cur-5] = evaluate(ans[cur-4], ans[cur-3], ans[cur-2]);
               
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            }
        }

        // cout << i << " remaining " << ans[0] << endl;

        if(ans[0] == '1' || ans[0] == '0')
        {
            cout << "Case #" << i << ": " << 0 << endl;
        }

        else
        {
            cout << "Case #" << i << ": " << 1 << endl;
        }
    }

    return 0;
}