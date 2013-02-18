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
	double a, b, c, d, e;
	int nParame;
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
		std::cout << "Enter an operation type; (M)ultiply, (D)ivide, (A)dd or (S)ubtract, (I)ntercept, (Q)uadratic, (T)hree-vector length or (F)our vector length, or e(X)it:" << std::endl;
		std::cin >> opt;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		
		opt = toupper((char)opt);
		switch (opt){
			case 'A':
			cout << "ADDITION:  Evaluates (a) + (b)" << std::endl;
			nParams = 2;
			break;
			case 'S':
			cout << "SUBTRACTION:  Evaluates (a) - (b)" << std::endl;
			nParams = 2;
			break;
			case 'M':
			cout << "MULTIPLICATION:  Evaluates (a) * (b)" << std::endl;
			nParams = 2;
			break;
			case 'D':
			cout << "DIVISION:  Evaluates (a) / (b)" << std::endl;
			nParams = 2;
			break;
			case 'I':
			cout << "INTERCEPT:  Evaluates x-intercept of y = (a)x + (b)" << std::endl;
			nParams = 2;
			break;
			case 'Q':
			cout << "QUADRATIC:  Evaluates solutions for y = (a)x^2 + (b)x + (c)" << std::endl;
			nParams = 3;
			break;
			case 'T':
			cout << "THREE VECTOR:  Evaluates length of 3-vector ((a), (b), (c))" << std::endl;
			nParams = 3;
			break;
			case 'F':
			cout << "FOUR VECTOR:  Evaluates length of 4-vector ((a), (b), (c), (d))" << std::endl;
			nParams = 4;
			break;

		};
		if (opt == 'X'){
			except = 3;
		}	
		else if (opt == 'M' || opt == 'D' || opt == 'C' || opt == 'S'){
			std::cout << " - First number (a):" << std::endl;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << " - Second number (b):" << std::endl;
			std::cin >> b;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << " - Second number (c):" << std::endl;
			std::cin >> c;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << " - Second number (d):" << std::endl;
			std::cin >> d;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			switch (opt){
				case 'M':
				e = multiply(a, b);
				type = " times ";
				break;
				case 'D':
				if (b == 0){
					except = 2;
				}
				else{
					e = divide(a, b);
				};
				type = " over ";
				break;
				case 'A':
				e = add(a, b);
				type = " plus ";
				break;
				case 'S':
				e = subtract(a, b);
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
			std::cout << a << type << b << " is " << e << std::endl;
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
