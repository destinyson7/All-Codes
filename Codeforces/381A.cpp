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
    
    ll n;
    cin >> n;

    ll left = 0;
    ll right = n-1;

    vector <ll> a(n+5, 0);

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll f = 0;
    ll s = 0;

    while(left<=right)
    {
        if(a[left] > a[right])
        {
            f+=a[left];
            left++;
        }

        else
        {
            f+=a[right];
            right--;
        }

        if(left>right)
        {
            break;
        }

        if(a[left] > a[right])
        {
            s+=a[left];
            left++;
        }

        else
        {
            s+=a[right];
            right--;
        }
    }

    cout << f << " " << s << endl;


    return 0;
}