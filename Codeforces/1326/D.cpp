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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 1e5+5;

bool isPalindrome(string s)
{
    ll len = sz(s);

    for(ll i=0; i<len/2; i++)
    {
        if(s[i] != s[len-1-i])
        {
            return false;
        }
    }

    return true;
}

ll longest_palindrome_prefix(const string &s) 
{
        /**
         * The LPS computation can determine, at any given index i in a string S, the maximum suffix length that
         * make up a suffix equal to the prefix. For example: S = "acexxxaceyyy": at S[6], S[7], and S[8] will be
         * marked with "1", "2", and "3" respectively because "a", "ac", and "ace" at this points in the string
         * make up substrings whose suffixes equal to the string's prefix. This computation can be done in one
         * linear scan of the string in O(N) time, using a secondary integer array in O(N) space.
         * 
         * For our purpose in finding the longest palindrome prefix of a string, the idea is simple:
         * if we reverse the string, then appending it to the original string (after a special marker),
         * the palindromic prefix will show up at the end of the compound string! If we then apply the above algorithm,
         * by the end of the linear scan, we'll have a number that correspond to the maximum suffix length of
         * the entire compound string, which correspond to a suffix = prefix. And since a palindromic prefix, when
         * reversed and appended, will show up as the suffix, we will conveniently have computed the maximum
         * length of the palindromic prefix!
         * 
         * For example: consider the string S = "abbaaax". The longest palindrome prefix is "abba".
         * 1. Create S' = "abbaaax#xaaabba"
         * 2. Compute LPS: lps[] = { 0,  0,  0,  1,  1,  1,  0,  0,  0,  1,  1,  1,  2,  3,  4 }
         *            from  S'[] = {'a','b','b','a','a','a','x','#','x','a','a','a','b','b','a'}
         * 3. The last element of LPS, 4, is our longest palindrome prefix length!
         */
        string kmprev = s;
        reverse(kmprev.begin(), kmprev.end());
        string kmp = s + "#" + kmprev;

        vector<int> lps(kmp.size(), 0);   // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
        for (int i = 1; i < (int)lps.size(); ++i)
        {
            int prev_idx = lps[i - 1];

            while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
            {
                prev_idx = lps[prev_idx - 1];
            }

            lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
        }

        // after KMP's LPS preprocessing, the last index of the LPS array will contain the longest palindrome prefix' length!
        return lps[lps.size() - 1];
}

void solve()
{
    string s;
    cin >> s;

    ll n = sz(s);

    // if(n == 1)
    // {
    //     cout << s << endl;
    //     return;
    // }

    string ans = "";

    ans = s.substr(0, longest_palindrome_prefix(s));

    // cout << "1 " << ans << endl;

    string suff = "";

    string reversed = s;
    reverse(all(reversed));

    string ans2 = reversed.substr(0, longest_palindrome_prefix(reversed));
    reverse(all(ans2));

    // cout << "2 " << ans2 << endl;

    if(sz(ans2) > sz(ans))
    {
        ans = ans2;
    }

    ll l=0, r=n-1;

    while(l<=r && s[l]==s[r])
    {
        r--, l++;
    }

    string ff = s.substr(0, l);
    string ss = (r+1 < n ? s.substr(r+1, l) : "");

    // cout << ff << " " << ss  << " " << mp(l, r) << endl;

    string rem = "";

    for(ll i=l; i<=r; i++)
    {
        rem += s[i];
    }

    string ans3 = rem.substr(0, longest_palindrome_prefix(rem));
    // cout << "3 " << ff + ans3 + ss << endl;

    if(sz(ans3) > 0 && sz(ans3) > sz(ans)-2*l)
    {
        ans = ff + ans3 + ss;
    }

    string reversed_rem = rem;
    reverse(all(reversed_rem));

    string ans4 = reversed_rem.substr(0, longest_palindrome_prefix(reversed_rem));
    reverse(all(ans4));

    // cout << "4 " << ff + ans4 + ss << endl;

    if(sz(ans4) > 0 && sz(ans4) > sz(ans)-2*l)
    {
        ans = ff + ans4 + ss;
    }

    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}