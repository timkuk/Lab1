#include <iostream>
#include <cmath>
#include <cstdlib>
#include "ClientTCP.h"

double function(double x) {
	return pow(x, 3) * pow(2, pow(x * sin(x), 1./3));
}

double method_left_rectangles(double x1, double x2, double y1) {
	return y1 * (x2 - x1);
}

int main()
{
	std::string message;
	double x1, x2, y1;
	double result = 0;

	ClientTCP client(1000);
	message = client.receiveMessage(15);

	x1 = atof(message.substr(0, message.find(' ')).c_str());
	x2 = atof(message.substr(message.find(' ') + 1, message.length() - message.find(' ') - 1).c_str());
	y1 = function(x1);

	std::cout << "A: " << x1 << std::endl;
	std::cout << "B: " << x2 << std::endl;
	std::cout << "Y: " << y1 << std::endl;
	
	result = method_left_rectangles(x1, x2, y1);

	std::cout << "result: " << result << std::endl;

	client.sendMessage(std::to_string(result));

	int tmp = getchar();

	return 0;
}

