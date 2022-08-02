// ClothingWholesaler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Store.h"
#include "Seller.h"
#include "TShirt.h"
#include "Pants.h"
#include "ApplicationTools.h"

int main()
{
	//Creating store and seller
	Store* store = new Store("QuarkAcademy", "Fake Street 123");
	Seller* seller = new Seller("Francisco", "Quiroga", 10);

	//Adding the stock
	store->AddProduct(new TShirt("TShirt-ShortSleeve-MandarinCollar-PREMIUM",ProductQuality::PREMIUM, 100, true, true));
	store->AddProduct(new TShirt("TShirt-ShortSleeve-MandarinCollar-STANDARD",ProductQuality::STANDARD, 100, true, true));
	store->AddProduct(new TShirt("TShirt-ShortSleeve-CommonCollar-PREMIUM", ProductQuality::PREMIUM, 150, true, false));
	store->AddProduct(new TShirt("TShirt-ShortSleeve-CommonCollar-STANDARD", ProductQuality::STANDARD, 150, true, false));
		 
	store->AddProduct(new TShirt("TShirt-LongSleeve-MandarinCollar-PREMIUN", ProductQuality::PREMIUM, 75, false, true));
	store->AddProduct(new TShirt("TShirt-LongSleeve-MandarinCollar-STANDARD", ProductQuality::STANDARD, 75, false, true));
	store->AddProduct(new TShirt("TShirt-LongSleeve-CommonCollar-PREMIUM", ProductQuality::PREMIUM, 175, false, false));
	store->AddProduct(new TShirt("TShirt-LongSleeve-CommonCollar-STANDARD", ProductQuality::STANDARD, 175, false, false));

	store->AddProduct(new Pants("Pants-Common-PREMIUM", ProductQuality::PREMIUM, 750, false));
	store->AddProduct(new Pants("Pants-Common-STANDARD", ProductQuality::STANDARD, 750, false));
	store->AddProduct(new Pants("Pants-Chupin-PREMIUM", ProductQuality::PREMIUM, 250, true));
	store->AddProduct(new Pants("Pants-Chupin-STANDARD", ProductQuality::STANDARD, 250, true));

	bool exit = false;
	ApplicationTools::ShowMainMenu(store, seller, exit);

	if (exit)
	{
		delete store;
		delete seller;
		return 3;
	}
}