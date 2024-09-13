#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, x, y; cin >> n >> q;
    vector <vector<int>> a(2, vector<int> (n, 0));
    multiset<pair<pair<int,int>,pair<int,int>>> s;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        x--, y--;
        if (a[x][y] == 0) {
            if(y-1 >= 0 and a[x^1][y-1]) s.insert({{x,y},{x^1,y-1}}), s.insert({{x^1,y-1},{x,y}});
            if(a[x^1][y]) s.insert({{x,y},{x^1,y}}), s.insert({{x^1,y},{x,y}});
            if(y+1 < n and a[x^1][y+1]) s.insert({{x,y},{x^1,y+1}}), s.insert({{x^1,y+1},{x,y}});
        }
        else {
            if(y-1 >= 0 and a[x^1][y-1]) s.erase({{x,y},{x^1,y-1}}), s.erase({{x^1,y-1},{x,y}});
            if(a[x^1][y]) s.erase({{x,y},{x^1,y}}), s.erase({{x^1,y},{x,y}});
            if(y+1 < n and a[x^1][y+1]) s.erase({{x,y},{x^1,y+1}}), s.erase({{x^1,y+1},{x,y}});
        }
        a[x][y] ^= 1;
        cout << ((s.empty()) ? "Yes" : "No") << endl;

    }
}
