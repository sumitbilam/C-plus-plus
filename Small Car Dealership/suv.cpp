/*
 * suv.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: sumit
 */

#include"suv.hpp"
#include"car.hpp"
#include<iostream>
#include<string>

using namespace std;

Suv::Suv()
{
	type = "suv";
	suv_model = "";
	suv_price = 0;
	suv_automatic = true;
	vector<Suv> suv_cars;
}

Suv::~Suv()
{

}

Suv::Suv(string t, string model, int price, bool automatic)
{
	type = t;
	suv_model = model;
	suv_price = price;
	suv_automatic = automatic;

}

void Suv::print_info()
{
	if(suv_automatic == true){
		cout<<"Model = "<<suv_model<<" "<<" "<<"Price = "<<suv_price<<" Automatic = Yes"<<endl;
	}
	else{
		cout<<"Model = "<<suv_model<<" "<<" "<<"Price = "<<suv_price<<" Automatic = No"<<endl;
	}
}

vector<Suv> Suv::add_suv_car_to_list(Suv suv)
{
	suv_cars.push_back(suv);

	return suv_cars;
}

void Suv::print_inventory()
{
	cout<<"SUV Inventory: "<<endl;
	for(int i=0; i<suv_cars.size(); i++){
		cout<<suv_cars[i].suv_model<<endl;
	}
}

