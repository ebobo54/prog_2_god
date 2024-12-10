#include <stdio.h>
#include <stdlib.h>

void calculate_distances(int n, int *street, int *distances) {
    int last_zero = -1;

    for (int i = 0; i < n; i++) {
        if (street[i] == 0) {
            last_zero = i;
        }
        distances[i] = (last_zero == -1) ? n : i - last_zero;
    }

    last_zero = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (street[i] == 0) {
            last_zero = i;
        }
        if (last_zero != -1) {
            distances[i] = (distances[i] < last_zero - i) ? distances[i] : last_zero - i;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *street = (int *)malloc(n * sizeof(int));
    int *distances = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &street[i]);
    }

    calculate_distances(n, street, distances);

    for (int i = 0; i < n; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");

    free(street);
    free(distances);

    return 0;
}

// #include <stdio.h>

// int main() {
//     printf("Hello, world!\n");
//     return 0;
// }
