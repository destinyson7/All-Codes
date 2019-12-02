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

const ll L = 505;

ll mat[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll h, w;
    cin >> h >> w;

    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            char c;
            cin >> c;

            if(c=='*')
            {
                mat[i][j] = 1;
            }

            else
            {
                mat[i][j] = 0;
            }
        }
    }

    ll cnt = 0;
    ll r = -1;
    ll c = -1;
    ll flag = 0;

    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            if(i && j && i<h-1 && j<w-1)
            {
                if(mat[i][j]==1 && mat[i-1][j]==1 && mat[i+1][j]==1 && mat[i][j-1]==1 && mat[i][j+1]==1)
                {
                    flag = 1;
                    r = i;
                    c = j;
                    break;
                    // return 0;
                }
            }
        }
    }

    if(!flag)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            if(i!=r && j!=c)
            {
                if(mat[i][j]==1)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    for(ll j=c; j<w; j++)
    {
        if(mat[r][j]==1 && mat[r][j-1]==0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(ll j=c; j>=0; j--)
    {
        if(mat[r][j]==1 && mat[r][j+1]==0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(ll i=r; i<h; i++)
    {
        if(mat[i][c]==1 && mat[i-1][c]==0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(ll i=r; i>=0; i--)
    {
        if(mat[i][c]==1 && mat[i+1][c]==0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}