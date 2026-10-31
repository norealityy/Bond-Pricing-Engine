#include <iostream>
#include "inputVerification.h"

double getMarketPrice() 
{
	double marketPrice{};
	std::string prompt{ "Enter the market price of the bond: $" };

	VerifyDouble(marketPrice, prompt);

	return marketPrice;
}

double getParValue() 
{
	double parValue{};
	std::string prompt{ "Enter bond Par Value $: " };
	
	VerifyDouble(parValue, prompt);

	return parValue;
}

double getCouponRate() 
{
	double couponRate{};
	std::string prompt{ "Enter the interest rate %: " };

	VerifyDouble(couponRate, prompt);

	return couponRate / 100;
}

double getBenchmarkRate() 
{
	double benchmarkRate{};
	std::string prompt{ "Enter your benchmark rate %: " };

	VerifyDouble(benchmarkRate, prompt);

	return benchmarkRate / 100;
}

int getYearsToMaturity() 
{
	int ytm{};
	std::string prompt{ "Enter the number of years until maturity: " };

	VerifyInt(ytm, prompt);

	return ytm;
}

int getPaymentFrequency() 
{
	int freq{};
	std::string prompt{ "Enter how many times the bond is paid a year: " };

	VerifyInt(freq, prompt);

	return freq;
}

int getCreditSpreadBPS() 
{
	int bps{};
	std::string prompt{ "Enter your credit spread BPS: " };

	VerifyInt(bps, prompt);

	return bps;
}