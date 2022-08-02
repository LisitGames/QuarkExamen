#pragma once

#include<string>

class IGenericQuestion
{
public:
	virtual void BinaryQuestion(std::string Question, bool& CurrentAnswer, std::string FirstAnswer = "1.Yes", std::string SecondAnswer = "2.No") = 0;
};

