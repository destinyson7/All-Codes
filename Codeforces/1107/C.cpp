#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define pq priority_queue
#define endl "\n"

ll a[200005];
ll cnt[1005];
pq < ll, vector<ll>,  greater<ll> > prio_que;
ll flag[200005];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
	}

	string s;
	cin >> s;

	cnt[s[0]]++;
	for(ll j=1; j<n; j++)
	{
		if(s[j]==s[j-1])
		{
			cnt[s[j]]++;
		}

		else
		{
			cnt[s[j-1]]=0;
			cnt[s[j]]=1;
		}

		if(cnt[s[j]]>k)
		{
			flag[s[j]]=1;
		}
	}

	ll dmg = 0;

	char p = s[0];
	prio_que.push(a[0]);

	for(ll b=1; b<n; b++)
	{
		if(s[b]==p)
		{
			prio_que.push(a[b]);
		}

		else
		{
			ll len = prio_que.size();

			while(prio_que.size()>k)
			{
				prio_que.pop();
				len--;
			}

			while(prio_que.empty()!=1)
			{
				dmg+=prio_que.top();
				prio_que.pop();
			}

			p = s[b];
			prio_que.push(a[b]);
		}

		if(b==n-1)
		{
			ll len = prio_que.size();

			while(len>k)
			{
				prio_que.pop();
				len--;
			}

			while(prio_que.empty()!=1)
			{
				dmg+=prio_que.top();
				prio_que.pop();
			}
		}
	}

	cout << dmg << endl;

	return 0;
}