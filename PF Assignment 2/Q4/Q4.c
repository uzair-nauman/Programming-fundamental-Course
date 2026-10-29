#include <stdio.h>

int getValidDays() {
    int days;
    printf("Number of days: ");
    scanf("%d", &days);
    while (days < 1 || days > 7) {
        printf("Invalid! Enter number of days between 1 and 7: ");
        scanf("%d", &days);
    }
    return days;
}

float calculateDailySales(int dayNumber) {
    int n, i;
    float amount, total = 0, max = 0;

    printf("Day %d - Number of orders: ", dayNumber);
    scanf("%d", &n);
    printf("Order amounts: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &amount);
        while (amount <= 0) {
            printf("Invalid amount! Re-enter order %d: ", i + 1);
            scanf("%f", &amount);
        }
        total += amount;
        if (amount > max) max = amount;
    }
    printf("Total sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", total / n);
    printf("Highest order: Rs. %.2f\n\n", max);
    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays) {
    int i, best = 0;
    for (i = 1; i < numberOfDays; i++)
        if (dailySales[i] > dailySales[best]) best = i;
    return best + 1;
}

void displayBarChart(float dailySales[], int numberOfDays) {
    int i, s;
    for (i = 0; i < numberOfDays; i++) {
        printf("Day %d: ", i + 1);
        for (s = 0; s < (int)(dailySales[i] / 100); s++)
            printf("*");
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

int main() {
    float dailySales[7], festivalTotal = 0;
    int days, i, best;

    days = getValidDays();
    for (i = 0; i < days; i++) {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal += dailySales[i];
    }

    best = findHighestSalesDay(dailySales, days);
    printf("===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", best);
    printf("Highest daily sales: Rs. %.2f\n\n", dailySales[best - 1]);

    printf("===== DAILY SALES BAR CHART =====\n");
    displayBarChart(dailySales, days);
    return 0;
}
