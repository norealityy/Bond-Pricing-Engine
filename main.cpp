#include <iostream>
#include <cmath>
#include <iomanip>

#include "bond_engine.h"
#include "bond_info.h"
#include "inputVerification.h"


int main() 
{
	while (true) 
	{
	
		std::cout << "Bond Pricing Engine\n";

		// Get some initial information about the bonds

		double parValue{ getParValue() };
		double couponRate{ getCouponRate() };
		int yearsToMaturity{ getYearsToMaturity() };
		int paymentFrequency{ getPaymentFrequency() };

		// Ask the user what they want to solve for

		int solveFor{};
		std::string options{ "Calculate: \n 1) Fair Bond Value \n 2) Yield to Maturity\n" };
	
		// Verifying the user input to pick which path

		VerifyInt(solveFor, options);

		while (solveFor != 1 && solveFor != 2) 
		{
			std::cout << "invalid input, " << options;
			std::cin >> solveFor;
		}


		// Formating it so it doesnt output in scientific notation

		std::cout << std::fixed << std::setprecision(2);
		switch (solveFor) 
		{
			case 1:
			{
				// Asking for benchmark rate and credit spread then outputs the discount rate and the fair value of the bond

				double benchmarkRate{ getBenchmarkRate() };
				int creditSpreadBPS{ getCreditSpreadBPS() };
				double discountRate{ (benchmarkRate * 100) + (static_cast<double>(creditSpreadBPS) / 100) };
				std::cout << "\n Discount Rate: " << discountRate << "%\n";
				std::cout << " Fair Value: $" << calculateBondFairValue(parValue, couponRate, yearsToMaturity, paymentFrequency, benchmarkRate, creditSpreadBPS) << '\n';
				break;
			}
			case 2:
				{

				// Asking for the market price of the bond then outputs the yield to maturity

				double marketPrice{ getMarketPrice() };
				std::cout << "\n" << "Yield to Maturity: " << calculateYTM(marketPrice, parValue, couponRate, yearsToMaturity, paymentFrequency) << "%\n";
				break;
				}
		}

		// Handling the loop to exit or run again

		char exitChoice{};
		std::string exitPrompt{ "\nWould you like to run again (y/n)? " };

		VerifyChar(exitChoice, exitPrompt);

		while (exitChoice != 'y' && exitChoice != 'n') 
		{
			std::cout << "invalid input, " << exitPrompt;
			std::cin >> exitChoice;
		}

		if (exitChoice == 'y') 
		{
			continue;
		}
		else 
		{
			break;
		}

	}

	return 0;
}