#include <stdio.h>
#include "display.h"

void displaySpecialties(char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                         double baseFees[NUM_SPECIALTIES],
                         int consultTimes[NUM_SPECIALTIES],
                         int dailyCaps[NUM_SPECIALTIES]) {
    printf("\n%-4s %-25s %-14s %-14s %-9s\n",
           "ID", "Specialty", "Fee (LKR)", "Time/Patient", "Daily Cap");
    for (int i = 0; i < NUM_SPECIALTIES; i++) {
        printf("%-4d %-25s %-14.2f %-14d %-9d\n",
               i + 1, specialtyNames[i], baseFees[i], consultTimes[i], dailyCaps[i]);
    }
}

void displayWards(char wardNames[NUM_WARDS][NAME_LEN],
                   double dailyRates[NUM_WARDS],
                   int bedCapacities[NUM_WARDS]) {
    printf("\n%-4s %-25s %-14s %-9s\n", "ID", "Ward", "Rate/Day", "Capacity");
    for (int i = 0; i < NUM_WARDS; i++) {
        printf("%-4d %-25s %-14.2f %-9d\n",
               i + 1, wardNames[i], dailyRates[i], bedCapacities[i]);
    }
}

void displayBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                       char wardNames[NUM_WARDS][NAME_LEN],
                       int bedCapacities[NUM_WARDS]) {
    for (int w = 0; w < NUM_WARDS; w++) {
        int occupied = 0;
        printf("\n%s: ", wardNames[w]);
        for (int b = 0; b < bedCapacities[w]; b++) {
            printf("%d", bedOccupancy[w][b]);
            if (bedOccupancy[w][b] == 1) occupied++;
        }
        printf("  (%d/%d occupied)\n", occupied, bedCapacities[w]);
    }