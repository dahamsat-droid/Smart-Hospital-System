#include <stdio.h>
#include "reports.h"

/* These counters are returned through pointers so one function gives all three totals. */
void countByUrgency(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    int *normalCount,
    int *urgentCount,
    int *criticalCount) {

    *normalCount = 0;
    *urgentCount = 0;
    *criticalCount = 0;

    for (int i = 0; i < patientCount; i++) {

        if (urgencyLevels[i] == 1) {
            (*normalCount)++;
        } else if (urgencyLevels[i] == 2) {
            (*urgentCount)++;
        } else if (urgencyLevels[i] == 3) {
            (*criticalCount)++;
        }
    }
}

double calculateTotalRevenue(
    const double finalBillAmounts[MAX_PATIENTS],
    int patientCount) {

    double total = 0.0;

    for (int i = 0; i < patientCount; i++) {
        total += finalBillAmounts[i];
    }

    return total;
}

double calculateTotalDiscounts(
    const double discountAmounts[MAX_PATIENTS],
    int patientCount) {

    double total = 0.0;

    for (int i = 0; i < patientCount; i++) {
        total += discountAmounts[i];
    }

    return total;
}

/* Occupancy is calculated using the actual capacity rather than all 20 matrix columns. */
double calculateOccupancyPercentage(
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
    int wardIndex,
    int capacity) {

    int occupied = 0;

    for (int b = 0; b < capacity; b++) {

        if (bedOccupancy[wardIndex][b] == 1) {
            occupied++;
        }
    }

    if (capacity > 0) {
        return occupied * 100.0 / capacity;
    }

    return 0.0;
}

int findHighestPayingPatient(
    const double finalBillAmounts[MAX_PATIENTS],
    int patientCount) {

    if (patientCount == 0) {
        return -1;
    }

    int highestIndex = 0;

    for (int i = 1; i < patientCount; i++) {

        if (finalBillAmounts[i] >
            finalBillAmounts[highestIndex]) {

            highestIndex = i;
        }
    }

    return highestIndex;
}

void generateSummaryReport(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    const double finalBillAmounts[MAX_PATIENTS],
    const double discountAmounts[MAX_PATIENTS],
    const char patientIds[MAX_PATIENTS][16],
    const char patientNames[MAX_PATIENTS][NAME_LEN],
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
    const int bedCapacities[NUM_WARDS],
    const char wardNames[NUM_WARDS][NAME_LEN]) {

    printf("\n=========================================================\n");
    printf("                     HOSPITAL SUMMARY REPORT\n");
    printf("=========================================================\n");

    if (patientCount == 0) {
        printf("No patients registered yet.\n");
        printf("=========================================================\n");
        return;
    }

    int normalCount;
    int urgentCount;
    int criticalCount;

    countByUrgency(
        urgencyLevels,
        patientCount,
        &normalCount,
        &urgentCount,
        &criticalCount
    );

    printf("Total Patients Registered : %d\n",
           patientCount);

    printf("  - Normal (Level 1)      : %d\n",
           normalCount);

    printf("  - Urgent (Level 2)      : %d\n",
           urgentCount);

    printf("  - Critical (Level 3)    : %d\n",
           criticalCount);

    double totalRevenue =
        calculateTotalRevenue(
            finalBillAmounts,
            patientCount
        );

    double totalDiscounts =
        calculateTotalDiscounts(
            discountAmounts,
            patientCount
        );

    printf("---------------------------------------------------------\n");

    printf("Total Revenue Earned      : LKR %.2f\n",
           totalRevenue);

    printf("Total Discounts Granted   : LKR %.2f\n",
           totalDiscounts);

    printf("---------------------------------------------------------\n");
    printf("Bed Occupancy by Ward:\n");

    for (int w = 0; w < NUM_WARDS; w++) {

        double occupancyPercent =
            calculateOccupancyPercentage(
                bedOccupancy,
                w,
                bedCapacities[w]
            );

        printf("  - %-25s : %.1f%%\n",
               wardNames[w],
               occupancyPercent);
    }

    int topIndex =
        findHighestPayingPatient(
            finalBillAmounts,
            patientCount
        );

    printf("---------------------------------------------------------\n");

    printf("Highest-Paying Patient    : %s (%s) - LKR %.2f\n",
           patientNames[topIndex],
           patientIds[topIndex],
           finalBillAmounts[topIndex]);

    printf("=========================================================\n");
}