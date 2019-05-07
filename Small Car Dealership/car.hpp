/*
 * movie.hpp
 *
 *  Created on: Apr 4, 2019
 *      Author: sumit
 */

#ifndef CAR_HPP_
#define CAR_HPP_

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	string car_company;

	Car();

	~Car();

	Car(string company, bool cert);

	int finance_available(int down_payment);

	void print_inventory();
};


#endif /* CAR_HPP_ */
