#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "billing.h"
#include "fileio.h"

/* Only used inside this file, so it's not declared in patient.h. */
static int findAvailableBed(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD], int wardIndex, int capacity) {
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
                     int bedCapacities[NUM_WARDS],
                     int specialtyQueueCount[NUM_SPECIALTIES],
                     char wardNames[NUM_WARDS][NAME_LEN],
                     char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                     double baseFees[NUM_SPECIALTIES],
                     double wardDailyRates[NUM_WARDS],
                     int consultTimes[NUM_SPECIALTIES]) {

    if (*patientCount >= MAX_PATIENTS) {
        printf("\nPatient limit reached. Cannot register more patients.\n");
        return -1;
    }

    int i = *patientCount;

    getchar(); /* clears the newline left behind by the menu's scanf("%d", &choice) */

    printf("\nEnter patient name: ");
    fgets(patientNames[i], NAME_LEN, stdin);
    patientNames[i][strcspn(patientNames[i], "\n")] = '\0';

    printf("Enter patient age: ");
    scanf("%d", &patientAges[i]);

    int urgency;
    do {
        printf("Enter urgency level (1 = Normal, 2 = Urgent, 3 = Critical): ");
        scanf("%d", &urgency);
    } while (urgency < 1 || urgency > 3);
    urgencyLevels[i] = urgency;

    int specialty;
    do {
        printf("Enter specialty ID (1-%d): ", NUM_SPECIALTIES);
        scanf("%d", &specialty);
    } while (specialty < 1 || specialty > NUM_SPECIALTIES);
    specialtyIds[i] = specialty;

    int admitted;
    do {
        printf("Is the patient admitted to a ward? (1 = Yes, 0 = No): ");
        scanf("%d", &admitted);
    } while (admitted != 0 && admitted != 1);
    isAdmitted[i] = admitted;

    if (admitted == 1) {
        int ward;
        do {
            printf("Enter ward ID (1-%d): ", NUM_WARDS);
            scanf("%d", &ward);
        } while (ward < 1 || ward > NUM_WARDS);

        int bed = findAvailableBed(bedOccupancy, ward - 1, bedCapacities[ward - 1]);

        if (bed == -1) {
            printf("\nNo beds available in %s. Registering as Outpatient instead.\n", wardNames[ward - 1]);
            isAdmitted[i] = 0;
            wardIds[i] = 0;
            bedNumbers[i] = -1;
            daysAdmitted[i] = 0;
        } else {
            wardIds[i] = ward;
            bedNumbers[i] = bed;
            bedOccupancy[ward - 1][bed] = 1;

            int days;
            do {
                printf("Enter number of days admitted: ");
                scanf("%d", &days);
            } while (days < 1);
            daysAdmitted[i] = days;
        }
    } else {
        wardIds[i] = 0;
        bedNumbers[i] = -1;
        daysAdmitted[i] = 0;
    }

    snprintf(patientIds[i], 16, "PAT-%d", *patientIdCounter + 1001);
    (*patientIdCounter)++;
    (*patientCount)++;

    double wardRateForBill = isAdmitted[i] ? wardDailyRates[wardIds[i] - 1] : 0.0;
    char *wardNameForBill = isAdmitted[i] ? wardNames[wardIds[i] - 1] : "N/A";

    printBillReceipt(patientIds[i], patientNames[i], patientAges[i],
                      specialtyNames[specialty - 1], wardNameForBill, isAdmitted[i], bedNumbers[i],
                      urgencyLevels[i], baseFees[specialty - 1], daysAdmitted[i], wardRateForBill,
                      specialtyQueueCount, specialty, consultTimes,
                      &finalBillAmounts[i], &discountAmounts[i]);

    logPatientRecord(patientIds[i], patientNames[i], urgencyLevels[i], finalBillAmounts[i]);

    return i;
}