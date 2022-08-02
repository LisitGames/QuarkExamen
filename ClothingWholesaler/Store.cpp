#include "Store.h"
#include "TShirt.h"
#include "Pants.h"
#include "ApplicationTools.h"

Store::Store(std::string CompanyName, std::string Adress)
{
	this->CompanyName = CompanyName;
	this->Adress = Adress;
}

void Store::AddProduct(ProductType* Product)
{
	Products.push_back(Product);
}

const ProductType* Store::FilterProduct()
{
	//Ask for the ProductType
	std::cout << "Select the cloth that you want to Quote:\n";
	std::cout << "1. Tshirt\n";
	std::cout << "2. Pants\n";

	bool isPremium;

	switch (ApplicationTools::CinIntNumber())
	{
	case 1:
		//Asks for short sleeved shirt.
		bool isShortSleevedShirt;
		BinaryQuestion("Is the cloth to Quote Short Sleeved Shirt?", isShortSleevedShirt);

		//Asks for mandarin collar shirt.
		bool isMandarinCollarShirt;
		BinaryQuestion("Is the cloth to Quote  Mandarin Collar Shirt?", isMandarinCollarShirt);

		//Asks if the cloth is premium
		BinaryQuestion("Select the Cloth Quality", isPremium, "1. PREMIUM", "2. STANDARD");

		for (ProductType* i : Products)
		{
			TShirt* ts = dynamic_cast<TShirt*>(i);

			if (ts == nullptr)
				continue;

			if (ts->GetIsShortSleevedShirt() != isShortSleevedShirt)
				continue;

			if (ts->GetIsMandarinCollarShirt() != isMandarinCollarShirt)
				continue;

			if ((int)ts->GetProductQuality() != (int)isPremium)
				continue;

			return i;
		}
		break;

	case 2:
		//Asks for chupin pants.
		bool isChupinPants;
		BinaryQuestion("Is the cloth to Quote a chupin pants?", isChupinPants);

		//Asks if the cloth is premium
		BinaryQuestion("Select the Cloth Quality", isPremium, "1. PREMIUM", "2. STANDARD");

		for (ProductType* i : Products)
		{
			Pants* ps = dynamic_cast<Pants*>(i);

			if (ps == nullptr)
				continue;

			if (ps->GetIsChupinPants() != isChupinPants)
				continue;

			if ((int)ps->GetProductQuality() != (int)isPremium)
				continue;

			return i;
		}
		break;
	}

	return nullptr;
}

void Store::PrintInfo()
{
	std::cout << "Company Name: " << GetCompanyName() << " - " << "Address: " << GetAdress() << "\n";
}

void Store::BinaryQuestion(std::string Question, bool& CurrentAnswer, std::string FirstAnswer, std::string SecondAnswer)
{
	std::cout << Question << "\n";
	std::cout << FirstAnswer << "\n";
	std::cout << SecondAnswer << "\n";

	switch (ApplicationTools::CinIntNumber())
	{
	case 1:
		CurrentAnswer = true;
		break;

	case 2:
		CurrentAnswer = false;
		break;
	default:
		std::cout << "Wrong answer. Try again...";
		BinaryQuestion(Question, CurrentAnswer, FirstAnswer, SecondAnswer);
		break;
	}
}