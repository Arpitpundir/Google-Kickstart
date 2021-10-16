#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int k = 1;
    while(k<=t){
        long int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> l, r;
        l.resize(n, -1);
        r.resize(n, -1);
        int lastBin = -1;
        for(long int i=0;i<n;i++){
            if(s[i]=='1'){
                l[i] = 0;
                lastBin = i;
            }else if(lastBin == -1){
                l[i]=-1;
            }else{
                l[i] = abs(lastBin-i);
            }
        }
        lastBin = -1;
        for(long int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                r[i] = 0;
                lastBin = i;
            }else if(lastBin == -1){
                r[i] = -1;
            }else{
                r[i] = abs(lastBin-i);
            }
        }
        
        long long int ans = 0;
        for(long int i=0;i<n;i++){
            if(l[i] == -1){
                ans+=r[i];
            }
            else if(r[i] == -1){
                ans+=l[i];
            }
            else{
                ans+=min(l[i], r[i]);
            }
            
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
        k++;
    }
}