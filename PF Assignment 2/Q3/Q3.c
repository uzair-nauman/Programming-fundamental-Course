#include <stdio.h>

#define MAX 50

void inputReadings(int temp[][MAX], int sensors, int hours) {
    int i, j;
    for (i = 0; i < sensors; i++) {
        printf("Sensor %d: ", i + 1);
        for (j = 0; j < hours; j++)
            scanf("%d", &temp[i][j]);
    }
}

void analyzeSensor(int r[], int n, int *total, float *avg, int *max, int *min,
                   int *critical, int *warning, int *streak) {
    int j, cur = 0;
    *total = 0; *critical = 0; *warning = 0; *streak = 0;
    *max = *min = r[0];
    for (j = 0; j < n; j++) {
        *total += r[j];
        if (r[j] > *max) *max = r[j];
        if (r[j] < *min) *min = r[j];
        if (r[j] >= 40) (*critical)++;
        else if (r[j] >= 35) (*warning)++;
        if (r[j] >= 35) {
            cur++;
            if (cur > *streak) *streak = cur;
        } else {
            cur = 0;
        }
    }
    *avg = (float)*total / n;
}

int highestAverage(float avg[], int sensors) {
    int i, best = 0;
    for (i = 1; i < sensors; i++)
        if (avg[i] > avg[best]) best = i;
    return best + 1;
}

int main(void) {
    int temp[MAX][MAX], sensors, hours, i;
    int total, max, min, critical, warning, streak, best;
    float avg[MAX];

    do {
        printf("Enter number of sensors (1-%d): ", MAX);
        scanf("%d", &sensors);
    } while (sensors < 1 || sensors > MAX);
    do {
        printf("Enter number of hourly readings (1-%d): ", MAX);
        scanf("%d", &hours);
    } while (hours < 1 || hours > MAX);

    inputReadings(temp, sensors, hours);

    printf("\n");
    for (i = 0; i < sensors; i++) {
        analyzeSensor(temp[i], hours, &total, &avg[i], &max, &min, &critical, &warning, &streak);
        printf("Sensor %d: Total=%d Avg=%.2f Max=%d Min=%d\n", i + 1, total, avg[i], max, min);
        printf("          Critical=%d Warning=%d Longest hot streak=%d\n", critical, warning, streak);
    }

    best = highestAverage(avg, sensors);
    printf("\nHighest average: Sensor %d (%.2f)\n", best, avg[best - 1]);
    return 0;
}
