#include "MutantStack.hpp"
#include <list>
// int main()
// {
    // MutantStack<int> mstack;
// 
    // mstack.push(5);
    // mstack.push(17);
    
    // std::cout << mstack.top() << std::endl;
    
    // std::cout << "size: " << mstack.size() << std::endl;
    
    // mstack.pop();
    
    // std::cout << "size: " << mstack.size() << std::endl;
    
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    
    // [...]
    // 
    // mstack.push(0);
    
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    
    // ++it;
    // --it;
    
    // while (it != ite)
    // {
        // std::cout << *it << std::endl;
        // ++it;
    // 
    // }
    // ite = mstack.rbegin();
    // std::stack<int> s(mstack);
    // return 0;
// }


static void	subject_test(void)
{
	MutantStack<int> mstack;

	mstack.push(5);								// insert the element at the top of the stack
												//  the stack contain [5,]
	mstack.push(17);							// insert the element at the top of the stack
												//  the stack contain [5, 17]
	std::cout << mstack.top() << std::endl;		// return the reference to the last element inserted into stack
	// output : 17\n 17
												//  the stack contain [5, 17]

	mstack.pop();								// remove the last element inserted
												//  the stack contain [5]
	std::cout << mstack.size() << std::endl;	// size get the number of element inside the stack
	// output : 1\n								// the stack contain [5]

	mstack.push(3);								// the stack contain [5, 3]
	mstack.push(5);								// the stack contain [5, 3, 5]
	mstack.push(737);							// the stack contain [5, 3, 5, 737]
	mstack.push(0);								// the stack contain [5, 3, 5, 737, 0]

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// output : 0\n737\n5\n3\n5\n
	std::stack<int> s(mstack);
}

static void	list_test(void)
{
	std::cout << "--separator line--" << std::endl;
	std::list<int> mstack;

	mstack.push_back(5);								// insert the element at the top of the stack
												//  the stack contain [5,]
	mstack.push_back(17);							// insert the element at the top of the stack
												//  the stack contain [5, 17]
	std::cout << mstack.back() << std::endl;		// return the reference to the last element inserted into stack
	// output : 17\n 17
												//  the stack contain [5, 17]
	mstack.pop_back();								// remove the last element inserted
	// 											//  the stack contain [5]
	std::cout << mstack.size() << std::endl;	// size get the number of element inside the stack
	// // output : 1\n								// the stack contain [5]

	mstack.push_back(3);								// the stack contain [5, 3]
	mstack.push_back(5);								// the stack contain [5, 3, 5]
	mstack.push_back(737);							// the stack contain [5, 3, 5, 737]
	mstack.push_back(0);								// the stack contain [5, 3, 5, 737, 0]

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// output : 0\n737\n5\n3\n5\n
	
	std::stack<int, std::list<int> > s(mstack);
}

static void	copy_constructor_test(void)
{
	std::cout << "--separator line--" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);								// insert the element at the top of the stack
												//  the stack contain [5,]
	mstack.push(17);							// insert the element at the top of the stack
												//  the stack contain [5, 17]
	std::cout << mstack.top() << std::endl;		// return the reference to the last element inserted into stack
	// output : 17\n 17
												//  the stack contain [5, 17]

	mstack.pop();								// remove the last element inserted
												//  the stack contain [5]
	std::cout << mstack.size() << std::endl;	// size get the number of element inside the stack
	// output : 1\n								// the stack contain [5]

	mstack.push(3);								// the stack contain [5, 3]
	mstack.push(5);								// the stack contain [5, 3, 5]
	mstack.push(737);							// the stack contain [5, 3, 5, 737]
	mstack.push(0);								// the stack contain [5, 3, 5, 737, 0]
	
	MutantStack<int> cmstack(mstack);
	MutantStack<int>::iterator it = cmstack.begin();
	MutantStack<int>::iterator ite = cmstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// output : 0\n737\n5\n3\n5\n
	std::stack<int> s(cmstack);
}

int	main(void)
{
	subject_test();
	list_test();
	copy_constructor_test();
	return (0);
}