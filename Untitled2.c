#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int req[] = {137, 240, 179, 75, 118, 29, 15, 51};
    int n = sizeof(req)/sizeof(req[0]);
    int head = 55;
    int visited[8] = {0};
    int total_seek = 0;

    for (int i = 0; i < n; i++) {
        int min = 1e9, index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs_diff(head, req[j]);
                if (diff < min) {
                    min = diff;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += abs_diff(head, req[index]);
        printf("Move from %d to %d (Seek = %d)\n", head, req[index], abs_diff(head, req[index]));
        head = req[index];
    }

    printf("\nTotal Seek Time: %d\n", total_seek);
    return 0;
}
