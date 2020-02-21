#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
ll bookDone[100001], libDone[100001], s[100001];
vector<pair<ll, ll>> liborder;
vector<ll> libBook[100001];
ll freq[100001];
bool comp(ll a, ll b) {
    return freq[a] < freq[b];
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll b, l, d, num = 0, j;
    cin>>b>>l>>d;
    ll i;
    for(i=0; i<b; i++) {
        cin>>s[b];
    }
    vector<pair<double, ll>> score(l);
    vector<ll> books[l];
    ll libraries[l][3];
    for(i=0; i<l; i++) {
        ll n, t, m, temp;
        cin>>n>>t>>m;
        libraries[i][0] = n;
        libraries[i][1] = m;
        libraries[i][2] = t;
        while(n--) {
            cin>>temp;
            books[i].pb(temp);
            freq[temp]++;
        }
        score[i].ff = (double)(n - m)/(double)t;
        score[i].ss = i;
    }
    ll days = 0;
    while(1) {
        if(score.size() == 0) {
            break;
        }
        sort(all(score));
        reverse(all(score));
        ll cur = score[0].ss;
        
        days += libraries[cur][2];
        ll days_left = d - days;
        ll allowed = min(days_left*libraries[cur][1], libraries[cur][0]);
        sort(all(books[cur]), comp);
        vector<ll> temp;
        for(i=0; i<allowed; i++) {
            temp.pb(books[cur][i]);
        }
        books[cur].clear();
        books[cur] = temp;
        for(auto u: books[cur]) {
            bookDone[u] = 1;
        }
        if(books[cur].size() == 0) {
            break;
        }
        liborder.pb(mp(cur, books[cur].size()));
        libDone[cur] = 1;
        libBook[num] = books[cur];
        score.clear();
        num++;
        for(i=0; i<l; i++) {
            if(!libDone[i]) {
                if(days + libraries[i][2] > d) {
                    continue;
                }
                vector<ll> temp = books[i];
                books[i].clear();
                for(auto u: temp) {
                    if(!bookDone[u]) {
                        books[i].pb(u);
                    }
                }
                libraries[i][0] = books[i].size();
                score.pb(mp((double)(libraries[i][1] + libraries[i][0])/(double)libraries[i][2], i));
            }
        }
    }
    cout<<num<<"\n";
    for(i=0; i<num; i++) {
        cout<<liborder[i].ff<<" "<<liborder[i].ss<<"\n";
        for(auto u: libBook[i]) {
            cout<<u<<" ";   
        }
        cout<<"\n";
    }
}