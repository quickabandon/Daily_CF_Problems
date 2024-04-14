// Problem: B. Cards Sorting
// Contest: Codeforces - Codeforces Round 424 (Div. 1, rated, based on VK Cup Finals)
// URL: https://codeforces.com/contest/830/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],c[N],l[N],r[N];
typedef long long ll;
int n,m;
vector<int>e[N];

int lowbit(int x){
	return x&(-x);
}

void add(int k,int x){
	for(int i=k;i<=n;i+=lowbit(i))
		c[i]+=x;
}

int ask(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

void solve(){
	cin>>n;
	memset(l,0x3f,sizeof l);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		m=max(m,x);
		e[x].push_back(i);
		l[x]=min(l[x],i),r[x]=max(r[x],i);
	}
	for(int i=1;i<=n;i++)
		add(i,1);
	
	ll ans=0;int p=0;
	for(int i=1;i<=m;i++){
		if(e[i].size()){
			//cout<<i<<"  ";
			sort(e[i].begin(),e[i].end());
			if(p<l[i]){
				ans+=ask(r[i])-ask(p-1);p=r[i];
			}
			else{
				//cout<<p<<"p\n";
				int t=lower_bound(e[i].begin(),e[i].end(),p)-e[i].begin();
				if(t)t--;
				ans+=ask(n)-ask(p);
				p=e[i][t];
				ans+=ask(e[i][t]);
				//cout<<ask(n)<<"as "<<ask(t)<<"ast "<<" ";
			}
			for(int v:e[i]){
				add(v,-1);
			}
			//cout<<ans<<"\n";
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


