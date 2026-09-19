#ifndef BILLING_H
#define BILLING_H

#include "hospital.h"

double calculateWaitTime(int specialtyQueueCount[NUM_SPECIALTIES],
                         int specialtyId,
                         const int consultTimes[NUM_SPECIALTIES]);

double calculateSurcharge(int urgencyLevel, double baseFee);

double calculateWardCost(int daysAdmitted, double wardDailyRate);

double calculateDiscount(int age, double grossTotal);

void printBillReceipt(const char *patientId,
                      const char *patientName,
                      int age,
                      const char *specialtyName,
                      const char *wardName,
                      int isAdmitted,
                      int bedNumber,
                      int urgencyLevel,
                      double baseFee,
                      int daysAdmitted,
                      double wardDailyRate,
                      int specialtyQueueCount[NUM_SPECIALTIES],
                      int specialtyId,
                      const int consultTimes[NUM_SPECIALTIES],
                      double *outFinalPayable,
                      double *outDiscount);

#endif