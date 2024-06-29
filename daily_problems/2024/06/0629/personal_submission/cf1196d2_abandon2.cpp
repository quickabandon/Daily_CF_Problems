#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char c[]={'R','G','B'};
int f[N][3];

void solve(){
    int n,k;cin>>n>>k;
    string s,r[3];
    r[0]=' '+r[0];
    r[1]=' '+r[1];
    r[2]=' '+r[2];

    cin>>s;s+=' ';
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<3;j++)
            f[i][j]=0;
    }

    int t=0;
    for(int i=1;i<=n*2+1;i++){
        for(int j=0;j<3;j++)
            r[j]+=c[(j+t)%3];
        t++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            f[i][j]=(r[j][i]!=s[i]);
            f[i][j]+=f[i-1][j];
           // cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
        }
    }

    int ans=N;
    for(int i=k;i<=n;i++){
        for(int j=0;j<3;j++){
            ans=min(ans,f[i][j]-f[i-k-1][j]);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
