//DS: Stack
//Time Complexity:O(length of string)
//Space Complexity: no extra space, recurssive function call O(length of string)
//Concepts learned:
//Usage of long long
//Difference and use of modulus and remainder

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pair pair<ll,ll>
const int modnum=1000000000;
ll mod(ll a, ll b=modnum)
{
    ll r = a % b;
    return r < 0 ? r + b : r;
}
pair util(const string &s,int x,int y, unordered_map<int,int>&mp){
    int i=x;
    ll m=0;
    ll n=0;
    while(i<=y){
        if(s.at(i)>='2' && s.at(i)<='9'){
        	int count=s.at(i)-'0';
            pair r=util(s,i+2,mp[i+1]-1,mp);
            m+=r.first*count;
            n+=r.second*count;
            i=mp[i+1]+1;
        }
        else{
            switch(s.at(i)){
                case 'N':{m--;break;};
                case 'S':{m++;break;};
                case 'E':{n++;break;};
                case 'W':{n--;break;};
            }
            i++;
        }
        m=mod(m);
        n=mod(n);
    }
    return {m,n};
}
int main(){
    int t;
    cin>>t;
    int tests =t;
    while(t--){
        string s;
        cin>>s;
        //storing the position of opening and closing brackets using stack and map
        stack<int>st;
        unordered_map<int,int>mp;
		for(int i=0;i<s.size();i++){
			if(s.at(i)=='('){
				st.push(i);
			}
			if(s.at(i)==')'){
				mp[st.top()]=i;
				st.pop();
			}
		}
        pair ans=util(s,0,s.size()-1,mp);
        cout<<"Case #"<<tests-t<<": "<<ans.second+1<<" "<<ans.first+1<<endl;
    }
}
