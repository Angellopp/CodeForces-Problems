#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        long long n, k;
        cin >> n >> k;
        int b[60+1]{};
        int ul = 0;
        for (int i = 0; i < 60; i++) {
            b[i] = ((k >> i) & 1);
            if (b[i] == 1) {ul = i; break;}
        }
        cout << n - ul << endl;

        // for (int i : b) {
        //     cout << i;
        // }
        // cout << endl;
    }
}