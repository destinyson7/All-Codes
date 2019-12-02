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
    
    ll N;
    cin >> N;

    cout << "INTERSECTING LINES OUTPUT" << endl;

    for(ll i=0; i<N; i++)
    {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if(x1 == x2)
        {
            if(x3 == x4)
            {
                double c1 = x1;
                double c2 = x3;

                if(c1 == c2)
                {
                    cout << "LINE" << endl;
                }

                else
                {
                    cout << "NONE" << endl;
                }
            }

            else
            {
                double ansx = (double)x1;
                double ansy = (double)(y4-y3)/(x4-x3);
                ansy*=(double)(ansx-x3);
                ansy+=(double)y3;

                cout << "POINT " << fixed << setprecision(2) << ansx << " " << ansy << endl;
            }
        }

        else
        {
            if(x3 == x4)
            {
                double ansx = (double)x3;
                double ansy = (double)(y2-y1)/(x2-x1);
                ansy*=(double)(ansx-x1);
                ansy+=(double)y1;
                
                cout << "POINT " << fixed << setprecision(2) << ansx << " " << ansy << endl;
            }

            else
            {
                double m1 = (double)(y2-y1)/(x2-x1);
                double m2 = (double)(y4-y3)/(x4-x3);

                if(m1 == m2)
                {
                    double c1 = y1 - m1*x1;
                    double c2 = y3 - m2*x3;

                    if(c1 == c2)
                    {
                        cout << "LINE" << endl;
                    }

                    else
                    {
                        cout << "NONE" << endl;
                    }
                    
                    continue;
                }

                double ansx = ((double)(y2-y1)/(x2-x1))*(double)x1 + y3 - y1 - ((double)(y4-y3)/(x4-x3))*(double)x3;
                ansx/=(m1-m2);

                double ansy = (double)(y2-y1)/(x2-x1);
                ansy*=(double)(ansx-x1);
                ansy+=(double)y1;
                
                cout << "POINT " << fixed << setprecision(2) << ansx << " " << ansy << endl;
            }
        }
    }

    cout << "END OF OUTPUT" << endl;


    return 0;
}