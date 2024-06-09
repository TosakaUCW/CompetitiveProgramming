#include<bits/stdc++.h>
using namespace std;
const int N =105;
int a[10005];
signed main(){
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        int x,y1;
        cin>>y1;
        int n;cin>>n;
        
        
        for(int i=1;i<=n;i++){
            cin>>x;
            a[x]++;
        }
        int y2;
        cin>>y2;
        int ans=y2-y1+1;
        for(int j=y1;j<=y2;j++){
            if(a[j]>0) ans--;
        }
        cout<<ans<<endl;

    }
}