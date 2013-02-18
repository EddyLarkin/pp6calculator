#include <iostream>

int main(){
	double a;
	double b;
	double c;

	std::cout << "Please provide the first number:" << std::endl;
	std::cin >> a;
	std::cout << "...and the second number:" << std::endl;
	std::cin >> b;
	c = a * b;
	std::cout << "The product is " << c << "!" << std::endl;
	return 0;
};
