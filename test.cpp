#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000000L
#define LL long long
#define LIMIT 1001

vector<int> fact;

void compute(){
    fact.resize(LIMIT);
    fact[0]=1;
    for(int i=1;i<LIMIT;i++){
        fact[i]=(i*fact[i-1])%MOD;
    }
}

LL inverse(LL x){
    LL p=MOD;
    LL x0=0,x1=1,q,temp;
    while(x>1){
        q=x/p;
        temp=p;
        p=x%p;
        x=temp;
 
        temp=x0;
        x0=x1-q*x0;
        x1=temp;
    }
    if(x1<0) x1+=MOD;
    return x1;
}

int main() {
    compute();
    int t;
    cin>>t;
    while(t--){
        LL n;
        cin>>n;
        for(LL i=0;i<=n;i++){
            cout<<((fact[n] * inverse(fact[i]))%MOD * inverse(fact[n-i]))%MOD<<" ";
        }
        cout<<endl;
    }
    return 0;
}
