#include "ApplicationTools.h"
#include <conio.h>

void ApplicationTools::ShowMainMenu(Store* Store, Seller* Seller, bool& Exit)
{
	std::cout << "EXPRESS QUOTATOR - MAIN MENU\n";

	DIVISIONLINE
		Store->PrintInfo();
	DIVISIONLINE
		Seller->PrintInfo();
	DIVISIONLINE

		std::cout << "SELECT AN OPTION FROM MENU\n\n";

	std::vector<std::string> mainMenuOptions
	{
		"1. Quotations History\n",
		"2. Make a Quotation\n",
		"3. Exit\n"
	};

	for (std::string i : mainMenuOptions)
		std::cout << i;

	ProductType productType;
	switch (CinIntNumber(true, 1, mainMenuOptions.size()) - 1)
	{
	case 0:
		std::system("CLS");
		DIVISIONLINE
			Store->PrintInfo();
		DIVISIONLINE
			Seller->PrintInfo();
		DIVISIONLINE

			//Prints history;
			Seller->PrintHistory();

		//Returns no main menu
		ApplicationTools::ReturnToMainMenu(Store, Seller, Exit);
		break;
	case 1:
		std::system("CLS");
		DIVISIONLINE
			Store->PrintInfo();
		DIVISIONLINE
			Seller->PrintInfo();
		DIVISIONLINE

			//Searches a product type.
			productType = *Store->FilterProduct();

		std::cout << "Enter the unit price of quoted product: \n";
		productType.UnitPrice = ApplicationTools::CinIntNumber(false);

		std::cout << "Information: \n";
		std::cout << "There are/is " << productType.GetStockAmount() << " quantity in stock of the selected product.\n";
		std::cout << "Enter the amount of product units: \n";
		productType.StockAmount = ApplicationTools::CinIntNumber(true, 1, productType.GetStockAmount());

		//Sets parameters to make the quotation.
		// CalculatePriceWithBusinessRules gets the price with rules.
		Seller->CreateNewQuotation(productType.GetProductName(), productType.UnitPrice, productType.StockAmount,
			productType.CalculatePriceWithBusinessRules(productType.UnitPrice));
																				

		//Prints the quote just quoted.
		Seller->PrintLastQuotation();

		//Returns no main menu
		ApplicationTools::ReturnToMainMenu(Store, Seller, Exit);
		break;
	case 2:
		//EXIT
		Exit = true;
		break;
	}
}

void ApplicationTools::ReturnToMainMenu(Store* Store, Seller* Seller, bool& Exit)
{
	DIVISIONLINE
		std::cout << "Press any button to return to main menu: \n";
	_getch();
	std::system("CLS");
	ApplicationTools::ShowMainMenu(Store, Seller, Exit);
}

int ApplicationTools::CinIntNumber(bool HasLimit, int Min, int Max)
{
	short indexOption = 0;
	do
	{
		std::cin >> indexOption;

		if (HasLimit)
		{
			if (indexOption > Max || indexOption < Min)
			{
				std::cin.clear();
				std::cin.ignore();
			}
			else
			{
				return indexOption;
			}
		}
		else
		{
			if (indexOption == NULL)
			{
				std::cin.clear();
				std::cin.ignore();
			}
			else
			{
				return indexOption;
			}
		}
	} while (true);
}