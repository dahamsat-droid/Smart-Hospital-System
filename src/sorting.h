#ifndef SORTING_H
#define SORTING_H

#include "hospital.h"

void sortPatientsByPriority(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    int sortedIndices[MAX_PATIENTS]
);

void displaySortedPatients(
    const int sortedIndices[MAX_PATIENTS],
    int patientCount,
    const char patientIds[MAX_PATIENTS][16],
    const char patientNames[MAX_PATIENTS][NAME_LEN],
    const int urgencyLevels[MAX_PATIENTS]
);

#endif