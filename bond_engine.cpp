#include <iostream>
#include <cmath>
#include <iomanip>

double calculateBondFairValue(double parValue, double couponRate, int yearsToMaturity, int paymentFrequency, double benchmarkRate, int creditSpreadBPS)
{
	double totalDiscountRate{ benchmarkRate + (creditSpreadBPS / 10000.0) };

	double c = (parValue * couponRate) / paymentFrequency;
	double r = totalDiscountRate / paymentFrequency;
	int n = yearsToMaturity * paymentFrequency;

	double pvCoupons = c * ((1.0 - std::pow(1.0 + r, -n)) / r);
	double pvParValue = parValue / std::pow(1.0 + r, n);

	return pvCoupons + pvParValue;
}

double calculateYTM(double marketPrice, double parValue, double couponRate, int yearsToMaturity, int paymentFrequency) 
{
    double c = (parValue * couponRate) / paymentFrequency;
    int n = yearsToMaturity * paymentFrequency;

   
    auto getPrice = [&](double r) {
        if (std::abs(r) < 1e-9) {
            return c * n + parValue; 
        }
        double pvCoupons = c * ((1.0 - std::pow(1.0 + r, -n)) / r);
        double pvParValue = parValue / std::pow(1.0 + r, n);
        return pvCoupons + pvParValue;
        };

    double low = -0.99;
    double high = 5.0;  
    double tolerance = 1e-7;
    int maxIterations = 1000;

    double periodicRate = low;

    for (int i = 0; i < maxIterations; ++i) {
        periodicRate = (low + high) / 2.0;
        double estimatedPrice = getPrice(periodicRate);
        double diff = estimatedPrice - marketPrice;

        if (std::abs(diff) < tolerance) {
            break;
        }

        if (estimatedPrice > marketPrice) {
            low = periodicRate;
        }
        else {
            high = periodicRate;
        }
    }

    return (periodicRate * paymentFrequency) * 100;
}