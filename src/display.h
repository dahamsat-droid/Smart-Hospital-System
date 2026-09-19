#ifndef DISPLAY_H
#define DISPLAY_H

#include "hospital.h"

void displaySpecialties(const char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                        const double baseFees[NUM_SPECIALTIES],
                        const int consultTimes[NUM_SPECIALTIES],
                        const int dailyCaps[NUM_SPECIALTIES]);

void displayWards(const char wardNames[NUM_WARDS][NAME_LEN],
                  const double dailyRates[NUM_WARDS],
                  const int bedCapacities[NUM_WARDS]);

void displayBedStatus(const int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                      const char wardNames[NUM_WARDS][NAME_LEN],
                      const int bedCapacities[NUM_WARDS]);

#endif