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

bool rows(char grid[3][3], char c)
{
    for(ll i=0; i<3; i++)
    {
        if(grid[i][0]==c && grid[i][1]==c && grid[i][2]==c)
        {
            return true;
        }
    }

    return false;
}

bool cols(char grid[3][3], char c)
{
    for(ll i=0; i<3; i++)
    {
        if(grid[0][i]==c && grid[1][i]==c && grid[2][i]==c)
        {
            return true;
        }
    }

    return false;
}

bool diags(char grid[3][3], char c)
{
    if(grid[0][0]==c && grid[1][1]==c && grid[2][2]==c)
    {
        return true;
    }

    if(grid[0][2]==c && grid[1][1]==c && grid[2][0]==c)
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;


    while(N--)
    {
        ll x = 0, o = 0;
        char grid[3][3];

        for(ll i=0; i<3; i++)
        {
            for(ll j=0; j<3; j++)
            {
                cin >> grid[i][j];
                
                if(grid[i][j] == 'X')
                {
                    x++;
                }

                else if(grid[i][j] == 'O')
                {
                    o++;
                }

            }
        }

        bool ok = true;

        if(o > x)
        {
            ok = false;
        }

        if(x - o > 1)
        {
            ok = false;
        }

        bool a = false, b = false;

        if(rows(grid, 'X') || cols(grid, 'X') || diags(grid, 'X'))
        {
            a = true;

            if(x-o != 1)
            {
                ok = false;
            }
        }

        if(rows(grid, 'O') || cols(grid, 'O') || diags(grid, 'O'))
        {
            b = true;


            if(x-o != 0)
            {
                ok = false;
            }
        }

        if(a && b)
        {
            ok = false;
        }

        if(ok)
        {
            cout << "yes" << endl;
        }

        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}