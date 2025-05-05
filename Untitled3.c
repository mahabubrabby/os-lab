
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Given page reference string and frame size
    int pages[]   = {0, 1, 5, 3, 5, 0, 2, 4, 7, 9, 0, 0, 3};
    int n         = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 4;

    int frames[frameSize];
    int nextReplace = 0;
    int hits = 0, misses = 0;


    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;


        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == page) {
                found = true;
                hits++;
                break;
            }
        }

        // If not found → miss, replace using FIFO
        if (!found) {
            frames[nextReplace] = page;
            nextReplace = (nextReplace + 1) % frameSize;
            misses++;
        }


    }

    printf("Total references: %d\n", n);
    printf("Total hits:       %d\n", hits);
    printf("Total misses:     %d\n", misses);

    return 0;
}
