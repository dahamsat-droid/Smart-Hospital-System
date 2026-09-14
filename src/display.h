#ifndef DISPLAY_H
#define DISPLAY_H

#include "hospital.h"

void displaySpecialties(char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                         double baseFees[NUM_SPECIALTIES],
                         int consultTimes[NUM_SPECIALTIES],
                         int dailyCaps[NUM_SPECIALTIES]);

void displayWards(char wardNames[NUM_WARDS][NAME_LEN],
                   double dailyRates[NUM_WARDS],
                   int bedCapacities[NUM_WARDS]);

void displayBedStatus(int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                       char wardNames[NUM_WARDS][NAME_LEN],
                       int bedCapacities[NUM_WARDS]);

#endif