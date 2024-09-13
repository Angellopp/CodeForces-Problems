#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tam(int n) {
    int ans = 0;
    while(n) {
        n /= 10;
        ans++;
    }
    return ans;
}

int pow(int n, int p) {
    int ans = n;
    for (int i = 0; i < p; i++) {
        ans *= n;
    }
}


int main() {
    int n1, n2, n3;
    char c, c1;
    cin >> n1;
    cin >> c;
    cin >> n2;
    cin >> c1;
    cin >> n3;
    vector <string> v1, v2, v3;
    v1.push_back("");
    v2.push_back("");
    v3.push_back("");
    for (int i = tam(n1)-1; i >= 0; i--) {
        v1.push_back(to_string(n1 / (ll)pow(10, i)));
    }
    for (int i = tam(n2)-1; i >= 0; i--) {
        v2.push_back(to_string(n2 / (int)pow(10, i)));
    }
    for (int i = tam(n3)-1; i >= 0; i--) {
        v3.push_back(to_string(n3 / (int)pow(10, i)));
    }
    for (int i = 0; i < v1.size()-1; i++){
        for (int j = 0; j < v2.size()-1; j++) {
            string xn1 = v2[j] + to_string(n1).substr(i);
            string xn2 = v1[i] + to_string(n2).substr(j);
            ll nn1 = stoll(xn1);
            ll nn2 = stoll(xn2);
            if(c == '+') {
                if(nn1 + nn2 == n3) {
                    cout << nn1 << " + " << nn2 << " = " << n3;
                    return 0;
                }
            }
            else if (c == '*') {
                if(nn1 * nn2 == n3) {
                    cout << nn1 << " * " << nn2 << " = " << n3;
                    return 0;
                }
            }
        }
    }
    
    for (int i = 0; i < v1.size()-1; i++){
        for (int j = 0; j < v3.size()-1; j++) {
            string xn1 = v3[j] + to_string(n1).substr(i);
            string xn3 = v1[i] + to_string(n3).substr(j);
            // cout << xn1 << " " << xn3 << "\n";
            ll nn1 = stoll(xn1);
            ll nn3 = stoll(xn3);
            // cout << nn1 << "+" << n2 << " = " << nn3 << " \n";
            if(c == '+') {
                if(nn1 + n2 == nn3) {
                    cout << nn1 << " + " << n2 << " = " << nn3;
                    return 0;
                }
            }
            else if (c == '*') {
                if(nn1 * n2 == nn3) {
                    cout << nn1 << " * " << n2 << " = " << nn3;
                    return 0;
                }
            }
        }
    }
    
    for (int i = 0; i < v2.size(); i++){
        for (int j = 0; j < v3.size(); j++) {
            string xn2 = v3[j] + to_string(n2).substr(i);
            string xn3 = v2[i] + to_string(n3).substr(j);
            ll nn2 = stoll(xn2);
            ll nn3 = stoll(xn3);
            if(c == '+') {
                if(n1 + nn2 == nn3) {
                    cout << n1 << " + " << nn2 << " " << nn3;
                    return 0;
                }
            }
            else if (c == '*') {
                if(n1 * nn2 == nn3) {
                    cout << n1 << " * " << nn2 << " " << nn3;
                    return 0;
                }
            }
        }
    }
    
}