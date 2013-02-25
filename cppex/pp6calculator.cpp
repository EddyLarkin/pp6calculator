#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>

void multiply(int &, double *, double=1, double=1,double=0,double=0);
void divide(int &, double *, double=1, double=1,double=0,double=0);
void add(int &, double *, double=0, double=0, double=0, double=0);
void subtract(int &, double *, double=0, double=0, double=0, double=0);
void intercept(int &, double *, double=0, double=0, double=0, double=0);
void quadratic(int &, double *, double=0, double=0, double=0, double=0);
void threevector(int &, double *, double=0, double=0, double=0, double=0);
void fourvector(int &, double *, double=0, double=0, double=0, double=0);

void swap(double &, double &);
void bubbleSort(double *, int);
std::string toString(double);

int main(){
	// allows user to specify and evaluate an operation (addition, multiplication...)
	char opt;
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	int info = 0; // info on result, divide by zero errors etc
	/*   Error types:
 	 *	 0 = program succeeded
	 *  	-1 = invalid option
	 *  	-2 = divide by zero error
	 *  	-3 = user abort
 	*/
	double result [16];
	int nParams;
	void (* operation)(int &, double *, double, double, double, double);
	
	while (info != -3){	
		// continue ruultning until user abort is found
		info = 0;
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
			info = -3;
		}	
		else if (nParams == 0){
			info = -1;
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
			(* operation)(info, result, a, b, c, c);
		};

		switch (info){
			case -1:
			std::cout << "Invalid operation specified!" << std::endl;
			break;
			case -2:
			std::cout << "Divide by zero error!" << std::endl;
			break;
			case -3:
			std::cout << "Exiting..." << std::endl;
			break;
			case 1:
			std::cout << result[0] << " +/- " << result[1] << std::endl;
			break;
			case 2:
			std::cout << result[0] << " +/- " << result[1] << "i" << std::endl;
			break;	
			default:
			std::cout << result[0] << std::endl;
		};
	};
};	

void multiply(int &info, double *e, double a, double b, double c, double d){
	// returns the product of a and b
	e[0] = (a * b);
};
void divide(int &info, double *e, double a, double b, double c, double d){
	// returns the quotient of a and b
	if (b==0){
		info = -2;
	};
	e[0] = (a / b);
};
void add(int &info, double *e, double a, double b, double c, double d){
	// returns the sum of a and b
	e[0] = (a + b);
};
void subtract(int &info, double *e, double a, double b, double c, double d){
	// returns the difference of a and b
	e[0] = (a - b);
};
void intercept(int &info, double *e, double a, double b, double c, double d){
	// returns the x intercept of y = (a)x + b
	e[0] = (-b/a);
};
void quadratic(int &info, double *e, double a, double b, double c, double d){
	// returns the solutions to (a)x^2 + (b)y + (c) = 0
	// returns in format e[0] +- (i)e[1]
	// info gives 1 for real roots, 2 for complex, default otherwise 
	double disc = b*b - 4*a*c;
	if (a == 0){
		intercept(info, e, b, c);
	}
	else{ 
		e[0] = -b/(2*a);
		if (disc<0){
			e[1] = sqrt(-disc)/(2*a);
			info = 2;
		}
		else if(disc==0){
			e[1] = 0;
		}
		else{
			e[1] = sqrt(disc)/(2*a);
			info = 1;
		};
	};
};
void threevector(int &info, double *e, double a, double b, double c, double d){
	// returns the magnitude of vector ((a), (b), (c))
	e[0] = sqrt(a*a + b*b + c*c);
};
void fourvector(int &info, double *e, double a, double b, double c, double d){
	// returns the magnitude of four vector ((a), (b), (c), (d))
	e[0] = sqrt(fabs(a*a - b*b - c*c - d*d));
};

std::string toString(double inp){
	std::stringstream converter;
	converter << inp;
	return converter.str();
};

void swap(double &a, double &b){
	double init_a = a;
	a = b;
	b = init_a;
};

void bubbleSort(double *a, int len){
	int i;
	int j;
	for (i=0; i<len-1; i++){
		for (j=0; j<len-l; j++){
			if (a[j] < a[j+1]){
				swap(a[j], a[j+1]);
			};
		};	
	};	
};
