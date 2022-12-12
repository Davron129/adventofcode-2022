#include <iostream>
#include <string.h>
#include "vector"
#include "bits/stdc++.h"
using namespace std;

#define ALL(x) (x).begin(), (x).end()

bool isInt(string str) {
    bool t = false;
    for(char s: str) {
        t = isdigit(s);
    }

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sums;

    string S;
    int max1 = 0, max2 = 0, max3 = 0, total = 0, len = 0;
    while (getline(cin, S)) {
        len = S.length();
        cout << S << " " << len << " " << (len > 0 ? "katta" : "kichik") << endl;
        if(isInt(S)) {
            total += stoi(S);
        } else {
            sums.push_back(total);
            if(max1 <= total) {
                max1 = total;
            }

            total = 0;

            sort(ALL(sums));
            reverse(ALL(sums));
            cout << "result: " << sums[0] + sums[1] + sums[2] << endl;
        }
    }

    return 0;
}
