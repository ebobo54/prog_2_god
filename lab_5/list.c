#include <stdio.h>
#include <string.h>

#define SIZE 4

int max_points(int k, char field[SIZE][SIZE + 1]) {
    int counts[10] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] >= '1' && field[i][j] <= '9') {
                counts[field[i][j] - '0']++;
            }
        }
    }
    
    int max_score = 0;
    
    for (int t = 1; t <= 9; t++) {
        if (counts[t] > 0 && counts[t] <= 2 * k) {
            max_score++;
        }
    }
    
    return max_score;
}

int main() {
    int k;
    char field[SIZE][SIZE + 1];
    
    scanf("%d", &k);
    for (int i = 0; i < SIZE; i++) {
        scanf("%s", field[i]);
    }
    
    printf("%d\n", max_points(k, field));
    
    return 0;
}
