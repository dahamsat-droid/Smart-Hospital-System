#ifndef FILEIO_H
#define FILEIO_H

#include "hospital.h"

void saveBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]);

/* If beds_status.txt doesn't exist yet (first run), leaves bedOccupancy
 * untouched (already zero-initialized by main) rather than erroring. */
void loadBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]);

/* Appends one line to patient_records.txt - called at registration time,
 * not at exit, so a record survives even if the program doesn't exit cleanly. */
void logPatientRecord(char *patientId, char *patientName, int urgencyLevel, double finalPayable);

/* Counts existing lines in patient_records.txt so patientCount can continue
 * from where the last run left off, instead of restarting IDs at PAT-1001
 * every time the program runs. Returns 0 if the file doesn't exist yet. */
int loadPatientCount(void);

#endif