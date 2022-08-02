#pragma once
#include <string>
#include <vector>

enum class ProductQuality
{
	STANDARD = 0,
	PREMIUM = 1

};

class ProductType
{

protected:
	ProductQuality Quality = ProductQuality::STANDARD;

	std::string ProductName;

	std::vector<float> BusinessRulesPercent;

public:

	float UnitPrice = 0.f;;
	int StockAmount = 0;

public:
	std::string GetProductName() { return ProductName; }
	ProductQuality GetProductQuality() { return Quality; }
	float GetUnitPrice() { return UnitPrice; }
	int GetStockAmount() { return StockAmount; }
	float CalculatePriceWithBusinessRules(float UnitPrice);

	virtual void SetBusinessRules(){}
};

