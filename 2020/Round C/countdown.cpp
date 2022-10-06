#include <bits/stdc++.h>
using namespace std;

int N, K, tmp, ans_cnt, decreasing_cnt;

int solve() {   
    vector<int> A;
    ans_cnt = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> tmp,
        A.push_back(tmp);
    
    for (int i = 1; i < N; ++i) {
        decreasing_cnt = (A[i] == A[i-1]-1) ? decreasing_cnt + 1 : 0;
        ans_cnt += (A[i] == 1 && decreasing_cnt >= K-1) ? 1 : 0;
    }
    return ans_cnt;
}

int main() {
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int s = solve();
        cout << "Case #" << i + 1 << ": " << s << endl;
    }
}