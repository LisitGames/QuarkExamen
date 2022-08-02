#pragma once
#include <string>
#include "IPrintable.h"
#include "Quotation.h"
#include "Store.h"

class Seller : public IPrintable
{

private:

	std::string Name;
	std::string LastName;
	int SellerID;

	Quotation* LastQuotation = nullptr;

	//For now we don't need to save the instances. We just print the whole history. 
	std::string QuotationHistory;

private:

void AddQuotationToHistory(std::string QuotationAsString);

public:
	Seller(std::string Name, std::string LastName,
		   int SellerID)
	{
		this->Name = Name; this->LastName = LastName;
		this->SellerID = SellerID;
	}
	void CreateNewQuotation(std::string QuotedCloth, float UnitPrice, int QuotedUnits, float PriceWithBusinessRules);
	const std::string& GetName() const { return Name; }
	const std::string& GetLastName() const { return LastName; }
	const int& GetSellerID() const { return SellerID; }
	void PrintHistory() { std::cout << QuotationHistory; }
	void PrintLastQuotation() { std::cout << LastQuotation->GetQuotationAsString(); }

	void PrintInfo() override;
};

