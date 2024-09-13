#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
    fast_io;
    int n, k, aux;
    cin >> k >> n;
    set <int> s;
    vector <int> v;
    for (int i = 0; i < n; i++) {cin >> aux; s.insert(k - aux);}
    for (auto x : s) v.emplace_back(x);
    n = v.size();
    queue <int> q;
    q.push(0);
    vector <int> m(2001, -1);
    m[1000] = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            int vec = p + v[i];
            if (vec == 0) {
                cout << m[p+1000] + 1;
                return 0;
            }
            if (abs(vec) <= 1000 and m[vec+1000] == -1) {
                m[vec+1000] = m[p+1000] + 1;
                q.push(vec);
            }
        }
    }
    cout << -1;
}