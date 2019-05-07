/*
 * movie.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: sumit
 */

#include "car.hpp"

#include <iostream>
#include <string>
#include<cstring>

using namespace std;

Car::Car()
{
	car_company = "Honda";
}

Car::~Car()
{

}

int Car::finance_available(int down_payment)
{
	return (down_payment*(0.5));
}

void Car::print_inventory()
{
	cout<<"Company: "<<car_company<<endl;
	cout<<"We have two types of cars Sedan and SUV" <<endl;
}
