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
    
    string f, s;
    cin >> f >> s;

    ll a = sz(f);
    ll b = sz(s);

    if(a < b)
    {
        cout << "need tree" << endl;
        return 0;
    }

    swap(a, b);
    swap(f, s);

    if(a == b)
    {
        multiset <char> c, d;
        
        for(ll i=0; i<sz(f); i++)
        {
            c.insert(f[i]);
        }

        for(ll j=0; j<sz(s); j++)
        {
            d.insert(s[j]);
        }

        if(c == d)
        {
            cout << "array" << endl;
        }

        else
        {
            cout << "need tree" << endl;
        }
    }

    else
    {

        map <char, deque <ll> > m;

        for(ll i=0; i<b; i++)
        {
            m[s[i]].pb(i);
        }

        // ll prev = -1;
        bool flag = true;

        for(ll i=0; i<a; i++)
        {
            if(m[f[i]].empty())
            {
                cout << "need tree" << endl;
                return 0;
            }

            // ll temp = m[f[i]].front();

            // cout << temp << endl;

            // if(temp < prev)
            // {
            //     flag = false;
            // }

            m[f[i]].pop_front();
            // prev = temp;
        }

        ll end = 0;

        for(ll i=0; i<a; i++)
        {
            if(end == b)
            {
                flag = false;
                break;
            }

            while(s[end]!=f[i])
            {
                end++;

                if(end == b)
                {
                    flag = false;
                    break;
                }
            }

            if(!flag)
            {
                break;
            }

            end++;
        }

        if(flag)
        {
            cout << "automaton" << endl;
        }

        else
        {
            cout << "both" << endl;
        }
    }


    return 0;
}