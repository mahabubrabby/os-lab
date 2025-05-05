#include <stdio.h>

int main() {
    int n = 6, i, time = 0, remain = n;
    int qt = 4;  // time quantum
    int at[] = {0, 1, 2, 3, 4, 4};
    int bt[] = {7, 4, 15, 11, 20, 9};
    int rt[6], ct[6], tat[6], wt[6];

    // initialize remaining times
    for (i = 0; i < n; i++)
        rt[i] = bt[i];

    printf("Order of execution (with time slices):\n");

    // RR Scheduling
    while (remain) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                int exec = (rt[i] > qt) ? qt : rt[i];
                printf("P%d [%d - %d]\n", i+1, time, time + exec);
                time += exec;
                rt[i] -= exec;
                if (rt[i] == 0) {
                    ct[i] = time;
                    remain--;
                }
            }
        }
    }


    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }

    // Print table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

