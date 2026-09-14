#include <stdio.h>
#include "hospital.h"
#include "display.h"

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

    int choice;

    do {
        printf("\n==================================================\n");
        printf("   SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM\n");
        printf("==================================================\n");
        printf(" 1. View Doctor Specialties\n");
        printf(" 2. View Hospital Wards\n");
        printf(" 3. View Bed Occupancy Status\n");
        printf(" 4. Register New Patient        [coming soon]\n");
        printf(" 5. View Patients by Priority   [coming soon]\n");
        printf(" 6. Generate Summary Report     [coming soon]\n");
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
            case 5:
            case 6:
                printf("\nThis feature is built in a later stage of development.\n");
                break;
            case 7:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}