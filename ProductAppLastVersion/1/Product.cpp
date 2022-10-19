#include "Product.h"

Product::Product(uint16_t id, uint16_t tva, std::string name, std::string expirationDate, float price)
	:m_id{ id }, m_tva{ tva }, m_name{ name }, m_expirationDate{ expirationDate }, m_price{ price }
{

}

Product::Product(uint16_t id, uint16_t tva, std::string name, ProductType productType, float price)
	:m_id{ id }, m_tva{ tva }, m_name{ name }, m_productType{ productType }, m_price{ price }
{

}

uint16_t Product::getId() const
{
	return m_id;
}

uint16_t Product::getTva() const
{
	return m_tva;
}

std::string Product::getName() const
{
	return m_name;
}

std::string Product::getExpirationDate() const
{
	return m_expirationDate;
}

float Product::getPrice() const
{
	return (m_tva/100*m_price)+m_price;
}

ProductType Product::getProductType() const
{
	return m_productType;
}

//bool product::comparatorName(const product &p1 ,const product& p2)
//{
//	return p1.getPrice() < p2.getPrice();
//}

std::ostream& operator<<(std::ostream& os, const Product& p)
{
	os << p.m_id << " " << p.m_name << " " << p.getPrice() << " " << p.m_tva << " ";
	if (p.m_tva == 9)
	{
		os << p.m_expirationDate<<std::endl;
	}
	else
	{
		os << p.m_productType << std::endl;
	}
	return os;
}

bool operator<(const Product& p1, const Product& p2)
{
	return p1.getName() < p2.getName();
}
