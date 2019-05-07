/*
 * sedan.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: sumit
 */


#include"sedan.hpp"
#include "suv.hpp"
#include"car.hpp"
#include<iostream>
#include<string>


using namespace std;

Sedan::Sedan()
{
	type = "sedan";
	sedan_model = " ";
	sedan_price = 0;
	sedan_automatic = true;
	vector<Sedan> sedan_cars;
}

Sedan::~Sedan()
{

}

Sedan::Sedan(string t, string model, int price, bool automatic)
{
	type = t;
	sedan_model = model;
	sedan_price = price;
	sedan_automatic = automatic;

}
/*
 * takes the object, add to the list and returns the sedan car list
 */
vector<Sedan> Sedan::add_sedan_car_to_list(Sedan sedan)
{
	sedan_cars.push_back(sedan);

	return sedan_cars;
}

vector<Sedan> Sedan::remove_element(int pos)
{
	sedan_cars.erase(sedan_cars.begin()+pos);

	return sedan_cars;

}


void Sedan::print_info()
{
	if(sedan_automatic == true){
		cout<<"Model = "<<sedan_model<<" "<<" "<<"Price = "<<sedan_price<<" Automatic = Yes"<<endl;
	}
	else{
		cout<<"Model = "<<sedan_model<<" "<<" "<<"Price = "<<sedan_price<<" Automatic = No"<<endl;
	}
}

void Sedan::display()
{
	cout<<"******Power Auto Dealership*********"<<endl;
	Car::print_inventory(); //calling one of parents func
	print_inventory();

}




void Sedan::print_inventory()
{
	cout<<"Sedan Inventory: "<<endl;
	for(int i = 0; i<sedan_cars.size(); i++){
		cout<<sedan_cars[i].sedan_model<<endl;//the reason I created vector because the value of model i was getting was from default constructor only not from parametric constructor

	}

}

