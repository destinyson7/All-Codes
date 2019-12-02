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
    
    string s;
    cin >> s;

    if(s[0]==s[1])
    {
        if(s[0]!=s[2] && s[2]==s[3])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    else if(s[0] == s[2])
    {
        if(s[0]!=s[1] && s[1]==s[3])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    else if(s[0] == s[3])
    {
        if(s[0]!=s[1] && s[1]==s[2])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}