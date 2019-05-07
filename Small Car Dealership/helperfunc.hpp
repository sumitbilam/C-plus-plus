/*
 * helperfunc.hpp
 *
 *  Created on: Apr 29, 2019
 *      Author: sumit
 */

#ifndef HELPERFUNC_HPP_
#define HELPERFUNC_HPP_

#include "car.hpp"
#include "sedan.hpp"
#include "suv.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search_car_in_inventory(string carName, vector<Sedan> sedan_list, vector<Suv> suv_list);

Sedan search_sedan(string carName, vector<Sedan> sedan_list);

Suv search_suv(string carName, vector<Suv> suv_list);

int car_position_in_list(string carName, vector<Sedan> sedan_list, vector<Suv> suv_list );


int finance_avialable_on_car(Car car);


#endif /* HELPERFUNC_HPP_ */
