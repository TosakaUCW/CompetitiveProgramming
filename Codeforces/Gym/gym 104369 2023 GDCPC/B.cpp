#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long value;
} tree[2000100];
void make_tree(int lo,int l,int r){
    tree[lo].l=l;
    tree[lo].r=r;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    make_tree(lo<<1,l,mid);
    make_tree(lo<<1|1,mid+1,r);
    return;
}
void clear_tree(int lo){
    tree[lo].value=0x3f3f3f3f3f3f3f3f;
    if(tree[lo].l==tree[lo].r){
        return;
    }
    clear_tree(lo<<1);
    clear_tree(lo<<1|1);
    return;
}
void insert(int lo,int pos,int val){
    if(tree[lo].l==tree[lo].r){
        tree[lo].value=val;
        return;
    }
    int mid=tree[lo].l+tree[lo].r>>1;
    if(pos<=mid){
        insert(lo<<1,pos,val);
    }
    else{
        insert(lo<<1|1,pos,val);
    }
    tree[lo].value=min(tree[lo<<1].value,tree[lo<<1|1].value);
    return;
}
long long find(int lo,int l,int r){
    if(tree[lo].l>=l && r<=tree[lo].r){
        return tree[lo].value;
    }
    int mid=tree[lo].l+tree[lo].r>>1;
    long long ans=0x3f3f3f3f3f3f3f3f;
    if(l<=mid){
        ans=min(ans,find(lo<<1,l,r));
    }
    if(r>mid){
        ans=min(ans,find(lo<<1|1,l,r));
    }
    return ans;
}
pair<pair<int,int>,int> a[500005];
pair<pair<int,int>,int> b[500005];
long long cost[500005];
long long dp[500005];
long long inf=1145141919810;
int main(){
    make_tree(1,1,500005);
    int t;
    scanf("%d",&t);
    while(t--){
        insert(1,0,0);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&cost[i]);
            dp[i]=inf;
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a[i].first.second,&a[i].first.first);
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++){
            a[i].second=i;
            b[i]=a[i];
            swap(b[i].first.first,b[i].first.second);
        }
        sort(b+1,b+m+1);
        stack<pair<pair<int,int>,int> > st;
        int ind=1;
        for(int i=1;i<=n;i++){
            while(i==b[ind].first.first){
                st.push(b[ind++]);
            }
            while(!st.empty() && st.top().first.second<i){
                st.pop();
            }
            insert(1,i,find(1,a[ind-st.size()].first.second,a[ind-st.size()].first.first)+cost[i]);
//            cout<<find(1,i,i)<<endl;
            cout<<st.size()<<endl;
        }
        printf("%lld\n",find(1,a[m].first.second,a[m].first.first));
    }
    return 0;
}