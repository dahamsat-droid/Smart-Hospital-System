#ifndef BILLING_H
#define BILLING_H

#include "hospital.h"

/* Uses the specialty's current queue count, then increments it by 1 —
 * per the spec's note that queue count increments after each registration. */
double calculateWaitTime(int specialtyQueueCount[NUM_SPECIALTIES], int specialtyId, int consultTimes[NUM_SPECIALTIES]);

double calculateSurcharge(int urgencyLevel, double baseFee);
double calculateWardCost(int daysAdmitted, double wardDailyRate);
double calculateDiscount(int age, double grossTotal);

/* Computes the full bill via the functions above and prints the formatted receipt.
 * outFinalPayable and outDiscount write back the computed amounts so the caller
 * can log them for reporting (e.g. revenue totals) - pass NULL to skip either. */
void printBillReceipt(char *patientId, char *patientName, int age,
                       char *specialtyName, char *wardName, int isAdmitted, int bedNumber,
                       int urgencyLevel, double baseFee, int daysAdmitted, double wardDailyRate,
                       int specialtyQueueCount[NUM_SPECIALTIES], int specialtyId, int consultTimes[NUM_SPECIALTIES],
                       double *outFinalPayable, double *outDiscount);

#endif