#pragma once
#include <cstdint>
#include <string>
#include <iostream>

enum class ProductType:uint8_t
{
	SmallAppliences, 
	PersonalHygiene, 
	Clothing
};

ProductType parseProductType(const std::string str);
std::ostream& operator<<(std::ostream& os, const ProductType& type);