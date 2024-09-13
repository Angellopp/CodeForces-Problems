#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;



int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i= 0; i < n; i++){
            cin >> v[i];
        }
        // bool can = 1;
        // for (int i = 0; i < n; i++) {
        //     if (v[i] != i+1) {
        //         can = 0;
        //         break;
        //     }
        // }
        // if(can) {
        //     cout << "0\n";
        //     continue;
        // }
        // if (v[0] > v[n-1]) {
        //     cout << "1\n" << 1 << " " << n << "\n";
        //     continue;
        // }
        vector <pair<int,int>> ans;
        for (int i = 0; i < n; i++) {
            if (v[i] == i+1) continue; 
            for (int j = n-1; j > i; j--) {
                if (v[j] == j+1) continue;
                if(v[i] > v[j]) {
                    sort(v.begin() + i, v.begin() + j + 1);
                    ans.emplace_back(i+1, j+1);
                    break;
                }
            }
        }

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }

    }



}