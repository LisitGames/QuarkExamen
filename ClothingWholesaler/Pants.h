#pragma once

#include "ProductType.h"
class Pants : public ProductType
{
private:

	bool isChupinPants = false;

public:
	Pants(std::string ClothName, ProductQuality Quality, int StockAmount, bool isChupinPants)
	{
		this->ProductName = ClothName;
		this->Quality = Quality;
		this->StockAmount = StockAmount;
		this->isChupinPants = isChupinPants;

		SetBusinessRules();
	}
	bool GetIsChupinPants() { return isChupinPants; }

	virtual void SetBusinessRules() override;
};

