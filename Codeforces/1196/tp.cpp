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

// typedef struct coord
// {
//     int x, y;
// };

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char c = 255;

    bool a =  (c>10);

    cout << (int)c << endl;

    if(a)
    {
        cout << "First";
    }

    else
    {
        cout <<" no" << endl; 
    }

    printf("1/2 = %f", (float)(1/2));

    int x = 5, y = 2;

    if(x&y)
    {
        cout << "firsy" << endl;
    }

    std:: vector<std::vector<int>> thematrix;

    return 0;
}