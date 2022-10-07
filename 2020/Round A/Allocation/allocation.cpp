/**
 * @file GKSRA2020.cpp
 * @author Nisarg Suthar (nisargsuthar0@gmail.com)
 * @brief Solution to the Allocation problem from Google Kickstart 200 Round A
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, b;
        cin >> n >> b;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (b >= v[j]) {
                b -= v[j];
                ans++;
            } else {
                break;
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}