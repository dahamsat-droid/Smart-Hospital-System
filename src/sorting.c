#include <stdio.h>
#include "sorting.h"

/* Selection sort keeps the original index order when urgency levels are tied. */
void sortPatientsByPriority(
    const int urgencyLevels[MAX_PATIENTS],
    int patientCount,
    int sortedIndices[MAX_PATIENTS]) {

    for (int i = 0; i < patientCount; i++) {
        sortedIndices[i] = i;
    }

    for (int i = 0; i < patientCount - 1; i++) {

        int selected = i;

        for (int j = i + 1; j < patientCount; j++) {

            int a = sortedIndices[selected];
            int b = sortedIndices[j];

            if (urgencyLevels[b] > urgencyLevels[a] ||
                (urgencyLevels[b] == urgencyLevels[a] && b < a)) {

                selected = j;
            }
        }

        if (selected != i) {
            int temp = sortedIndices[i];
            sortedIndices[i] = sortedIndices[selected];
            sortedIndices[selected] = temp;
        }
    }
}

void displaySortedPatients(
    const int sortedIndices[MAX_PATIENTS],
    int patientCount,
    const char patientIds[MAX_PATIENTS][16],
    const char patientNames[MAX_PATIENTS][NAME_LEN],
    const int urgencyLevels[MAX_PATIENTS]) {

    if (patientCount == 0) {
        printf("\nNo patients registered yet.\n");
        return;
    }

    printf("\n%-6s %-10s %-25s %-10s\n",
           "Rank", "ID", "Name", "Urgency");

    for (int rank = 0; rank < patientCount; rank++) {

        int idx = sortedIndices[rank];
        int level = urgencyLevels[idx];

        const char *label =
            (level == 1) ? "Normal" :
            (level == 2) ? "Urgent" : "Critical";

        printf("%-6d %-10s %-25s Level %d (%s)\n",
               rank + 1,
               patientIds[idx],
               patientNames[idx],
               level,
               label);
    }
}