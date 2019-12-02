#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll L;
    cin >> L;

    string A;
    cin >> A;

    ll len = sz(A);

    if(len%L == 0)
    {
        bool f = true;
        for(ll i=0; i<len; i++)
        {
            if(A[i] != '9')
            {
                f = false;
                break;
            }
        }

        if(f)
        {
            ll mini = len+1;

            ll parts = mini/L;

            if(mini%L)
            {
                parts++;
            }

            string s = "1";
            for(ll i=0; i<L-1; i++)
            {
                s+="0";
            }

            for(ll i=0; i<parts; i++)
            {
                cout << s;
            }
            cout << endl;
        }

        else
        {
            ll check = 0;

            for(ll i=1; i<len/L; i++)
            {
                for(ll j=0; j<L; j++)
                {
                    if(A[j] > A[L*i+j])
                    {
                        check = 1;
                        break;
                    }

                    else if(A[j] < A[L*i+j])
                    {
                        check = 2;
                        break;
                    }
                }

                if(check > 0)
                {
                    break;
                }
            }

            if(!check)
            {
                check = 2;
            }

            if(check == 2)
            {
               ll i=L-1;
                for(i=L-1; i>=0; i--)
                {
                    if(A[i] == '9')
                    {
                        A[i] = '0';
                    }

                    else
                    {
                        A[i]++;
                        break;
                    }
                }

                string s = "";
                for(ll j=0; j<L; j++)
                {
                    s+=A[j];
                }

                ll parts = len/L;

                for(ll i=0; i<parts; i++)
                {
                    cout << s;
                }
                cout << endl;
                
            }

            else
            {
                ll parts = len/L;

                string s = "";

                for(ll i=0; i<L; i++)
                {
                    s+=A[i];
                }

                for(ll i=0; i<parts; i++)
                {
                    cout << s;
                }
                cout << endl;
            }
        }
            
    }

    else
    {
        ll parts = len/L + 1;

        string s = "1";
        for(ll i=0; i<L-1; i++)
        {
            s+="0";
        }

        for(ll i=0; i<parts; i++)
        {
            cout << s;
        }
        cout << endl;
    }


    return 0;
}