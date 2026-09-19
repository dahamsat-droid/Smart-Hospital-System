#ifndef PATIENT_H
#define PATIENT_H

#include "hospital.h"

/* Registers one patient: collects input, assigns a bed if admitted,
 * then calls billing.c to compute and print the full bill (which also
 * updates the specialty queue count as part of the wait-time calculation).
 * Returns the patient's array index, or -1 if MAX_PATIENTS is reached. */
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
                     int bedCapacities[NUM_WARDS],
                     int specialtyQueueCount[NUM_SPECIALTIES],
                     char wardNames[NUM_WARDS][NAME_LEN],
                     char specialtyNames[NUM_SPECIALTIES][NAME_LEN],
                     double baseFees[NUM_SPECIALTIES],
                     double wardDailyRates[NUM_WARDS],
                     int consultTimes[NUM_SPECIALTIES]);

#endif