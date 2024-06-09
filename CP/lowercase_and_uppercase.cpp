#include<bits/stdc++.h>
using namespace std;

void convertAllLowerCase(string s) {
    int n = s.size();

    for (int i = 0; i < n;i++) {
        if(islower(s[i])) {
            toupper(s[i]);
            cout << s[i];
        }
        else {
            cout << s[i];
        }
    }
}

void convertAllUpperCase(string s) {
    int n = s.size();

    for (int i = 0; i < n;i++) {
        if(isupper(s[i])) {
            tolower(s[i]);
            cout << s[i];
        }
        else {
            cout << s[i];
        }
    }
}

int calculateLowerCase(string s) {
    int lowerCaseCount = 0;
    int n = s.size();

    for (int i = 0; i < n;i++) {
        if(islower(s[i])) {
            lowerCaseCount++;
        }
    }

    return lowerCaseCount;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    if(n == 1) {
        cout << s;
    }

    int lowerCaseCount = calculateLowerCase(s);

    if(lowerCaseCount <= (int)(n/2)) {
        convertAllLowerCase(s);
    }
    else {
        convertAllUpperCase(s);
    }
    return 0;
}