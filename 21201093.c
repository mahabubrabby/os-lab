#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};

int main() {
    int n = 5, currentTime = 0, completed = 0;
    struct Process p[5] = {
        {1, 2, 4, 0, 0, 0, 0},
        {2, 10, 1, 0, 0, 0, 0},
        {3, 3, 2, 0, 0, 0, 0},
        {4, 2, 5, 0, 0, 0, 0},
        {5, 0, 5, 0, 0, 0, 0}
    };

    while (completed != n) {
        int idx = -1, minBT = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].completed == 0) {
                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
                // tie-breaking: by arrival time if needed
                else if (p[i].bt == minBT && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            currentTime += p[idx].bt;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}            completed++;
        } else {
            currentTime++;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
