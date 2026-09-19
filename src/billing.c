#include <stdio.h>
#include "billing.h"

/* The current queue is used first, then increased for the new patient. */
double calculateWaitTime(int specialtyQueueCount[NUM_SPECIALTIES],
                         int specialtyId,
                         const int consultTimes[NUM_SPECIALTIES]) {

    double waitTime =
        specialtyQueueCount[specialtyId - 1] *
        consultTimes[specialtyId - 1];

    specialtyQueueCount[specialtyId - 1]++;

    return waitTime;
}

double calculateSurcharge(int urgencyLevel, double baseFee) {

    if (urgencyLevel == 2) {
        return baseFee * 0.20;
    }

    if (urgencyLevel == 3) {
        return baseFee * 0.50;
    }

    return 0.0;
}

double calculateWardCost(int daysAdmitted, double wardDailyRate) {
    return daysAdmitted * wardDailyRate;
}

/* The age subsidy is applied to the complete gross bill. */
double calculateDiscount(int age, double grossTotal) {

    if (age < 5 || age > 65) {
        return grossTotal * 0.15;
    }

    return 0.0;
}

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
                      double *outDiscount) {

    double surcharge = calculateSurcharge(urgencyLevel, baseFee);

    double wardCost = isAdmitted
                      ? calculateWardCost(daysAdmitted, wardDailyRate)
                      : 0.0;

    double grossTotal = baseFee + surcharge + wardCost;

    int subsidyEligible = (age < 5 || age > 65);

    double discount = calculateDiscount(age, grossTotal);
    double finalPayable = grossTotal - discount;

    double waitTime = calculateWaitTime(
        specialtyQueueCount, specialtyId, consultTimes
    );

    double surchargePercent =
        (urgencyLevel == 2) ? 20.0 :
        (urgencyLevel == 3) ? 50.0 : 0.0;

    const char *urgencyLabel =
        (urgencyLevel == 1) ? "Normal" :
        (urgencyLevel == 2) ? "Urgent" : "Critical";

    printf("\n====================================================\n");
    printf("      SMART HOSPITAL ADMISSION & BILL\n");
    printf("----------------------------------------------------\n");

    printf("Patient ID     : %s\n", patientId);
    printf("Patient Name   : %s\n", patientName);
    printf("Age            : %d Years%s\n",
           age,
           subsidyEligible ? " (15% Subsidy Eligible)" : "");

    printf("Specialty      : %s\n", specialtyName);

    if (isAdmitted) {
        printf("Assigned Ward  : %s (Bed #%02d)\n",
               wardName, bedNumber + 1);
    } else {
        printf("Assigned Ward  : Outpatient (OPD)\n");
    }

    printf("Urgency Level  : Level %d (%s)\n",
           urgencyLevel, urgencyLabel);

    printf("----------------------------------------------------\n");

    printf("Base Consultation Fee   : LKR %.2f\n", baseFee);

    printf("Emergency Surcharge     : LKR %.2f (%.0f%%)\n",
           surcharge, surchargePercent);

    if (isAdmitted) {
        printf("Ward Stay Cost (%d Days) : LKR %.2f\n",
               daysAdmitted, wardCost);
    } else {
        printf("Ward Stay Cost          : LKR 0.00\n");
    }

    printf("----------------------------------------------------\n");

    printf("Gross Total Bill        : LKR %.2f\n",
           grossTotal);

    if (subsidyEligible) {
        printf("Age Subsidy Discount    : LKR -%.2f (15%%)\n",
               discount);
    } else {
        printf("Age Subsidy Discount    : LKR 0.00 (0%%)\n");
    }

    printf("----------------------------------------------------\n");

    printf("Final Payable Amount    : LKR %.2f\n",
           finalPayable);

    if (urgencyLevel == 3) {
        printf("Estimated Waiting Time  : %.2f mins (Immediate Attention)\n",
               waitTime);
    } else {
        printf("Estimated Waiting Time  : %.2f mins\n",
               waitTime);
    }

    printf("====================================================\n");

    if (outFinalPayable != NULL) {
        *outFinalPayable = finalPayable;
    }

    if (outDiscount != NULL) {
        *outDiscount = discount;
    }
}