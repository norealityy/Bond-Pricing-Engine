# Bond Pricing Engine

A console-based finance tool designed to perform financial calculations on bonds; current functionality includes calculating fair value and yield to maturity with customizable benchmark rates and credit spreads.

## Features
* **Fair Bond Value:** Determines the present value of a bond based on the information the user provides about the bond, combining a custom benchmark rate and credit spread to establish an accurate total discount rate.
* **Yield to Maturity:** Calculates the annualized internal rate of return based on the bond's market price.
* **Flexible Payment Frequencies:** Supports annual, semi-annual, quarterly, or monthly coupon payment schedules.
* **Granular Risk Inputs:** Allows manual entry of baseline benchmark rates (e.g U.S. Treasuries or other bonds) and credit spreads measured in Basis Points.
* **Robust Input Validation** Includes error-handling routines to ensure reliable user inputs and prevent console crashes.

---

## Tech Stack
* Languages: C++

## How to Run

### Prerequisites
* A C++ compiler supporting C++11 or later
* Visual Studio or any other C++ IDE

### Building and Running
* Clone the repository: https://github.com/norealityy/Bond-Pricing-Engine
* Open the project in your IDE
* Switch the build configuration to Release
* Build and run the solution to launch the console engine.

### Sample Output

```
Bond Pricing Engine
Enter bond Par Value $: 1000
Enter the interest rate %: 7.5
Enter the amount of years until maturity: 4
Enter how many times the bond is paid a year: 4
Calculate:
 1) Fair Bond Value
 2) Yield to Maturity
1
Enter your benchmark rate %: 4.67
Enter your credit spread BPS: 150

 Discount Rate: 6.17%
 Fair Value: $1046.83

Would you like to run again (y/n)? y
Bond Pricing Engine
Enter bond Par Value $: 1000
Enter the interest rate %: 6.57
Enter the number of years until maturity: 10
Enter how many times the bond is paid a year: 2
Calculate:
 1) Fair Bond Value
 2) Yield to Maturity
2
Enter the market price of the bond: $987.56

Yield to Maturity: 6.74%

Would you like to run again (y/n)? n
```
