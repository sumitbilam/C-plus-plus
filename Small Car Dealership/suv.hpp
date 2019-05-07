/*
 * suv.hpp
 *
 *  Created on: Apr 24, 2019
 *      Author: sumit
 */

#ifndef SUV_HPP_
#define SUV_HPP_

#include"car.hpp"
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Suv:public Car
{
public:
	string type;
	string suv_model;
	int suv_price;
	bool suv_automatic;
	vector<Suv> suv_cars;

	Suv();

	~Suv();
	Suv(string t, string model, int price, bool automatic);

	vector<Suv> add_suv_car_to_list(Suv suv);

	void print_info();

	//overridding function
	void print_inventory();

};



#endif /* SUV_HPP_ */
