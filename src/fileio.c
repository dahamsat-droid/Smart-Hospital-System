#include <stdio.h>
#include "fileio.h"

void saveBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]) {
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

void loadBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]) {
    FILE *file = fopen("beds_status.txt", "r");
    if (file == NULL) {
        return; /* no saved file yet - first run, bedOccupancy stays all zeros */
    }

    for (int w = 0; w < NUM_WARDS; w++) {
        for (int b = 0; b < MAX_BEDS_PER_WARD; b++) {
            fscanf(file, "%d", &bedOccupancy[w][b]);
        }
    }

    fclose(file);
}

void logPatientRecord(char *patientId, char *patientName, int urgencyLevel, double finalPayable) {
    FILE *file = fopen("patient_records.txt", "a");
    if (file == NULL) {
        printf("\nWarning: could not write to patient records file.\n");
        return;
    }

    fprintf(file, "%s | %s | Urgency Level %d | Final Payable: LKR %.2f\n",
            patientId, patientName, urgencyLevel, finalPayable);

    fclose(file);
}