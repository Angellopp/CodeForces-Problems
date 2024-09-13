#include <bits/stdc++.h>

using namespace std;
int num = 0;
map <int,int> numCiclos(vector<int>& v) {
    int n = v.size();
    vector <bool> vis(n);
    map <int,int> m;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cur = v[cur] - 1;
            m[cur] = num;
        }
        num++;
    }
    return m;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        num = 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        map <int, int> ans = numCiclos(v);
        n-=num;
        int ans2 = n+3;
        for (int i = 0; i < ans.size() - 1; i++) {
            int aux = n;
            if (ans[i] == ans[i + 1]) aux--;
            else aux++;
            ans2 = min(ans2, aux);
        }
        cout << ans2 << "\n";

    }
}