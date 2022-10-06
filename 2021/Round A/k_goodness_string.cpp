#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size()/2; ++i){
            if(s[i] != s[s.size() - i - 1]) ans++;
        }
        cout << "Case #" << tt << ": " << abs(k-ans) << endl;
    }
    return 0;
}