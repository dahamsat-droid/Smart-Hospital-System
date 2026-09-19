#ifndef REPORTS_H
#define REPORTS_H

#include "hospital.h"

void countByUrgency(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    int *normalCount,
    int *urgentCount,
    int *criticalCount
);

double calculateTotalRevenue(
    const double finalBillAmounts[MAX_PATIENTS],
    int patientCount
);

double calculateTotalDiscounts(
    const double discountAmounts[MAX_PATIENTS],
    int patientCount
);

double calculateOccupancyPercentage(
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
    int wardIndex,
    int capacity
);

int findHighestPayingPatient(
    const double finalBillAmounts[MAX_PATIENTS],
    int patientCount
);

void generateSummaryReport(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    const double finalBillAmounts[MAX_PATIENTS],
    const double discountAmounts[MAX_PATIENTS],
    const char patientIds[MAX_PATIENTS][16],
    const char patientNames[MAX_PATIENTS][NAME_LEN],
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
    const int bedCapacities[NUM_WARDS],
    const char wardNames[NUM_WARDS][NAME_LEN]
);

#endif