
#include <iostream>
using namespace std;

int main() {
    int n = 4, at[] = {0, 1, 2, 3}, bt[] = {4, 3, 1, 2}, ft[4], tat[4], wt[4], ct = 0, twt = 0, ttat = 0;

    for (int i = 0; i < n; i++) {
        ct = max(ct, at[i]) + bt[i];
        ft[i] = ct;
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
        ttat += tat[i];
    }

    cout << "Avg WT= " << (float)twt / n << "\n";
    cout << "Avg TAT= " << (float)ttat / n << "\n";

    return 0;
}




