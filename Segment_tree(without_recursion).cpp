/*Segment Trees without recursion

Finds the sum of elements from index l to r where 0 <= l <= r <= n-1
Changes value of a specified element of the array to a new given value. We need to update arr[i] = x where 0 <= i <= n-1. 
*/

#include <bits/stdc++.h> 
#define ll int
using namespace std; 
  
const ll N = 1000005;  
  
ll n;  
  

ll seg_tree[2 * N]; 
  

void _build( ll arr[])  
{  
   
    for (ll i=0; i<n; i++)     
        seg_tree[n+i] = arr[i]; 
      
    for (ll i = n - 1; i > 0; --i)      
        seg_tree[i] = seg_tree[i<<1] + seg_tree[i<<1 | 1];     
} 
  

void update_tree_node(ll p, ll value)  
{  
     
    seg_tree[p+n] = value; 
    p = p+n; 
      
    for (ll i=p; i > 1; i >>= 1) 
      seg_tree[i>>1] = seg_tree[i] + seg_tree[i^1]; 
} 
  
 
ll query(ll l, ll r)  
{  
    ll ans = 0; 
    
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            ans += seg_tree[l++]; 
      
        if (r&1)  
            ans += seg_tree[--r]; 
    } 
      
    return ans; 
} 
  

int main()  
{ 
	cin>>n;
    ll a[n]; 
 for(ll i=0;i<n;i++) cin>>a[i];
   _build(a); 
 ll Q;
 cin>>Q;
 while(Q--)
 {
 	ll l,r,x,ind,val;
 cin>>x;
 	if(x==2)
 	{
 		
 	cin>>l>>r;
    cout << query(l, r)<<endl; 
 		
 	}
  else if(x==1)
  {
  	cin>>ind>>val;
     update_tree_node(ind, val);
   } 
 }
    return 0; 
}
