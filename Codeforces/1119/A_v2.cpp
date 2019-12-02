#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

vector <int> v[300001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;


	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v[a].pb(i);
	}

	int mi=INT_MAX, smi, ma=-INT_MAX, sma= 0, midx, madx;
	for(int i=1;i<n+1;i++){
		if(v[i].size()==0) continue;
		sort(v[i].begin(), v[i].end());

		if(mi>=v[i][0]){
			smi = mi;
			mi = v[i][0];
		}
		else if(smi>=v[i][0])
			smi = v[i][0];
		
		if(ma<=v[i][v[i].size()-1]){
			sma = ma;
			ma = v[i][v[i].size()-1];
		}
		else if(sma<=v[i][v[i].size()-1])
			sma = v[i][v[i].size()-1];
	
	}
	
	int ans = INT_MIN;
	for(int i=1;i<n+1;i++){
		if(v[i].size()==0) continue;

		int st=mi, en=ma;
		//need max from onther
		st = v[i][0];
		if(v[i][v[i].size()-1] == ma) en = sma;
		ans = max(ans, en-st);

		if(v[i][0] == mi) st = smi, en = v[i][v[i].size()-1];
		ans = max(ans, en-st);
	}
	
	cout << ans << endl;
	return 0;
}