#ifndef REPORTS_H
#define REPORTS_H

#include "hospital.h"

void countByUrgency(int urgencyLevels[MAX_PATIENTS], int patientCount,
                     int *normalCount, int *urgentCount, int *criticalCount);

double calculateTotalRevenue(double finalBillAmounts[MAX_PATIENTS], int patientCount);
double calculateTotalDiscounts(double discountAmounts[MAX_PATIENTS], int patientCount);

double calculateOccupancyPercentage(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD], int wardIndex, int capacity);

/* Returns the index of the patient with the highest final bill, or -1 if patientCount is 0. */
int findHighestPayingPatient(double finalBillAmounts[MAX_PATIENTS], int patientCount);

void generateSummaryReport(int urgencyLevels[MAX_PATIENTS], int patientCount,
                            double finalBillAmounts[MAX_PATIENTS], double discountAmounts[MAX_PATIENTS],
                            char patientIds[MAX_PATIENTS][16], char patientNames[MAX_PATIENTS][NAME_LEN],
                            int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                            int bedCapacities[NUM_WARDS], char wardNames[NUM_WARDS][NAME_LEN]);

#endif