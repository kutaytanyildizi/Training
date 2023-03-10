#include <iostream>
#include <vector>
#include <string>

enum Direction { North, South, East, West };

enum GroceryItem { Milk, Bread, Apple, Orange };

enum State {EngineFailure, InclementWeather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

std::string directionToString(Direction direction);
void useOfUnscopedEnums();

std::ostream& operator<<(std::ostream& os, GroceryItem groceryItem);
bool isValidGroceryItem(GroceryItem groceryItem);
void displayGroceryList(const std::vector<GroceryItem>& groceryList);
void useOfEnumsWithOverloadedInsertionOperator();

std::istream& operator>>(std::istream& is, State& state);
std::ostream& operator<<(std::ostream& os, const Sequence& sequence);
void initiate(Sequence sequence);
void useOfEnumsWithOverloadedStreamExtractionOperator();


int main()
{
	/*	enum {Red, Green, Blue}; // Implicit initialization
		enum {Red = 1, Green = 2, Blue = 3}; // Explicit initialization
		enum {Red = 1, Green, Blue}; // Explicit/Implicit initialization(Green is initialized to 2 and Blue is initialized to 3) */

	std::cout << "**********UNSCOPED ENUMS**********" << std::endl; 

	useOfUnscopedEnums();
	useOfEnumsWithOverloadedInsertionOperator();
	useOfEnumsWithOverloadedStreamExtractionOperator();

	return 0;
}

std::string directionToString(Direction direction)
{
	// This function excepts a Direction parameter and returns its strings representation

	std::string result;

	switch (direction)
	{
	case North:
		result = "North";
		break;
	case South:
		result = "South";
		break;
	case East:
		result = "East";
		break;
	case West:
		result = "West";
		break;
	default:
		result = "Unknown direction";
		break;
	}

	return result;
}

void useOfUnscopedEnums()
{
	std::cout << "*****Use of Unscoped Enums*****" << std::endl;
	
	Direction direction{ North };
	std::cout << "Direction : " << direction << std::endl;
	std::cout << "Direction : " << directionToString(direction) << std::endl;

	direction = West;
	std::cout << "\nDirection : " << direction << std::endl;
	std::cout << "Direction : " << directionToString(direction) << std::endl;

	// direction = 3 // This statement is generates a compiler error.
	direction = Direction(100);
	std::cout << "\nDirection : " << direction << std::endl;
	std::cout << "Direction : " << directionToString(direction) << std::endl;

	direction = static_cast<Direction>(100);
	std::cout << "\nDirection : " << direction << std::endl;
	std::cout << "Direction : " << directionToString(direction) << std::endl;

	std::cout << "*******************************" << std::endl;
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, GroceryItem groceryItem)
{
	switch (groceryItem)
	{
	case Milk:
		os << "Milk";
		break;
	case Bread:
		os << "Bread";
		break;
	case Apple:
		os << "Apple";
		break;
	case Orange:
		os << "Orange";
		break;
	default:
		os << "Invalid Item";
		break;
	}
	
	return os;
}

bool isValidGroceryItem(GroceryItem groceryItem)
{
	switch (groceryItem)
	{
		case Milk:
		case Bread:
		case Apple:
		case Orange:
			return true;
		default:
			return false;
	}
}

void displayGroceryList(const std::vector<GroceryItem> &groceryList)
{
	int invalidItemCounter{ 0 };
	int validItemCounter{ 0 };

	for (GroceryItem groceryItem : groceryList)
	{
		std::cout << groceryItem << std::endl;
		
		if (isValidGroceryItem(groceryItem))
		{
			validItemCounter++;
		}
		else
		{
			invalidItemCounter++;
		}
	}
	std::cout << "======================" << std::endl;
	std::cout << "Valid Items : " << validItemCounter << std::endl;
	std::cout << "Invalid Items : " << invalidItemCounter << std::endl;
	std::cout << "Total Items : " << validItemCounter + invalidItemCounter << std::endl;
}

void useOfEnumsWithOverloadedInsertionOperator()
{
	std::cout << "*****Use of Enums with Overloaded Insertion Operator*****" << std::endl;

	std::vector<GroceryItem> shoppingList;

	shoppingList.push_back(Apple);
	shoppingList.push_back(Apple);
	shoppingList.push_back(Milk);
	shoppingList.push_back(Orange);

	//GroceryItem item = 100 // This statement generates compile error

	int Helicopter{ 100 };

	shoppingList.push_back(GroceryItem(Helicopter));
	shoppingList.push_back(GroceryItem(0));

	displayGroceryList(shoppingList);

	std::cout << "*********************************************************" << std::endl;
	std::cout << std::endl;
}

std::istream& operator>>(std::istream& is, State& state)
{
	std::underlying_type_t<State> userInput;
	is >> userInput;

	switch (userInput)
	{
		case EngineFailure:
		case InclementWeather:
		case Nominal:
		case Unknown:
			state = State(userInput);
			break;
		default:
			std::cout << "User input is not a valid launch state." << std::endl;
			state = Unknown;
		break;
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Sequence& sequence)
{
	switch (sequence)
	{
		case Abort:
			os << "Abort";
			break;
		case Hold:
			os << "Hold";
			break;
		case Launch:
			os << "Launch";
			break;
	}

	return os;
}

void initiate(Sequence sequence)
{
	std::cout << "Initiate " << sequence << " sequence!" << std::endl; // Uses overloaded operator<<
}

void useOfEnumsWithOverloadedStreamExtractionOperator()
{
	std::cout << "*****Use of Enum with Overloaded Stream Extraction Operator*****" << std::endl;

	State state;
	std::cout << "Launch State : ";
	std::cin >> state;

	switch (state)
	{
		case EngineFailure:
		case Unknown:
			initiate(Abort);
			break;
		case InclementWeather:
			initiate(Hold);
			break;
		case Nominal:
			initiate(Launch);
			break;
	}

	std::cout << "****************************************************************" << std::endl;
	std::cout << std::endl;
}