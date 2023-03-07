#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
	std::string name;
	long population;
	double cost;
};

struct Country
{
	std::string name;
	std::vector<City> cities;
};

struct Tours
{
	std::string title;
	std::vector<Country> countries;
};

int main()
{
	Tours tours
	{ "Tours Ticket Prices from Miami",
		{
			{
				"Colombia",
				{
					{"Bogota", 8778000, 400.98},
					{"Cali", 2401000, 424.12},
					{"Medellin", 2464000, 350.98},
					{"Cartagena", 9720000, 345.34}
				},
			},
			{
				"Brazil",
				{
					{"Rio De Janiero", 13500000, 567.45},
					{"Sao Paulo", 11310000, 975.45},
					{"Salvador", 18234000, 855.99}
				},
			},
			{
				"Chile",
				{
					{"Valdivia", 260000, 569.12},
					{"Santiago", 7040000, 520.00},
				},
			},
			{
				"Argentina",
				{
					{"Buenos Aires", 3010000, 723.77}
				}
			},
		}
	};

	
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::setw(50) <<tours.title << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(20) << std::left << "Country" << std::setw(20) << std::left << "City" << std::setw(20) << std::left << "Population" << std::setw(20) << std::left << "Price" << std::endl;
	std::cout << std::setfill('-') << std::setw(65) << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (auto country : tours.countries)
	{
		for (size_t i = 0; i<country.cities.size(); i++)
		{
			std::cout << std::setw(20) << std::left << ((i==0) ? country.name : "") << std::setw(20) << std::left << country.cities.at(i).name << std::setw(20) << std::left << country.cities.at(i).population << std::setw(20) << std::left << country.cities.at(i).cost << std::endl;
		}
	}

	std::cout << std::endl << std::endl;
	return 0;
}