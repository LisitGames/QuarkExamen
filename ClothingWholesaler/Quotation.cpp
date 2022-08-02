#include "Quotation.h"
#include "TShirt.h"
#include "Pants.h"
#include <chrono>

std::string Quotation::ConvertQuotationToString()
{
	GeneratedQuotation =
		"Quote ID: " + std::to_string(ID) + "\n" +
		"Quotation date and time: " + Date + " - " + Time + "\n" +
		"Vendor ID: " + std::to_string(SellerID) + "\n" +
		"Quoted cloth: " + QuotedCloth + "\n" +
		"Unit price: " + std::to_string(UnitPrice) + "\n" +
		"Number of quoted units: " + std::to_string(QuotedUnits) + "\n" +
		"Quotation result: " + std::to_string(QuotationResult) + "\n" +
		"-------------------------------------------------------\n";

	return GeneratedQuotation;
}

int Quotation::ID;

void Quotation::GetCurrentTimeAndDate(std::string& date, std::string& timeRef)
{
	time_t curr_time;
	struct tm curr_tm;
	char date_string[100];
	char time_string[100];

	time(&curr_time);
	localtime_s(&curr_tm,&curr_time);

	strftime(date_string, 50, "%B %d, %Y", &curr_tm);
	strftime(time_string, 50, "%T", &curr_tm);

	date = date_string;
	timeRef = time_string;
}
