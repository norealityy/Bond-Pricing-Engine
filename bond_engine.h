#pragma once

double calculateBondFairValue(double parValue, double couponRate, int yearsToMaturity, int paymentFrequency, double benchmarkRate, int creditSpreadBPS);
double calculateYTM(double marketPrice, double parValue, double couponRate, int yearsToMaturity, int paymentFrequency);