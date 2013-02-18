#include <iostream>
#include <string>
#include <climits>

double multiply(double, double);
double divide(double, double);
double add(double, double);
double subtract(double, double);

int main(){
	// allows user to specify and evaluate an operation (addition, multiplication...)
	char opt;
	std::string type;
	double a, b, c;
	int except = 0;
	/*   Error types:
 	 *	0 = program succeeded
	 *  	1 = invalid option
	 *  	2 = divide by zero error
	 *  	3 = user abort
 	*/
	
	while (except != 3){	
		// continue running until user abort is found
		except = 0;
		std::cout << "Enter an operation type; (M)ultiply, (D)ivide, (A)dd or (S)ubtract, or (Q)uit:" << std::endl;
		std::cin >> opt;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		
		opt = toupper((char)opt);
		if (opt == 'Q'){
			except = 3;
		}	
		else if (opt == 'M' || opt == 'D' || opt == 'C' || opt == 'S'){
			std::cout << " - First number:" << std::endl;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << " - Second number:" << std::endl;
			std::cin >> b;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			switch (opt){
				case 'M':
				c = multiply(a, b);
				type = " times ";
				break;
				case 'D':
				if (b == 0){
					except = 2;
				}
				else{
					c = divide(a, b);
				};
				type = " over ";
				break;
				case 'A':
				c = add(a, b);
				type = " plus ";
				break;
				case 'S':
				c = subtract(a, b);
				type = " subtract ";
				break;
			};	
		}
		else {
			except = 1;
		};

		switch (except){
			case 1:
			std::cout << "Invalid operation specified!" << std::endl;
			break;
			case 2:
			std::cout << "Divide by zero error!" << std::endl;
			break;
			case 3:
			std::cout << "Exiting..." << std::endl;
			break;
			default:
			std::cout << a << type << b << " is " << c << std::endl;
		};
	};
};	

double multiply(double a, double b){
	// returns the product of a and b
	return a * b;
};
double divide(double a, double b){
	// returns the product of a and b
	return a / b;
};
double add(double a, double b){
	// returns the product of a and b
	return a + b;
};
double subtract(double a, double b){
	// returns the product of a and b
	return a - b;
};
