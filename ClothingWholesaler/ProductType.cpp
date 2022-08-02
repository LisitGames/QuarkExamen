#include "ProductType.h"

float ProductType::CalculatePriceWithBusinessRules(float UnitPrice)
{
	for (float i : BusinessRulesPercent)
	{
		UnitPrice = UnitPrice + (UnitPrice * i);
	}
	return UnitPrice;
}
