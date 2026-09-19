#ifndef PATIENT_H
#define PATIENT_H

#include "hospital.h"

int registerPatient(char patientIds[MAX_PATIENTS][16],
                    char patientNames[MAX_PATIENTS][NAME_LEN],
                    int patientAges[MAX_PATIENTS],
                    int urgencyLevels[MAX_PATIENTS],
                    int specialtyIds[MAX_PATIENTS],
                    int isAdmitted[MAX_PATIENTS],
                    int wardIds[MAX_PATIENTS],
                    int bedNumbers[MAX_PATIENTS],
                    int daysAdmitted[MAX_PATIENTS],
                    double finalBillAmounts[MAX_PATIENTS],
                    double discountAmounts[MAX_PATIENTS],
                    int *patientCount,
                    int *patientIdCounter,
                    int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                    const int bedCapacities[NUM_WARDS],
                    int specialtyQueueCount[NUM_SPECIALTIES],
                    const char wardNames[NUM_WARDS][NAME_LEN],
                    const char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                    const double baseFees[NUM_SPECIALTIES],
                    const double wardDailyRates[NUM_WARDS],
                    const int consultTimes[NUM_SPECIALTIES],
                    const int dailyCaps[NUM_SPECIALTIES]);

#endif