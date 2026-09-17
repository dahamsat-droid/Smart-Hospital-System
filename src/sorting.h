#ifndef SORTING_H
#define SORTING_H

#include "hospital.h"

/* Fills sortedIndices[0..patientCount-1] with patient indices ordered by
 * priority: highest urgency first, and for equal urgency, earlier
 * registration first. Does not move the original patient data. */
void sortPatientsByPriority(int urgencyLevels[MAX_PATIENTS], int patientCount, int sortedIndices[MAX_PATIENTS]);

void displaySortedPatients(int sortedIndices[MAX_PATIENTS], int patientCount,
                            char patientIds[MAX_PATIENTS][16],
                            char patientNames[MAX_PATIENTS][NAME_LEN],
                            int urgencyLevels[MAX_PATIENTS]);

#endif