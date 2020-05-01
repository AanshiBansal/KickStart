//Time complexity: O(n)
//Space Complexity: O(1)

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    int tests =t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        vector<ll>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=n-1;i>=0;i--)
            d-=d%arr[i];
        cout<<"Case #"<<tests-t<<": "<<d<<endl;
    }
}
