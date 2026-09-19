#include <stdio.h>
#include "fileio.h"

/* Bed data is overwritten with the latest occupancy state when the program exits. */
void saveBedStatus(
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]) {

    FILE *file = fopen("beds_status.txt", "w");

    if (file == NULL) {
        printf("\nWarning: could not save bed status to file.\n");
        return;
    }

    for (int w = 0; w < NUM_WARDS; w++) {

        for (int b = 0; b < MAX_BEDS_PER_WARD; b++) {
            fprintf(file, "%d ", bedOccupancy[w][b]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

void loadBedStatus(
    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]) {

    FILE *file = fopen("beds_status.txt", "r");

    if (file == NULL) {
        return;
    }

    for (int w = 0; w < NUM_WARDS; w++) {

        for (int b = 0; b < MAX_BEDS_PER_WARD; b++) {
            fscanf(file, "%d", &bedOccupancy[w][b]);
        }
    }

    fclose(file);
}

/* Patient records are appended so previous billing records are not overwritten. */
void logPatientRecord(
    const char *patientId,
    const char *patientName,
    int urgencyLevel,
    double finalPayable) {

    FILE *file = fopen("patient_records.txt", "a");

    if (file == NULL) {
        printf("\nWarning: could not write to patient records file.\n");
        return;
    }

    fprintf(file,
            "%s | %s | Urgency Level %d | Final Payable: LKR %.2f\n",
            patientId,
            patientName,
            urgencyLevel,
            finalPayable);

    fclose(file);
}

int loadPatientCount(void) {

    FILE *file = fopen("patient_records.txt", "r");

    if (file == NULL) {
        return 0;
    }

    int count = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {

        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);

    return count;
}