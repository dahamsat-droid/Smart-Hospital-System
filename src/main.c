#include <stdio.h>
#include "hospital.h"
#include "display.h"
#include "patient.h"
#include "sorting.h"
#include "reports.h"
#include "fileio.h"

/* Reads the menu as a line so non-numeric input does not leave characters in stdin. */
static int readMenuChoice(void) {
    int choice;
    char line[100];

    while (1) {

        printf("Enter your choice: ");

        if (fgets(line, sizeof(line), stdin) != NULL &&
            sscanf(line, "%d", &choice) == 1) {

            return choice;
        }

        printf("Invalid input. Please enter a whole number.\n");
    }
}

int main(void) {

    /*
     * These are fixed lookup tables, so const prevents them
     * from being accidentally changed during program execution.
     */
    const char specialtyNames[NUM_SPECIALTIES][NAME_LEN] = {
        "General Practice (OPD)",
        "Paediatrics",
        "Cardiology",
        "Neurology"
    };

    const double baseFees[NUM_SPECIALTIES] = {
        1500.00,
        2500.00,
        4500.00,
        5000.00
    };

    const int consultTimes[NUM_SPECIALTIES] = {
        15,
        20,
        30,
        30
    };

    const int dailyCaps[NUM_SPECIALTIES] = {
        30,
        20,
        12,
        10
    };

    const char wardNames[NUM_WARDS][NAME_LEN] = {
        "General Ward",
        "Paediatric Ward",
        "Surgical Ward",
        "ICU (Intensive Care Unit)"
    };

    const double dailyRates[NUM_WARDS] = {
        3000.00,
        6000.00,
        12000.00,
        25000.00
    };

    const int bedCapacities[NUM_WARDS] = {
        20,
        10,
        10,
        5
    };

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

    /*
     * Previous records are only used to continue the ID sequence.
     * Current-session arrays begin empty for today's registrations.
     */
    int patientIdCounter = loadPatientCount();

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

        choice = readMenuChoice();

        switch (choice) {

            case 1:
                displaySpecialties(
                    specialtyNames,
                    baseFees,
                    consultTimes,
                    dailyCaps
                );
                break;

            case 2:
                displayWards(
                    wardNames,
                    dailyRates,
                    bedCapacities
                );
                break;

            case 3:
                displayBedStatus(
                    bedOccupancy,
                    wardNames,
                    bedCapacities
                );
                break;

            case 4:
                registerPatient(
                    patientIds,
                    patientNames,
                    patientAges,
                    urgencyLevels,
                    specialtyIds,
                    isAdmitted,
                    wardIds,
                    bedNumbers,
                    daysAdmitted,
                    finalBillAmounts,
                    discountAmounts,
                    &patientCount,
                    &patientIdCounter,
                    bedOccupancy,
                    bedCapacities,
                    specialtyQueueCount,
                    wardNames,
                    specialtyNames,
                    baseFees,
                    dailyRates,
                    consultTimes,
                    dailyCaps
                );
                break;

            case 5:
                sortPatientsByPriority(
                    urgencyLevels,
                    patientCount,
                    sortedIndices
                );

                displaySortedPatients(
                    sortedIndices,
                    patientCount,
                    patientIds,
                    patientNames,
                    urgencyLevels
                );
                break;

            case 6:
                generateSummaryReport(
                    urgencyLevels,
                    patientCount,
                    finalBillAmounts,
                    discountAmounts,
                    patientIds,
                    patientNames,
                    bedOccupancy,
                    bedCapacities,
                    wardNames
                );
                break;

            case 7:
                saveBedStatus(bedOccupancy);

                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1-7.\n");
        }

    } while (choice != 7);

    return 0;
}