#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; ++tt){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c,0));
    priority_queue<pair<int,pair<int,int>>> q;
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j) {
        cin >> g[i][j];
        q.push(make_pair(g[i][j],make_pair(i,j)));
      }
    }
    long long ans = 0;
    while(!q.empty()){
      int x,y;
      x = q.top().second.first;
      y = q.top().second.second;
      q.pop();
      int v = g[x][y];
      int m = 0;
      for(int i = 0; i < 4; ++i){
        if(x+dx[i] >= r || y+dy[i] >= c || x+dx[i] < 0 || y+dy[i] < 0) continue;
        if(g[x+dx[i]][y+dy[i]] > v-1){
          m = max(m,g[x+dx[i]][y+dy[i]]);
      }
      }
      if(m > v+1){
        ans += m-v;
        g[x][y] = m;
      }
      v = g[x][y];
      for(int i = 0; i < 4; ++i){
        if(x+dx[i] >= r || y+dy[i] >= c || x+dx[i] < 0 || y+dy[i] < 0) continue;
        if(g[x+dx[i]][y+dy[i]] < v-1){
          ans += v-1-g[x+dx[i]][y+dy[i]];
          g[x+dx[i]][y+dy[i]] = v-1;
          q.push(make_pair(g[x+dx[i]][y+dy[i]],make_pair(x+dx[i], y+dy[i])));
        }
      }
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
  return 0;
}
