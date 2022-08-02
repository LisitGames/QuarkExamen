#include "TShirt.h"

void TShirt::SetBusinessRules()
{
	if (isShortSleevedShirt)
	{
		float percent = -0.1f;
		BusinessRulesPercent.push_back(percent);
	}

	if (isMandarinCollarShirt)
	{
		float percent = 0.03f;
		BusinessRulesPercent.push_back(percent);
	}

	if (Quality == ProductQuality::PREMIUM)
	{
		float percent = -0.3f;
		BusinessRulesPercent.push_back(percent);
	}
}
