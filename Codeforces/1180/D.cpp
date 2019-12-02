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

map <pll, ll> flag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    ll sr = 1;
    ll er = n;
    ll sc = 1;
    ll ec = m;

    if(m!=1)
    {
        while(1)
        {
            // if(!flag[mp(sr, sc)])
            // {
                cout << sr << " " << sc << endl;
            // }

            // else
            // {
            //     break;
            // }

            if(sr!=er || sc!=ec)
            {
                cout << er << " " << ec << endl;
            }

            sr++;
            er--;
            
            // cout << "brr " << sr << " " << er << " " << sc << " " << sc << endl;

            if(sr==n+1)
            {
                sc++;
                ec--;

                sr = 1;
                er = n;
            }

            if(sc>=ec || ec<=0 || sc>m || sr>n || er<=0)
            {
                break;
            }
        }
    }

    if(m&1)
    {
        ll c = m/2 + 1;

        ll sr = 1;
        ll er = n;

        while(1)
        {
            cout << sr << " " << c << endl;
            
            if(sr!=er)
            {
                cout << er << " " << c << endl;
            }

            sr++;
            er--; 

            if(sr>er)
            {
                break;
            }
        }
    }

    return 0;
}