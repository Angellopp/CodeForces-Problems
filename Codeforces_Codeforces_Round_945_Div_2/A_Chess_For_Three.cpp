#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if((p1 + p2 + p3) % 2 == 1) {
            cout << "-1\n";
            continue;
        } 
        int pro = (p1 + p2 + p3) / 2;
        if (p1 <= pro and p2 <= pro and p3 <= pro) {
            cout << pro << "\n";        
        }   
        else {
            cout << -p1 - p2 + 4*(pro)-2*p3 << "\n";
        }
    }   
    
}