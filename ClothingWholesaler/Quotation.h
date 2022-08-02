#pragma once

#include <iostream>
#include <string>

class Quotation
{

private:

	static int ID;
	std::string Date;
	std::string Time;
	int SellerID;
	std::string QuotedCloth;
	float UnitPrice;
	int QuotedUnits;
	float QuotationResult;

	std::string GeneratedQuotation;

private:

	void GetCurrentTimeAndDate(std::string& Date, std::string& Time);

public:

	Quotation(int SellerID, std::string QuotedCloth,
			  float UnitPrice, int QuotedUnits, float BusinessRulesPercentPrice)
	{
		ID = ID++;
		GetCurrentTimeAndDate(Date, Time);
		this->SellerID = SellerID;
		this->QuotedCloth = QuotedCloth;
		this->UnitPrice = UnitPrice;
		this->QuotedUnits = QuotedUnits;
		//Multiplies the rules per quoted units
		QuotationResult = BusinessRulesPercentPrice * QuotedUnits;
	}

	std::string ConvertQuotationToString();
	void PrintQuotation() { std::cout << GeneratedQuotation; }
	std::string GetQuotationAsString() { return GeneratedQuotation; }
};