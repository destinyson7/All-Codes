#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    set <ll> s;
    deque <ll> q;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(a[i])==s.end())
        {
            s.insert(a[i]);
            q.push_front(a[i]);
            if (q.size()>k)
            {
                ll t=q.back();
                s.erase(t);
                q.pop_back();
                
            }
        }
    }
    cout << q.size()<<"\n";
    while(!q.empty())
    {
        cout << q.front()<<" ";
        q.pop_front();
    }
    return 0;
}