#include<bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>&books, int M, int mxp) {
    int studentCount = 1;
    int current = 0;

    for (int pages : books) {
        current+= pages;
        if (current > mxp) {
            studentCount++;
            current = pages;
            if (studentCount > M) {
                return false; } }
    }
    return true;
}

int allocateBooks(int N, int M, const vector<int>& books) {
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(books, M, mid)) {
            result = mid; 
            //cout<<result;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >>N>> M;
        vector<int>books(N);
        for (int i=0; i < N; ++i) {
            cin >> books[i];
        }
        int result = allocateBooks(N, M, books);
        cout<< result << endl;
    }
    return 0;
}
