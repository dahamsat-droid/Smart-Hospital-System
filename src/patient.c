#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "billing.h"
#include "fileio.h"

/* fgets + sscanf prevents invalid text from breaking the input loop. */
static int readInt(const char *prompt) {
    int value;
    char line[100];

    while (1) {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) != NULL &&
            sscanf(line, "%d", &value) == 1) {
            return value;
        }

        printf("Invalid input. Please enter a whole number.\n");
    }
}

static int readIntInRange(const char *prompt, int min, int max) {
    int value;

    do {
        value = readInt(prompt);

        if (value < min || value > max) {
            printf("Please enter a value from %d to %d.\n",
                   min, max);
        }

    } while (value < min || value > max);

    return value;
}

/* Beds are assigned from the first available position in the selected ward. */
static int findAvailableBed(
    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
    int wardIndex,
    int capacity) {

    for (int b = 0; b < capacity; b++) {
        if (bedOccupancy[wardIndex][b] == 0) {
            return b;
        }
    }

    return -1;
}

int registerPatient(char patientIds[MAX_PATIENTS][16],
                    char patientNames[MAX_PATIENTS][NAME_LEN],
                    int patientAges[MAX_PATIENTS],
                    int urgencyLevels[MAX_PATIENTS],
                    int specialtyIds[MAX_PATIENTS],
                    int isAdmitted[MAX_PATIENTS],
                    int wardIds[MAX_PATIENTS],
                    int bedNumbers[MAX_PATIENTS],
                    int daysAdmitted[MAX_PATIENTS],
                    double finalBillAmounts[MAX_PATIENTS],
                    double discountAmounts[MAX_PATIENTS],
                    int *patientCount,
                    int *patientIdCounter,
                    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                    const int bedCapacities[NUM_WARDS],
                    int specialtyQueueCount[NUM_SPECIALTIES],
                    const char wardNames[NUM_WARDS][NAME_LEN],
                    const char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                    const double baseFees[NUM_SPECIALTIES],
                    const double wardDailyRates[NUM_WARDS],
                    const int consultTimes[NUM_SPECIALTIES],
                    const int dailyCaps[NUM_SPECIALTIES]) {

    if (*patientCount >= MAX_PATIENTS) {
        printf("\nPatient limit reached. Cannot register more patients.\n");
        return -1;
    }

    int i = *patientCount;

    printf("\nEnter patient name: ");

    if (fgets(patientNames[i], NAME_LEN, stdin) == NULL) {
        return -1;
    }

    patientNames[i][strcspn(patientNames[i], "\n")] = '\0';

    while (strlen(patientNames[i]) == 0) {
        printf("Patient name cannot be empty.\n");
        printf("Enter patient name: ");

        if (fgets(patientNames[i], NAME_LEN, stdin) == NULL) {
            return -1;
        }

        patientNames[i][strcspn(patientNames[i], "\n")] = '\0';
    }

    patientAges[i] = readIntInRange(
        "Enter patient age: ", 0, 120
    );

    urgencyLevels[i] = readIntInRange(
        "Enter urgency level (1 = Normal, 2 = Urgent, 3 = Critical): ",
        1, 3
    );

    specialtyIds[i] = readIntInRange(
        "Enter specialty ID (1-4): ",
        1, NUM_SPECIALTIES
    );

    /*
     * The cap is checked before changing patientCount or the queue.
     * Therefore, a rejected patient does not affect the daily count.
     */
    if (specialtyQueueCount[specialtyIds[i] - 1] >=
        dailyCaps[specialtyIds[i] - 1]) {

        printf("\nDaily registration cap reached for %s.\n",
               specialtyNames[specialtyIds[i] - 1]);

        printf("Maximum patients for this specialty today: %d\n",
               dailyCaps[specialtyIds[i] - 1]);

        printf("Patient was not registered.\n");

        return -1;
    }

    isAdmitted[i] = readIntInRange(
        "Is the patient admitted to a ward? (1 = Yes, 0 = No): ",
        0, 1
    );

    if (isAdmitted[i] == 1) {

        int ward = readIntInRange(
            "Enter ward ID (1-4): ",
            1, NUM_WARDS
        );

        int bed = findAvailableBed(
            bedOccupancy,
            ward - 1,
            bedCapacities[ward - 1]
        );

        if (bed == -1) {

            printf("\nNo beds available in %s.\n",
                   wardNames[ward - 1]);

            printf("Registering patient as Outpatient instead.\n");

            isAdmitted[i] = 0;
            wardIds[i] = 0;
            bedNumbers[i] = -1;
            daysAdmitted[i] = 0;

        } else {

            wardIds[i] = ward;
            bedNumbers[i] = bed;

            bedOccupancy[ward - 1][bed] = 1;

            daysAdmitted[i] = readIntInRange(
                "Enter number of days admitted: ",
                1, 365
            );
        }

    } else {

        wardIds[i] = 0;
        bedNumbers[i] = -1;
        daysAdmitted[i] = 0;
    }

    /* The stored record count keeps patient IDs continuous after restarting. */
    snprintf(patientIds[i], 16,
             "PAT-%d", *patientIdCounter + 1001);

    (*patientIdCounter)++;
    (*patientCount)++;

    double wardRateForBill =
        isAdmitted[i]
        ? wardDailyRates[wardIds[i] - 1]
        : 0.0;

    const char *wardNameForBill =
        isAdmitted[i]
        ? wardNames[wardIds[i] - 1]
        : "N/A";

    printBillReceipt(
        patientIds[i],
        patientNames[i],
        patientAges[i],
        specialtyNames[specialtyIds[i] - 1],
        wardNameForBill,
        isAdmitted[i],
        bedNumbers[i],
        urgencyLevels[i],
        baseFees[specialtyIds[i] - 1],
        daysAdmitted[i],
        wardRateForBill,
        specialtyQueueCount,
        specialtyIds[i],
        consultTimes,
        &finalBillAmounts[i],
        &discountAmounts[i]
    );

    logPatientRecord(
        patientIds[i],
        patientNames[i],
        urgencyLevels[i],
        finalBillAmounts[i]
    );

    return i;
}