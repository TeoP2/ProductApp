#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"
#include "ProductType.h"
#include <regex>
#include <algorithm>

void readFile(std::vector<Product>& products)
{
	std::ifstream file{ "product.prodb" };   
	//file.open("product.prodb");  optional

	//for (std::ifstream file{ "product.probd" }; !file.eof();/*empty*/)
	//{

	//}

	if (!file)
	{
		std::cerr << "file error\n";
		exit(0);
	}

	{
		uint16_t id, tva;
		std::string name, expirationDateOrType;
		float price;

		std::regex dateFormat(R"(\d\d\d\d-\d\d-\d\d)");

		while (file)
		{
			file >> id >> name >> price >> tva >> expirationDateOrType;
			if (std::regex_match(expirationDateOrType, dateFormat))
				products.emplace_back(Product(id, tva, name, expirationDateOrType, price));
			else
				products.push_back(Product(id, tva, name, parseProductType(expirationDateOrType), price));

		}
	}
}

bool compareName(const Product& p1, const Product& p2)
{
	return p1.getName() < p2.getName();
}

int main()
{
	std::vector<Product> sproducts;

	readFile(sproducts);

	//for (int i = 0; i < sproducts.size(); i++)
	//{
	//	if (sproducts[i].getTva() == 19)
	//	{
	//		std::cout << sproducts[i];
	//	}
	//}

	for (const Product& product : sproducts)
	{
		if (product.getTva() == 19)
		{
			std::cout << product;
		}
	}


	///comparatori
	///1. o functie obisnuita

	std::sort(sproducts.begin(), sproducts.end(), compareName);

	///2. cu operatorul < (operatorul pe care il foloseste std::sort)
	
	/*std::sort(sproducts.begin(), sproducts.end());

	///3. functie lambda (functie anonima)

	std::sort(sproducts.begin(), sproducts.end(), [](const product& p1, const product& p2){
		return p1.getPrice() < p2.getPrice();
		});*/
	///[] - lista de capturare (putem sa punem toate variabilele la care vrem sa avem acces in functie) 
	///() - parametrii functiei 
	///{} - corpul functiei

	///4. o functie obisnuita, metoda a clasei
	/*std::sort(sproducts.begin(), sproducts.end(), comparatorName);*/

	return 0;
}
