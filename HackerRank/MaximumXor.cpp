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

ll a[L];

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
    for(ll i=31; i>=0; i--)
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
    for(ll i=31; i>=0; i--)
    {
        ll bit = (num>>i)&1;

        // cout << bit << " ";

        if(bit)
        {
            if(cur->left)
            {
                // cout << i << endl;
                ans+=(1<<i);

                cur = cur->left;
            }

            else
            {
                cur = cur->right;
            }
        }

        else
        {
            if(cur->right)
            {
                ans+=(1<<i);

                cur = cur->right;
            }

            else
            {
                cur = cur->left;
            }
        }

        // cout << ans << endl;
    }
    // cout << endl;

    return ans;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    node* head = newNode();

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        
        head = insert(head, a[i]);
    }

    ll m;
    cin >> m;

    while(m--)
    {
        ll num;
        cin >> num;

        cout << query(head, num) << endl;
    }

    return 0;
}