#include <stdio.h>
#include "display.h"

/* Displays the fixed doctor information used for registration and billing. */
void displaySpecialties(const char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                        const double baseFees[NUM_SPECIALTIES],
                        const int consultTimes[NUM_SPECIALTIES],
                        const int dailyCaps[NUM_SPECIALTIES]) {

    printf("\n%-4s %-25s %-14s %-14s %-9s\n",
           "ID", "Specialty", "Fee (LKR)", "Time/Patient", "Daily Cap");

    for (int i = 0; i < NUM_SPECIALTIES; i++) {
        printf("%-4d %-25s %-14.2f %-14d %-9d\n",
               i + 1, specialtyNames[i], baseFees[i],
               consultTimes[i], dailyCaps[i]);
    }
}

void displayWards(const char wardNames[NUM_WARDS][NAME_LEN],
                  const double dailyRates[NUM_WARDS],
                  const int bedCapacities[NUM_WARDS]) {

    printf("\n%-4s %-25s %-14s %-9s\n",
           "ID", "Ward", "Rate/Day", "Capacity");

    for (int i = 0; i < NUM_WARDS; i++) {
        printf("%-4d %-25s %-14.2f %-9d\n",
               i + 1, wardNames[i],
               dailyRates[i], bedCapacities[i]);
    }
}

/* Only the beds within each ward's actual capacity are displayed. */
void displayBedStatus(const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                      const char wardNames[NUM_WARDS][NAME_LEN],
                      const int bedCapacities[NUM_WARDS]) {

    for (int w = 0; w < NUM_WARDS; w++) {
        int occupied = 0;

        printf("\n%s: ", wardNames[w]);

        for (int b = 0; b < bedCapacities[w]; b++) {
            printf("%d", bedOccupancy[w][b]);

            if (bedOccupancy[w][b] == 1) {
                occupied++;
            }
        }

        printf("  (%d/%d occupied)\n",
               occupied, bedCapacities[w]);
    }
}