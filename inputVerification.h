#pragma once

#include <iostream>
#include <limits>

inline void Ignore() 
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void VerifyDouble(double& value, std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (!std::cin || std::cin.peek() != '\n')
		{
			std::cout << "Invalid input, ";
			std::cin.clear();
			Ignore();
		}
		else
		{
			Ignore();
			break;
		}
	}
}


inline void VerifyInt(int& value, std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (!std::cin || std::cin.peek() != '\n')
		{
			std::cout << "Invalid input, ";
			std::cin.clear();
			Ignore();
		}
		else
		{
			Ignore();
			break;
		}
	}
}

inline void VerifyString(std::string input, std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin || std::cin.peek() != '\n')
		{
			std::cout << "Invalid input, ";
			std::cin.clear();
			Ignore();
		}
		else
		{
			Ignore();
			break;
		}
	}
}

inline void VerifyChar(char& input, std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin || std::cin.peek() != '\n')
		{
			std::cout << "Invalid input, ";
			std::cin.clear();
			Ignore();
		}
		else
		{
			Ignore();
			break;
		}
	}
}


