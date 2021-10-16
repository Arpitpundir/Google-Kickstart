#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int K = 1;
    while(K <= t){
        long int d,n,k;
        cin>>d>>n>>k;
        vector<pair<long int , pair<long int, long int> > > days;
        long long int ans = 0;
        for(long int i=0;i<n;i++){
            long int h, s, e;
            cin>>h>>s>>e;
            days.push_back(make_pair(h, make_pair(s,e)));
        }
        sort(days.begin(), days.end());
        
        for(long int i = 1;i<=d;i++){
            long int currDay = i;
            long long int currHappiness = 0;
            long int rides = k;
            for(long int j=n-1;j>=0&&rides;j--){
                if(currDay>=days[j].second.first && currDay<=days[j].second.second){
                    currHappiness += days[j].first;
                    rides--;
                }
            }
            ans = max(ans, currHappiness);
        }
        cout<<"Case #"<<K<<": "<<ans<<endl;
        K++;
    }
}