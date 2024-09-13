#include <bits/stdc++.h>
using namespace std;
vector <vector <char>> a(500, vector <char> (500));
vector <vector <bool>> vis(500, vector <bool> (500, 0));
int cnt = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string name = "snuke";
int m, n;


bool valid(int x, int y, int cnt) {
    return (x >= 0 and x < m and y >= 0 and y < n and vis[x][y] == 0 and a[x][y] == name[cnt%5]);
}

bool bfs(int x, int y) {
    queue <tuple<int,int, int>> q;
    q.emplace(x, y, 0);
    vis[x][y] = true;
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        // cnt++;
        int vf, vs, ct;
        tie(vf, vs, ct) = v;
        if (vf == m-1 and vs == n-1) {return true;}
        for (int i = 0; i < 4; i++) {
            int xx = vf + dx[i];
            int yy = vs + dy[i];
            if (valid(xx, yy, ct+1)) {
                q.emplace(xx, yy, ct + 1);
                vis[xx][yy] = true;
                // cout << xx << " " << yy << " " << ct+1 <<"\n";
            }
        }
    }
    return false;

}

int main() {
    cin >> m>> n;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    cout << (bfs(0,0) ? "Yes" : "No");
}