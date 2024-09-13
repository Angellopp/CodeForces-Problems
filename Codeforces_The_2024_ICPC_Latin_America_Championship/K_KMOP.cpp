#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    vector <string> v;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.emplace_back(s.substr(0, 3));
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
    // for (int i = 1; i < n; i++) {
        
    // }
    
}