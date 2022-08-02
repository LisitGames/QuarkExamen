#pragma once
#include <string>
#include "IPrintable.h"
#include "IGenericQuestion.h"
#include "ProductType.h"
#include <list>
#include <iostream>

class Store : public IPrintable, public IGenericQuestion
{

private:

	std::string CompanyName;
	std::string Adress;
	std::list<ProductType*> Products;

public:

	Store(std::string CompanyName, std::string Adress);
	const std::string& GetCompanyName() const { return CompanyName; };
	const std::string& GetAdress() const { return Adress; };
	void AddProduct(ProductType* Product);
	const ProductType* FilterProduct();
	virtual void PrintInfo() override;
	virtual void BinaryQuestion(std::string Question, bool& CurrentAnswer, std::string FirstAnswer = "1.Yes", std::string SecondAnswer = "2.No") override;
	~Store() { for (ProductType* p : Products) delete p; };
};