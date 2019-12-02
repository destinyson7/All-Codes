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
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    string t = "ABC";

    do
    {
        map <char, ll> m;

        m[t[0]] = 0;
        m[t[1]] = 1;
        m[t[2]] = 2;

        if(s1[1] == '>')
        {
            if(m[s1[0]] < m[s1[2]])
            {
                continue;
            }
        }

        else
        {
            if(m[s1[0]] > m[s1[2]])
            {
                continue;
            }
        }

        if(s2[1] == '>')
        {
            if(m[s2[0]] < m[s2[2]])
            {
                continue;
            }
        }

        else
        {
            if(m[s2[0]] > m[s2[2]])
            {
                continue;
            }
        }

        if(s3[1] == '>')
        {
            if(m[s3[0]] < m[s3[2]])
            {
                continue;
            }
        }

        else
        {
            if(m[s3[0]] > m[s3[2]])
            {
                continue;
            }
        }

        cout << t << endl;
        return 0;

    } while(next_permutation(all(t)));

    cout << "Impossible" << endl;

    return 0;
}