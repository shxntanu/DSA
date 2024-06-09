#include <bits/stdc++.h>
using namespace std;

void calculateCount(int n, int m, int* hands) {
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if ((m - hands[i]) >= 0)
        {
            cnt++;
            m = m - hands[i];
        }
        else
        {
            break;
        }
    }

    cout << cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int hands[n];
    for (int i = 0; i < n; i++)
    {
        cin >> hands[i];
    }

    calculateCount(n, m, hands);
    
    return 0;
}