#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int min_ops(string s, int n, int k) {
    int i = 0;
    int j = s.size()-1;
    int sc = 0;
    while (i < j) {
        if (s[i] != s[j]) sc++;
        i++;
        j--;
    }
    return abs(k - sc);
}

int main() {
    int t, n, k;
    string s;
    cin >> t;
    vector<int> ans;
    while (t--) {
        cin >> n >> k >> s;
        ans.push_back(min_ops(s, n, k));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}