#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>

std::string multiply(double=1, double=1,double=0,double=0);
std::string divide(double=1, double=1,double=0,double=0);
std::string add(double=0, double=0, double=0, double=0);
std::string subtract(double=0, double=0, double=0, double=0);
std::string intercept(double=0, double=0, double=0, double=0);
std::string quadratic(double=0, double=0, double=0, double=0);
std::string threevector(double=0, double=0, double=0, double=0);
std::string fourvector(double=0, double=0, double=0, double=0);
std::string toString(double);

int main(){
	// allows user to specify and evaluate an operation (addition, multiplication...)
	char opt;
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	std::string e = "0";
	int nParams;
	int except = 0;
	std::string (* operation)(double, double, double, double);
	/*   Error types:
 	 *	0 = program succeeded
	 *  	1 = invalid option
	 *  	2 = divide by zero error
	 *  	3 = user abort
 	*/
	
	while (except != 3){	
		// continue ruultning until user abort is found
		except = 0;
		std::cout << "Enter an operation type; (M)ultiply, (D)ivide, (A)dd or (S)ubtract, (I)ntercept, (Q)uadratic, (T)hree-vector length or (F)our vector length, or e(X)it:" << std::endl;
		std::cin >> opt;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		
		opt = toupper((char)opt);
		nParams = 0;
		switch (opt){
			case 'A':
			std::cout << "ADDITION:  Evaluates (a) + (b)" << std::endl;
			operation = add;
			nParams = 2;
			break;
			case 'S':
			std::cout << "SUBTRACTION:  Evaluates (a) - (b)" << std::endl;
			operation = subtract;
			nParams = 2;
			break;
			case 'M':
			std::cout << "MULTIPLICATION:  Evaluates (a) * (b)" << std::endl;
			operation = multiply;
			nParams = 2;
			break;
			case 'D':
			std::cout << "DIVISION:  Evaluates (a) / (b)" << std::endl;
			operation = divide;
			nParams = 2;
			break;
			case 'I':
			std::cout << "INTERCEPT:  Evaluates x-intercept of y = (a)x + (b)" << std::endl;
			operation = intercept;
			nParams = 2;
			break;
			case 'Q':
			std::cout << "QUADRATIC:  Evaluates solutions for y = (a)x^2 + (b)x + (c)" << std::endl;
			operation = quadratic;
			nParams = 3;
			break;
			case 'T':
			std::cout << "THREE VECTOR:  Evaluates length of 3-vector ((a), (b), (c))" << std::endl;
			operation = threevector;
			nParams = 3;
			break;
			case 'F':
			std::cout << "FOUR VECTOR:  Evaluates length of 4-vector ((a), (b), (c), (d))" << std::endl;
			operation = fourvector;
			nParams = 4;
			break;

		};
		if (opt == 'X'){
			except = 3;
		}	
		else if (nParams == 0){
			except = 1;
		}
		else{
			std::cout << " - First number (a):" << std::endl;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << " - Second number (b):" << std::endl;
			std::cin >> b;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			if (nParams > 2){
				std::cout << " - Third number (c):" << std::endl;
				std::cin >> c;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				if(nParams > 3){
					std::cout << " - Fourth number (d):" << std::endl;
					std::cin >> d;
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				};
			};

			e = (* operation)(a, b, c, c);
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
			std::cout << e << std::endl;
		};
	};
};	

std::string multiply(double a, double b, double c, double d){
	// returns the product of a and b
	return toString(a) + " times " + toString(b) + " gives " + toString(a * b);
};
std::string divide(double a, double b, double c, double d){
	// returns the quotient of a and b
	if (b==0){
		return toString(a) + " over " + toString(b) + " results in a divide by zero error";
	};
	return toString(a) + " over " + toString(b) + " gives " + toString(a / b);
};
std::string add(double a, double b, double c, double d){
	// returns the sum of a and b
	return toString(a) + " plus " + toString(b) + " gives " + toString(a + b);
};
std::string subtract(double a, double b, double c, double d){
	// returns the difference of a and b
	return toString(a) + " minus " + toString(b) + " gives " + toString(a - b);
};
std::string intercept(double a, double b, double c, double d){
	// returns the x intercept of y = (a)x + b
	return toString(a) + "x + " + toString(b) + " = 0 at " + toString(-b/a);
};
std::string quadratic(double a, double b, double c, double d){
	// returns the solutions to (a)x^2 + (b)y + (c) = 0
	double disc = b*b - 4*a*c;
	std::string res = toString(a) + "x^2 " + toString(b) + "x + " + toString(c) + " has solutions " + toString(-b/(2*a));
	if (a == 0){
		return intercept(b, c);
	};
	if (disc<0){
		return res + " +/- " + toString(sqrt(-disc)) + "i"; 
	}
	else if(disc==0){
		return res;
	}
	else{
		return res + " +/- " + toString(sqrt(disc));
	};
};
std::string threevector(double a, double b, double c, double d){
	// returns the magnitude of vector ((a), (b), (c))
	return "The length of (" + toString(a) + ", " + toString(b) + ", " + toString(c) + ") is " + toString(sqrt(a*a + b*b + c*c));
};
std::string fourvector(double a, double b, double c, double d){
	// returns the magnitude of four vector ((a), (b), (c), (d))
	return "The length of (" + toString(a) + ", " + toString(b) + ", " + toString(c) + toString(d) + ") is " + toString(sqrt(fabs(a*a - b*b - c*c - d*d)));
};

std::string toString(double inp){
	std::stringstream converter;
	converter << inp;
	return converter.str();
};
