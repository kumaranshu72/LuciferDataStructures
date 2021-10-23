#include <bits/stdc++.h>
#define LSB(x) x&-x
using namespace std;
int BIT[1000], A[1000], N;
void update(int idx, int val){
    for(; idx<=N; idx+= LSB(idx)){
        BIT[idx] += val;
    }
}

int query(int idx){
    int sum = 0;
    for(; idx>0; idx-= LSB(idx)){
        sum += BIT[idx];
    }
    return sum;
}

int main(){
    N = 16;
    int l,r;
    //creating BIT
    for(int i = 1; i<=N; i++){
        A[i] = i;
        update(i, A[i]);
    }
    //range query
    cin >> l >> r;
	cout << query(r) - query(l-1);
}
