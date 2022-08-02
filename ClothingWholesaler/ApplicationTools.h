#pragma once

#include "Store.h"
#include "Seller.h"

#define DIVISIONLINE printf("-------------------------------------------------------\n");

class ApplicationTools
{

public:
	static void ShowMainMenu(Store* Store, Seller* Seller, bool& Exit);
	static void ReturnToMainMenu(Store* Store, Seller* Seller, bool& Exit);
	static int CinIntNumber(bool HasLimit = true, int Min = 1, int Max = 2);
};

