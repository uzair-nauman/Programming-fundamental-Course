#include <stdio.h>

int main(void) {
    int seat[50][50], rows, cols, k, i, j, d, t, r, run, c;
    int total = 0, row = -1, start = -1, mid;

    do {
        printf("Enter number of rows (1-50): ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 50);
    do {
        printf("Enter number of seats per row (1-50): ");
        scanf("%d", &cols);
    } while (cols < 1 || cols > 50);

    printf("Enter seating status (0 = available, 1 = booked):\n");
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            scanf("%d", &seat[i][j]);
			}
		}

    do {
        printf("Enter group size k: ");
        scanf("%d", &k);
        if (k <= 0 || k > cols)
            printf("Invalid group size! It must be between 1 and %d.\n", cols);
    } while (k <= 0 || k > cols);


    printf("\nFree seats per row:");
    for (i = 0; i < rows; i++) {
        c = 0;
        for (j = 0; j < cols; j++)
            if (seat[i][j] == 0) c++;
        printf(" %d", c);
        total += c;
    }
    printf("   Total free: %d\n\n", total);


    mid = rows / 2;
    for (d = 0; d < rows && row < 0; d++) {
        for (t = 0; t < 2 && row < 0; t++) {
            if (d == 0 && t == 1) continue;
            r = (t == 0) ? mid - d : mid + d;
            if (r < 0 || r >= rows) continue;
            run = 0;
            for (j = 0; j < cols; j++) {
                run = (seat[r][j] == 0) ? run + 1 : 0;
                if (run == k) {
                    row = r;
                    start = j - k + 1;
                    break;
                }
            }
        }
    }

    if (row >= 0) {
        for (j = start; j < start + k; j++)
            seat[row][j] = 1;
        total -= k;
        printf("Group of %d seated in Row %d, Seats %d to %d\n\n", k, row, start, start + k - 1);
    } else {
        printf("No row has %d consecutive available seats. Seating plan unchanged.\n\n", k);
    }


    printf("   ");
    for (j = 0; j < cols; j++)
        printf("%d ", j);
    printf("\n");
    for (i = 0; i < rows; i++) {
        printf("R%-2d", i);
        for (j = 0; j < cols; j++)
            printf("%c ", seat[i][j] ? 'X' : '_');
        printf("\n");
    }
    printf("\nRemaining free seats: %d\n", total);
    return 0;
}
