// author: yogeshk972
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int,int> Rank;    // rank based union
    public :
        void init(int sz){
            for(int i=0;i<sz;i++){
                parent[i]=i;
                Rank[i]=0;
            }
        }

        void Union(int a,int b){
            int aParent=parent[a];
            int bParent=parent[b];

            if( aParent==bParent )return;

            if(  Rank[aParent] > Rank[bParent] ){
                  parent[ bParent ]= aParent;
            }else if(  Rank[aParent] < Rank[bParent] ){
                parent[ aParent ]= bParent;
            }else {
                  parent[bParent]=aParent;
                  Rank[a]++;
            }
        }

        int Find(int x){
            if(parent[x]!=x){
                parent[x] = Find(parent[x]); // path compression
            }
            return parent[x];
        }


};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)cin>>v[i];
    DisjointSet ds;
    ds.init(v.size());

    ds.Union(2,3);   // union of index 2 and 3
    ds.Union(1,2); // union of index 1 and 2


    for(i=0;i<v.size();i++){
        cout<<i<<" "<<ds.Find(i)<<"\n"; // displays parent of i'th indes is ds.Find(i)
                                        // alternatively we can say that those that have same ds.find() values belong to same set
    }
    return 0;
}


