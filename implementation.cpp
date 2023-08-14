#include <bits/stdc++.h>
using namespace std;
 
//----------------------------SHORTCUTS---------------------------------------------
#define ll                  long long
#define ld                  long double
#define int                 ll
const int mod=               1e9+7;
const long double PI =      3.14159265358979323846264338;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define endl "\n"
#define mii                 map<int,int>
#define veci                vector<int>
typedef pair<int,int>       pii; 
#define all(v)              v.begin(),v.end()
#define rall(v)             v.rbegin(),v.rend()
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define take(x)             for(auto &y:x) cin>>y
#define show(x)             for(auto y:x) cout<<y<<" ";cout<<endl;
#define pb                  push_back  
 

 
// segment tree
class SGTree{
    vector<int>seg;
    SGTree(int n){
        seg.resize(4*n);
    }
    void build(int ind,int low,int high,vector<int>arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
        
    }
    int query(int ind,int low,int high,int l,int r){
        // no overlap
        // l r low high     low high l r
        if(r<low || high <l){
            return INT_MAX;
        }
        // complete overlap
        // [l low high r]
        if(l<=low && high=r){
            return seg[ind];
        }
        int mid=(low+high)/2;
        int left = query(2*ind+1,low ,mid, l, r);
        int right = query(2*ind+2,mid+1 ,high, l, r);
        
        return min(left,right);
    }
    void update(int ind ,int low ,int high,int  i,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val);
        }
        else{
            update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
};
void solve(){
    int n,cin>>n;
    vector<int>arr(n);
    take(arr);
    SGTree sgt;
    
    sgt.build(0,0,n-1,arr);
    // find min
    int q;
    cin>>q;
    while(q--){ 
        // update the segment tree
        int type,l,r;
        cin>>type;
        if(type==1){
            cin>>l>>r;
            cout<<sgt.query(0,0,n-1,l,r)<<endl;
        }
        else{
            int i,val;cin>>i>>val;
            
            sgt.update(0,0,n-1,i,val,seg);
            arr[i]=val;
        }
    }
}
void solve2(){
    int n1;cin>>n1;
    vector<int>arr1(n1);
    take(arr1);
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);
    
    
    int n2;cin>>n2;
    vector<int>arr2(n2);
    take(arr2);
    GSTree sg2(n2);
    sg2.build(0,0,n2-1,arr2);
    
    
    int q;
    cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l1,l2,r1,r2;
            cin>>l1>>r1>>l2>>r2;
            
            int min1=sg1.query(0,0,n1-1,l1,r1);
            int min2=sg2.query(0,0,n2-1,l2,r2);
            
            cout<<min(min1,imn2)<<endl;
        }
        else{
            int arrNo,i,val;cin>>arrNo>>i>>val;
            if(arrNo==1){
                sg1.update(0,0,n1-1,i,val);
                arr1[i]=val;
            }
            else{
                sg2.update(0,0,n2-1,i,val);
                arr2[i]=val;
            }
        }
    }
}


 
signed main()
{
    int t;cin>>t;
    while(t--){
       // solve();
        solve2();
    }
    return 0;
}
