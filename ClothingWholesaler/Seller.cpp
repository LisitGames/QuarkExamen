#include "Seller.h"
#include <iostream>

void Seller::CreateNewQuotation(std::string ClothName,
	float UnitPrice, int ProductUnits, float PriceWithBusinessRules)
{
	//Creates a Quotation instance.
	LastQuotation = new Quotation(SellerID, ClothName, UnitPrice, ProductUnits, PriceWithBusinessRules);
	LastQuotation->ConvertQuotationToString();
	AddQuotationToHistory(LastQuotation->GetQuotationAsString());
}

void Seller::AddQuotationToHistory(std::string QuotationAsString)
{
	QuotationHistory.append(QuotationAsString);
}

void Seller::PrintInfo()
{
	std::cout << "Seller Name: " << GetName() << " " << GetLastName() << " - " << "Seller ID: " << GetSellerID() << "\n";
}
