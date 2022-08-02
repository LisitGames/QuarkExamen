#include "Pants.h"

void Pants::SetBusinessRules()
{
	if (isChupinPants)
	{
		float percent = -0.12f;
		BusinessRulesPercent.push_back(percent);
	}

	if (Quality == ProductQuality::PREMIUM)
	{
		float percent = 0.3f;
		BusinessRulesPercent.push_back(percent);
	}
}
