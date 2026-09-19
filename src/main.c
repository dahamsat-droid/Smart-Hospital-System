#include <stdio.h>
#include "hospital.h"
#include "display.h"
#include "patient.h"
#include "billing.h"
#include "sorting.h"
#include "reports.h"
#include "fileio.h"

int main(void) {
    char specialtyNames[NUM_SPECIALTIES][NAME_LEN] = {
        "General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology"
    };
    double baseFees[NUM_SPECIALTIES]   = {1500.00, 2500.00, 4500.00, 5000.00};
    int consultTimes[NUM_SPECIALTIES]  = {15, 20, 30, 30};
    int dailyCaps[NUM_SPECIALTIES]     = {30, 20, 12, 10};

    char wardNames[NUM_WARDS][NAME_LEN] = {
        "General Ward", "Paediatric Ward", "Surgical Ward", "ICU (Intensive Care Unit)"
    };
    double dailyRates[NUM_WARDS]    = {3000.00, 6000.00, 12000.00, 25000.00};
    int bedCapacities[NUM_WARDS]    = {20, 10, 10, 5};

    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD] = {0};
    loadBedStatus(bedOccupancy);
    int specialtyQueueCount[NUM_SPECIALTIES] = {0};

    char patientIds[MAX_PATIENTS][16];
    char patientNames[MAX_PATIENTS][NAME_LEN];
    int patientAges[MAX_PATIENTS];
    int urgencyLevels[MAX_PATIENTS];
    int specialtyIds[MAX_PATIENTS];
    int isAdmitted[MAX_PATIENTS];
    int wardIds[MAX_PATIENTS];
    int bedNumbers[MAX_PATIENTS];
    int daysAdmitted[MAX_PATIENTS];
    double finalBillAmounts[MAX_PATIENTS];
    double discountAmounts[MAX_PATIENTS];
    int patientCount = 0;
    int sortedIndices[MAX_PATIENTS];

    int choice;

    do {
        printf("\n==================================================\n");
        printf("   SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM\n");
        printf("==================================================\n");
        printf(" 1. View Doctor Specialties\n");
        printf(" 2. View Hospital Wards\n");
        printf(" 3. View Bed Occupancy Status\n");
        printf(" 4. Register New Patient\n");
        printf(" 5. View Patients by Priority\n");
        printf(" 6. Generate Summary Report\n");
        printf(" 7. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySpecialties(specialtyNames, baseFees, consultTimes, dailyCaps);
                break;
            case 2:
                displayWards(wardNames, dailyRates, bedCapacities);
                break;
            case 3:
                displayBedStatus(bedOccupancy, wardNames, bedCapacities);
                break;
            case 4:
                registerPatient(patientIds, patientNames, patientAges, urgencyLevels,
                                 specialtyIds, isAdmitted, wardIds, bedNumbers, daysAdmitted,
                                 finalBillAmounts, discountAmounts,
                                 &patientCount, bedOccupancy, bedCapacities,
                                 specialtyQueueCount, wardNames, specialtyNames,
                                 baseFees, dailyRates, consultTimes);
                break;
            case 5:
                sortPatientsByPriority(urgencyLevels, patientCount, sortedIndices);
                displaySortedPatients(sortedIndices, patientCount, patientIds, patientNames, urgencyLevels);
                break;
            case 6:
                generateSummaryReport(urgencyLevels, patientCount, finalBillAmounts, discountAmounts,
                                       patientIds, patientNames, bedOccupancy, bedCapacities, wardNames);
                break;
            case 7:
                saveBedStatus(bedOccupancy);
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}