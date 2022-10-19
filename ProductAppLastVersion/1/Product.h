#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include "ProductType.h"

class Product
{
private:
	uint16_t m_id, m_tva;
	std::string m_name, m_expirationDate;
	float m_price;
	ProductType m_productType;

public:
	Product(uint16_t id, uint16_t tva, std::string name, std::string expirationDate, float price);
	Product(uint16_t id, uint16_t tva, std::string name, ProductType productType, float price);

	uint16_t getId()const;
	uint16_t getTva()const;
	std::string getName()const;
	std::string getExpirationDate()const;
	float getPrice()const;
	ProductType getProductType()const;

	friend std::ostream& operator <<(std::ostream& os, const Product& p);
	
	friend bool operator < (const Product& p1, const Product& p2);
	friend bool comparatorName(const Product& p1, const Product& p2);

///rule of three
	/*product(const product& prod);
	product& operator = (const product& prod);
	~product();*/
};

