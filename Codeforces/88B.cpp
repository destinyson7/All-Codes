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

vector <string> v(35);

ll dis[35];
bool occur[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll n, m, x;
    cin >> n >> m >> x;

    for(ll i=0; i<n; i++)
    {
        cin >> v[i];
    }   

    for(ll i=0; i<26; i++)
    {
        dis[i] = 1e17;
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(v[i][j] == 'S')
            {
                for(ll a=0; a<n; a++)
                {
                    for(ll b=0; b<m; b++)
                    {
                        if(v[a][b] != 'S')
                        {
                            dis[v[a][b] - 'a'] = min(dis[v[a][b]-'a'], (i-a)*(i-a) + (j-b)*(j-b));
                        }
                    }
                }
            }
        }
    }
    
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(v[i][j] != 'S')
            {
                occur[v[i][j] - 'a'] = true;
            }
        }
    }

    ll q;
    cin >> q;

    ll req = 0;

    for(ll i=0; i<q; i++)
    {
        char c;
        cin >> c;

        if(c < 97)
        {
            if(!occur[c+32-'a'] || dis[c+32-'a'] == 1e17)
            {
                // cout << c << " here " << occur[c+32-'a'] << " " << endl;
                cout << -1 << endl;
                return 0;
            }

            else if(occur[c+32-'a'] && dis[c+32-'a'] > x*x)
            {
                req++;
            }

        }

        else
        {
            if(!occur[c-'a'])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << req << endl;

    return 0;
}