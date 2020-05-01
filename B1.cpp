//number of peaks
//Time complexity: O(n)
//Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int tests =t;
    while(t--){
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int i=0;i<k;i++)
            cin>>arr[i];
            
        int ans=0;
        for(int i=1;i<k-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            ans++;
        }
        cout<<"Case #"<<tests-t<<": "<<ans<<endl;
    }
}
