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
    
    while(true)
    {
        ll N, M, S;
        cin >> N >> M >> S;

        if(!N && !M && !S)
        {
            return 0;
        }

        ll a[N+5][M+5];

        ll x = 0, y = 0;

        char pos;
        
        for(ll i=0; i<N; i++)
        {
            string s;
            cin >> s;


            for(ll j=0; j<M; j++)
            {
                if(s[j] == '#')
                {
                    a[i][j] = 0;
                }

                else if(s[j] == '*')
                {
                    a[i][j] = 2;
                }

                else if(s[j] == '.')
                {
                    a[i][j] = 1;
                }

                else
                {
                    x = i;
                    y = j;
                    pos = s[j];
                    a[i][j] = 1;
                }

                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }

        ll cnt = 0;

        string ins;
        cin >> ins;

        for(ll i=0; i<sz(ins); i++)
        {
            if(ins[i] == 'D')
            {
                if(pos == 'N')
                {
                    pos = 'L';
                }

                else if(pos == 'S')
                {
                    pos = 'O';
                }

                else if(pos == 'L')
                {
                    pos = 'S';
                }

                else
                {
                    pos = 'N';
                }
            }

            else if(ins[i] == 'E')
            {
                if(pos == 'N')
                {
                    pos = 'O';
                }

                else if(pos == 'S')
                {
                    pos = 'L';
                }

                else if(pos == 'L')
                {
                    pos = 'N';
                }

                else
                {
                    pos = 'S';
                }
            }

            else
            {
                if(pos == 'N')
                {
                    if(x>0 && a[x-1][y])
                    {
                        x--;
                    }
                }

                else if(pos == 'S')
                {
                    if(x<N-1 && a[x+1][y])
                    {
                        x++;
                    }
                }

                else if(pos == 'L')
                {
                    if(y<M-1 && a[x][y+1])
                    {
                        y++;
                    }
                }

                else
                {
                    if(y>0 && a[x][y-1])
                    {
                        y--;
                    }
                }

                if(a[x][y] == 2)
                {
                    a[x][y] = 1;
                    cnt++;
                }
            }

            // cout << x << " " << y << " " << pos << endl;
        }
        
        cout << cnt << endl;
    }


    return 0;
}