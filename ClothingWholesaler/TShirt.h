#pragma once

#include "ProductType.h"

class TShirt : public ProductType
{
private:

	bool isShortSleevedShirt = false;
	bool isMandarinCollarShirt = false;

public:
	TShirt(std::string ClothName, ProductQuality Quality, int StockAmount,
		   bool isShortSleevedShirt, bool isMandarinCollarShirt)
	{
		this->ProductName = ClothName;
		this->Quality = Quality;
		this->StockAmount = StockAmount;
		this->isShortSleevedShirt = isShortSleevedShirt;
		this->isMandarinCollarShirt = isMandarinCollarShirt;
		
		SetBusinessRules();
	}
	bool GetIsShortSleevedShirt() { return isShortSleevedShirt; }
	bool GetIsMandarinCollarShirt() { return isMandarinCollarShirt; }

	virtual void SetBusinessRules() override;
};