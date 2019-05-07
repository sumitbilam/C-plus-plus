/*
 * sedan.hpp
 *
 *  Created on: Apr 24, 2019
 *      Author: sumit
 */

#ifndef SEDAN_HPP_
#define SEDAN_HPP_

#include"car.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;



/*publicly inherited class from car
*/
class Sedan:public Car
{
public:
	string type;
	string sedan_model;
	int sedan_price;
	bool sedan_automatic;
	vector<Sedan> sedan_cars;


	Sedan();

	~Sedan();
	Sedan(string t, string model, int price, bool automatic);

	vector<Sedan> add_sedan_car_to_list(Sedan sedan);

	vector<Sedan> remove_element(int pos);

	void print_info();

	void display();


	//overridding function
	void print_inventory();
};



#endif /* SEDAN_HPP_ */
