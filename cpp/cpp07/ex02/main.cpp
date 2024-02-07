#include "Array.hpp"

#define MAX_VAL 750
// int main(int, char**)
// {
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // const int value = rand();
        // numbers[i] = value;
        // mirror[i] = value;
		// std::cout << i << ": " << numbers[i] << std::endl;
    // }
  // SCOPE
    // {
        // Array<int> tmp = numbers;
        // Array<int> test(tmp);
    // }
// 
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // if (mirror[i] != numbers[i])
        // {
            // std::cerr << "didn't save the same value!!" << std::endl;
            // return 1;
        // }
    // }
    // try
    // {
        // numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
        // std::cerr << e.what() << '\n';
    // }
    // try
    // {
		// std::cout << numbers[-42] << std::endl;
    	// numbers[948] = -2147483648;
		// std::cout << numbers[759] << std::endl;
    // }
    // catch(const std::exception& e)
    // {
        // std::cerr << e.what() << '\n';
    // }
// 
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // numbers[i] = rand();
    // }
    // delete [] mirror;//
    // return 0;
// }

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int>	EmptyArray;
	std::cout << "size: " << EmptyArray.size() << std::endl;
	
	Array<int>		IntArray(15);
	IntArray[0] = 1;
	IntArray[1] = 2;
	IntArray[2] = 3;
	IntArray[3] = 4;
	IntArray[4] = 5;
	IntArray[5] = 6;
	IntArray[6] = 7;
	IntArray[7] = 8;
	IntArray[8] = 9;
	IntArray[9] = 10;
	IntArray[10] = 11;
	IntArray[11] = 17;
	IntArray[12] = 11;

	std::cout << "size: " << IntArray.size() << std::endl;
	std::cout << std::endl << "Value of the int array: \n" << std::endl;
	for (int i = 0; i < 13; i++)
		std::cout << IntArray[i] << std::endl;

	Array<std::string>	stringArray(10);
	try
	{
		stringArray[0] = "Lundi";
		stringArray[1] = "Mardi";
		stringArray[2] = "Mercredi";
		stringArray[3] = "Jeudi";
		stringArray[4] = "Vendredi";
		stringArray[5] = "Samedi";
		stringArray[6] = "Dimanche";
		stringArray[7] = "Dimanche";
		stringArray[8] = "Dimanche";
		stringArray[9] = "Dimanche";
		// stringArray[10] = "Dimanche";
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "size: " << stringArray.size() << std::endl;	
	std::cout << std::endl << "Value of the string array: \n" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << stringArray[i] << std::endl;

	Array<std::string>	ChangeStringArray;
	ChangeStringArray = stringArray;
	
	std::cout << "size: " << ChangeStringArray.size() << std::endl;	
	
	ChangeStringArray[1] = "???";
	ChangeStringArray[3] = "???";
	ChangeStringArray[5] = "???";
	
	std::cout << std::endl << "Value of the string array with some change: \n" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << ChangeStringArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl << "Value of the string array: \n" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << stringArray[i] << std::endl;

	try
	{
		std::cout << stringArray[42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}