#include<bits/stdc++.h>
using namespace std;
bool check(int h,vector<int> paper){
    int count=0;
    for(int i=0;i<paper.size();i++){
        if(paper[i]>=h)count++;

    }
    if(count>=h)return true;
    return false;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        cout<<"Case #"<<i+1<<": ";
        vector<int >paper;
        for(int j=1;j<=n;j++){
            long int cit;cin>>cit;
            paper.push_back(cit);
            for(int h_i=j;h_i>=1;h_i--){
                if(check(h_i,paper)){
                   cout<<h_i<<" ";break; 
                }
            }
        }cout<<endl;
    }
}