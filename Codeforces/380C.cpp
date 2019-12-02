#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e6+5;

string s;

typedef struct node
{
	ll pre;
	ll ans;
	ll suf;

} node;

vector <node> seg(4*L);

void make(ll i, ll tl, ll tr)
{
	// cout << i << endl;

	if(tl==tr)
	{
		if(s[tl]=='(')
		{
			seg[i].pre = 1;
			seg[i].ans = 0;
			seg[i].suf = 0;
		}

		else
		{
			seg[i].pre = 0;
			seg[i].ans = 0;
			seg[i].suf = 1;
		}

		return;
	}

	ll mid = tl + (tr-tl)/2;

	make(i<<1, tl, mid);
	make(i<<1|1, mid+1, tr);

	ll x = min(seg[i<<1].pre, seg[i<<1|1].suf);
	seg[i].ans = seg[i<<1].ans + seg[i<<1|1].ans + 2*x;
	seg[i].pre = seg[i<<1].pre + seg[i<<1|1].pre - x; 
	seg[i].suf = seg[i<<1].suf + seg[i<<1|1].suf - x;
}

node temp;

node query(ll i, ll tl, ll tr, ll l, ll r)
{
	if(r<tl || l>tr)
	{
		return temp;
	}

	if(l<=tl && tr<=r)
	{
		return seg[i];
	}

	ll mid = tl + (tr-tl)/2;

	node left = query(i<<1, tl, mid, l, r);
	node right = query(i<<1|1, mid+1, tr, l, r);

	node toRet;
	ll x = min(left.pre, right.suf);
	toRet.ans = left.ans + right.ans + 2*x;
	toRet.pre = left.pre + right.pre - x; 
	toRet.suf = left.suf + right.suf - x;

	return toRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// string s;
	cin >> s;

	s = '#' + s;

	ll len = s.length();

	make(1, 1, len);

	ll m;
	cin >> m;

	while(m--)
	{
		ll l, r;
		cin >> l >> r;

		cout << query(1, 1, len, l, r).ans << endl;		
	}

	return 0;
}