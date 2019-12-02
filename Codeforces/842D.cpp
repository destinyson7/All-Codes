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

const ll L = 1<<22;

ll a[L];
ll done[L];

typedef struct node
{
    node* left;
    node* right;
} node;

node* newNode()
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* insert(node* head, ll num)
{
    node* cur = head;
    for(ll i=20; i>=0; i--)
    {
        ll bit = (num>>i)&1;
        
        if(bit)
        {
            if(!cur->right)
            {
                cur->right = newNode();
            }

            cur = cur->right;
        }

        else
        {
            if(!cur->left)
            {
                cur->left = newNode();
            }

            cur = cur->left;
        }
    }

    return head;
}

ll query(node* head, ll num)
{
    node* cur = head;

    ll ans = 0;
    // ll max_xor = -1e15;
    for(ll i=20; i>=0; i--)
    {
        ll bit = (num>>i)&1;

        // cout << bit << " ";

        if(bit)
        {
            if(cur->right)
            {
                // cout << i << endl;
                // ans+=(1<<i);

                cur = cur->right;
            }

            else
            {
                ans+=(1<<i);
                cur = cur->left;
            }
        }

        else
        {
            if(cur->left)
            {
                // ans+=(1<<i);

                cur = cur->left;
            }

            else
            {
                ans+=(1<<i);

                cur = cur->right;
            }
        }

        // cout << ans << endl;
    }
    // cout << endl;

    return ans;
}

const ll M = 1<<22;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    node* head = newNode();

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        
        done[a[i]] = 1;
        // head = insert(head, a[i]);
    }

    // sort(a, a+n);

    ll cur_idx = 0;

    for(ll i=0; i<(M>>1); i++)
    {
        if(!done[i])
        {
            head = insert(head, i);
        }
    }

    ll cur_xor = 0;
    while(m--)
    {
        ll x;
        cin >> x;

        cur_xor^=x;

        cout << query(head, cur_xor) << endl;
    }

    return 0;
}