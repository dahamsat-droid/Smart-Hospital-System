#ifndef FILEIO_H
#define FILEIO_H

#include "hospital.h"

void saveBedStatus(
    const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]
);

void loadBedStatus(
    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD]
);

void logPatientRecord(
    const char *patientId,
    const char *patientName,
    int urgencyLevel,
    double finalPayable
);

int loadPatientCount(void);

#endif