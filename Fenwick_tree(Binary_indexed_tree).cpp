#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll Fen_tree[100005], a[100005], n;
void updt(ll x, ll val)
{
      for(; x <= n; x += x&-x)
        Fen_tree[x] += val;
}
ll query(ll val)
{
     ll sum = 0;
     for(; val > 0; val -= val&-val)
        sum += Fen_tree[val];
     return sum;
}

int main()
{
     cin>>n;
     ll i,x,l,r;
     for(i = 1; i <= n; i++)
     {
           cin>>a[i];
           updt(i, a[i]);
     }
     cin>>x>>l>>r;
     cout<<"Sum of first "<<x<<" elements is "<<query(x)<<endl;
     cout<<"Sum of all elements in range "<<"[ "<<l<<" , "<<r<<" ] is "<<(query(r)-query(l-1));
     return 0;
}
