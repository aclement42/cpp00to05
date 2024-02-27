#include "Span.hpp"

// int main()
// {
    // Span sp = Span(5);
// 
    // try
    // {
        // sp.addNumber(8);
        // sp.addNumber(5);
        // sp.addNumber(5);
        // sp.addNumber(-78);
        // sp.addNumber(-79);
        // sp.addNumber(-80);
        // sp.addNumber(-81);
        // sp.addNumber(-78);
// 
        // sp.addNumber(1);
        // sp.addNumber(-78);
        // sp.addNumber(-78);
        // sp.addNumber(-42);
        // sp.addNumber(88);
        // sp.addNumber(555);
    // }
    // catch (std::exception& e)
    // {
        // std::cerr << e.what() << std::endl;
        // return (1);
    // }
    // sp.print_span(sp._span);
    // try
    // {
        // std::cout << sp.longestSpan() << std::endl;
        // std::cout << sp.shortestSpan() << std::endl;
    // }
    // catch(std::exception& e)
    // {
        // std::cerr << e.what() << std::endl;
    // }
    // return (0);
// }


static void	instance_test()
{
	{
		Span test(0);

		try
		{
			test.addNumber(1);
			std::cout
			<< "Test size == 0 : FAIL"
			<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout
			<< "Test size == 0 : SUCCESS"
			<< std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span test(1);

		try
		{
			test.addNumber(1);
			std::cout
			<< "Test size == 1 : SUCCESS"
			<< std::endl;
			try
			{
				std::cout
				<< "Try again the limit"
				<< std::endl;
				test.addNumber(42);
				std::cout
				<< "Test FAIL"
				<< std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout
				<< "Test SUCCESS"
				<< std::endl;
			}
			try
			{
				std::cout
				<< "Test shorted span with only one value"
				<< std::endl;
				test.shortestSpan();
				std::cout << "FAIL"  << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "SUCCESS" << std::endl;
				std::cout << e.what() << std::endl;
			}
			try
			{
				std::cout
				<< "Test longest span with only one value"
				<< std::endl;
				test.longestSpan();
				std::cout << "FAIL"  << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "SUCCESS" << std::endl;
				std::cout << e.what() << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cout
			<< "Test size == 1 : FAIL"
			<< std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span test(42);

		try
		{
			test.addNumber(6);
			test.addNumber(3);
			test.addNumber(17);
			test.addNumber(9);
			test.addNumber(11);
			std::cout
			<< "Instanciation sucess"
			<< std::endl;
			try
			{
				std::cout << "Lowest span = " << test.shortestSpan() << std::endl;
				
				std::cout << "longest span = " << test.longestSpan() << std::endl;
				std::cout << "Test Validity N number for shortest/longest Span : SUCCESS"  << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Test Validity N number for shortest/longest Span : FAIL"  << std::endl;
				std::cout << e.what() << std::endl;
			}
			
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
}

static void	test_high_n(void)
{
	Span test = Span(15000);

	std::cout
	<< "Generating number into the vector list"
	<< std::endl;
	try
	{
		for (size_t i = 0; i < 15000; i++)
			test.addNumber(std::rand());
		std::cout << "Generation of number SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Generation of number FAILED" << std::endl;
	}
	try
	{
		std::cout << "Lowest span :" << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << "No exceptionn Throwed : SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "exceptionn Throwed : FAIL" << std::endl;
	}
	
	try
	{
		std::cout << "Longest span :" << std::endl;
		std::cout << test.longestSpan() << std::endl;
		std::cout << "No exceptionn Throwed : SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "exceptionn Throwed : FAIL" << std::endl;
	}
}

static void	test_range()
{
	Span						test = Span(120);
	std::vector<int>			test_vector(119);
	std::vector<int>::iterator	vect_it;
	int							i_vect = 0;

	try
	{
		// std::cout << "Space available on span : " << test.getSpaceAvailable() << std::endl;
		test.addNumber(45);
		test.addNumber(42);
		// std::cout << "Space available on span : " << test.getSpaceAvailable() << std::endl;
		// test.fill(42);
		// std::cout << "Size of the vector : " << test.size() << std::endl;
		// test.display();
		// test.fill();
		// test.display();
		vect_it = test_vector.begin();
		while (vect_it != test_vector.end())
		{
			// std::cout << "Display the value of vect_it : " << *vect_it << std::endl;
			*vect_it = i_vect;
			vect_it++;
			i_vect++;
		}
		std::cout << "Size of vect_it : " << test_vector.size() << std::endl;
		// test.range(test_vector.begin(), test_vector.end());
		// test.display();
		// std::cout << "Space available on span : " << test.getSpaceAvailable() << std::endl;
		test.addNumber(42);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::srand(time(NULL));
	instance_test();
	test_high_n();

	test_range();

	return (0);
}