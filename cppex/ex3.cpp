#include <iostream>
#include <string>

int main(){
	char opt;
	std::string type;
	double a, b, c;
	int except = 0;
	
	std::cout << "Enter an operation type; (M)ultiply, (D)ivide, (A)dd or (S)ubtract:" << std::endl;
	std::cin >> opt;
	std::cout << " - First number:" << std::endl;
	std::cin >> a;
	std::cout << " - Second number:" << std::endl;
	std::cin >> b;
	
	switch (toupper(opt)){
		case 'M':
		c = a * b;
		type = " times ";
		break;
		case 'D':
		if (b == 0){
			except = 2;
		}
		else{
			c = a / b;
		};
		type = " over ";
		break;
		case 'A':
		c = a + b;
		type = " plus ";
		break;
		case 'S':
		c = a - b;
		type = " subtract ";
		break;
		default:
		except = 1;
	};

	if (except == 1){
		std::cout << "Invalid operation specified!" << std::endl;
	}
	else if (except == 2){
		std::cout << "Divide by zero error!" << std::endl;
	}
	else{
		std::cout << a << type << b << " is " << c << std::endl;
	};
};	
