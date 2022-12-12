#include "bits/stdc++.h"
using namespace std;

#define ALL(x) (x).begin(), (x).end()

int checkInput(char c) {
    if(c == 'A' || c == 'X')
        return 1;
    if(c == 'B' || c == 'Y')
        return 2;
    if(c == 'C' || c == 'Z')
        return 3;

    return 0;
}

int checkResult(char c) {
    if(c == 'X')
        return 0;
    if(c == 'Y')
        return 3;
    return 6;
}

int getScore(int you, int me) {
    if(me == you)
        return me + 3;
    else {
        if((me == 1 && you == 3) || (me == 2 && you == 1) || (me == 3 && you == 2)) {
            return me + 6;
        }
    }
    return me;
}

int getWinnerScore(char c) {
    if(c == 'A')
        return 2;
    if(c == 'B')
        return 3;
    return 1;
}
int getLoserScore(char c) {
    if(c == 'A')
        return 3;
    if(c == 'B')
        return 1;
    return 2;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int total = 0, result = 0;
    string S;

    while(getline(cin, S)) {
        if(S.length() > 0) {
            if(checkResult(S[2]) == 3) {
                result += (checkInput(S[0]) + 3);
            }
            if(checkResult(S[2]) == 6) {
                result += (getWinnerScore(S[0]) + 6);
            }
            if(checkResult(S[2]) == 0) {
                result += (getLoserScore(S[0]));
            }


            total += getScore(checkInput(S[0]), checkInput(S[2]));
//            result += (getWinnerScore(S[0]) + checkResult(S[2]));
            cout << S[0] << " " << checkInput(S[0]) << " " << S[2] << " " << checkInput(S[2]) << " Total: " << total << " Result: " << result << endl;
        }
    }


    return 0;
}
