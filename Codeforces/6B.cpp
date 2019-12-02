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

const ll L = 1e2+5;

char grid[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    char c;

    cin >> n >> m >> c;    

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        for(ll j=0; j<m; j++)
        {
            grid[i][j] = s[j];
        }
    }

    set <char> s;

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(grid[i][j] == c)
            {
                if(i && grid[i-1][j]!='.')
                {
                    s.insert(grid[i-1][j]);
                }

                if(i<n-1 && grid[i+1][j]!='.')
                {
                    s.insert(grid[i+1][j]);
                }

                if(j && grid[i][j-1]!='.')
                {
                    s.insert(grid[i][j-1]);
                }

                if(j<m-1 && grid[i][j+1]!='.')
                {
                    s.insert(grid[i][j+1]);
                }
            }
        }
    }

    s.erase(c);

    cout << sz(s) << endl;

    return 0;
}