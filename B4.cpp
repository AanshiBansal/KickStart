#include<bits/stdc++.h>
using namespace std;
vector<double>fact(200000);
void precompute(){
	fact[0]=0;
	for(int i=1;i<200000;i++)
	fact[i]=fact[i-1]+log2(i);
}
double prob(int dec, int inc){
	int n=dec+inc;
	double ans=0;
	for(int i=inc;i<=n;i++)
	{
		double res=fact[n]-fact[i]-fact[n-i]-(n);
		ans+=pow(2.0,res);
	}
	return ans;
}
int main(){
	precompute();
    int t;
    cin>>t;
    int tests =t;
    while(t--){
        int w,h,l,u,r,d;
        cin>>w>>h>>l>>u>>r>>d;
        w--;h--;l--;u--;r--;d--;
        double ans=0;
        if(l-1>=0&&d+1<=h)
		ans+=prob(l-1,d+1);
		if(u-1>=0&&r+1<=w)
		ans+=prob(u-1,r+1);
        cout<<"Case #"<<tests-t<<": "<<ans<<endl;
    }
}
