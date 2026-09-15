#ifndef PATIENT_H
#define PATIENT_H

#include "hospital.h"

/* Registers one patient: collects input, assigns a bed if admitted,
 * updates the specialty queue count, and prints a confirmation.
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
                     int *patientCount,
                     int bedOccupancy[NUM_WARDS][MAX_BEDS_PER_WARD],
                     int bedCapacities[NUM_WARDS],
                     int specialtyQueueCount[NUM_SPECIALTIES],
                     char wardNames[NUM_WARDS][NAME_LEN]);

#endif