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

const ll L = 35;
const ll mod = 998244353;

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

ll adjMatrix[L][L];

// Template Source: https://www.geeksforgeeks.org/determinant-of-a-matrix/
// Function to get determinant of matrix   
ll determinantOfMatrix(ll N)   
{   
    ll num1,num2,det = 1,index,total = 1; // Initialize result   
        
    // temporary array for storing row   
    ll temp[N + 1];   
        
    //loop for traversing the diagonal elements  
    for(ll i = 0; i < N; i++)    
    {  
        index = i; // intialize the index   
            
        //finding the index which has non zero value   
        while(adjMatrix[index][i] == 0 && index < N) {   
            index++;       
                
        }   
        if(index == N) // if there is non zero element   
        {   
            // the determinat of matrix as zero   
            continue;   
                
        }   
        if(index != i)   
        {   
            //loop for swaping the diagonal element row and index row   
            for(ll j = 0; j < N; j++)   
            {   
                swap(adjMatrix[index][j],adjMatrix[i][j]);      
            }   
                //determinant sign changes when we shift rows   
                //go through determinant properties   
                det = det*pow(-1,index-i);     

                // cout << det << endl;
       }   
           
       //storing the values of diagonal row elements   
       for(ll j = 0; j < N; j++)   
       {   
           temp[j] = adjMatrix[i][j];   
               
       }   
       //traversing every row below the diagonal element   
       for(ll j = i+1; j < N; j++)   
       {   
           num1 = temp[i]; //value of diagonal element   
           num2 = adjMatrix[j][i]; //value of next row element   
               
           //traversing every column of row   
           // and multiplying to every row   
           for(ll k = 0; k < N; k++)   
           {   
               //multiplying to make the diagonal   
               // element and next row element equal   
               adjMatrix[j][k] = (num1 * adjMatrix[j][k]) - (num2 * temp[k]); 
               adjMatrix[j][k]%=mod; 
               adjMatrix[j][k] = (adjMatrix[j][k]+2*mod)%mod;     
           }   

           // cout << j << " " << num1 << endl;
           total = (total * num1)%mod; // Det(kA)=kDet(A);   
            // cout << total << endl;
           }   
            
    }   
    
    //mulitplying the diagonal elements to get determinant   
    for(ll i = 0; i < N; i++)   
    {   
        det = (det * adjMatrix[i][i])%mod;   
            
    }  
    // cout << total << endl;
    // Fermat's Theorem
    return (total ? det*modexp(total, mod-2, mod) : 0)%mod; //Det(kA)/k=Det(A);   
    }   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        ll N, M, K;
        cin >> N >> M >> K;

        for(ll i=0; i<L; i++)
        {
            for(ll j=0; j<L; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }

        // Using Kirchoff's Theorem to calculate the number of spanning trees in a graph

        // Logic Source: https://pdfs.semanticscholar.org/d032/1ff6d99626b488e7ef7d97af82df329d95ae.pdf
        // Followed steps as it is given in the above research paper

        for(ll i=0; i<M; i++)
        {
            ll a, b;
            cin >> a >> b;

            adjMatrix[a-1][a-1]++;
            adjMatrix[b-1][b-1]++;

            assert(a != b);
            
            if(a != b)
            {
                adjMatrix[b-1][a-1]--;
                adjMatrix[a-1][b-1]--;
            }
        }

        for(ll i=0; i<N; i++)
        {
            adjMatrix[i][i]-=(N*K);
        }

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<N; j++)
            {
                if(adjMatrix[i][j] > 0)
                {
                    adjMatrix[i][j] = mod - adjMatrix[i][j];
                }

                else
                {
                    adjMatrix[i][j] = -adjMatrix[i][j];
                }

                adjMatrix[i][j]%=mod;
                adjMatrix[i][j] = (adjMatrix[i][j] + 2*mod)%mod;

                // cout << adjMatrix[i][j] << " ";
            }
            // cout << endl;
        }

        ll determinant = determinantOfMatrix(N);

        // cout << determinant << endl;
        determinant = modexp(determinant, K, mod);

        ll div = modexp(N*K, mod-3, mod);

        // cout << div << endl;

        cout << (determinant*div)%mod << endl;
    }


    return 0;
}