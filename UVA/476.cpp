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

const ll L = 1e1+5;

typedef struct rectangle
{
    float x1, y1, x2, y2;
} rectangle;

rectangle r[L];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    // ll n;
    // cin >> n;
    
    ll i = 0;

    while(true)
    {
        char c;

        cin >> c;

        if(c == '*')
        {
            break;
        } 

        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        i++;

        // cout << "i " << i << endl;
    }

    ll pt = 0;

    while(true)
    {
        pt++;

        float a, b;
        cin >> a >> b;

        // cout << a << " " << b << endl;
        
        if(a == (float)9999.9 && b == (float)9999.9)
        {
            break;
        }

        bool f = false;

        for(ll j=0; j<i; j++)
        {
            if(a>r[j].x1 && b<r[j].y1 && a<r[j].x2 && b>r[j].y2)
            {
                f = true;

                cout << "Point " << pt << " is contained in figure " << j+1 << endl;
            }
        }

        if(!f)
        {
            cout << "Point " << pt << " is not contained in any figure" << endl;
        }
    }


    return 0;
}