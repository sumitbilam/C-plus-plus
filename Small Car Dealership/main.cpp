/*
 * main.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: sumit
 */

#include <iostream>
#include <string>
#include <vector>
#include "car.hpp"
#include "sedan.hpp"
#include "suv.hpp"
#include "helperfunc.hpp"

using namespace std;


int main()
{
	/*
	this initialization wont work if you have C++98 or lower, this is supported in C++11 and onwards
	vector<Civic> civic_list {Civic("jkl", 2000, 15000.00, true), Civic("sports", 2007, 14000.00, false), Civic("xrt", 2018, 30000.00, true)};
	 */
	//Civic civic_list; every time you crate an object of a class its default constructor get called automatically

	Sedan sedan;
	Suv suv;

	sedan.display();
	suv.print_inventory();
	vector<Sedan> sedan_list;
	vector<Suv> suv_list;

	string model;
	int price;
	bool automatic;
	string carType;

	int num;
	string userSelectedModel;

	cout<<"How many cars you want to add:";
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Enter "<<i+1<<" "<<"car info:"<<endl;
		cout<<"Enter car type sedan/suv:";
		cin>>carType;
		cout<<"Enter model: ";
		cin>>model;
		cout<<"Enter price: ";
		cin>>price;
		cout<<"Enter 1 if automatic, 0 otherwise: ";
		cin>>automatic;

		if(sedan.type.compare(carType)== 0){
			Sedan sed(carType, model, price, automatic);
			sedan_list = sedan.add_sedan_car_to_list(sed);
			cout<<"size of sedan list = "<<sedan_list.size()<<endl;
		}
		if(suv.type.compare(carType) == 0){
			Suv s(carType, model, price, automatic);
			suv_list = suv.add_suv_car_to_list(s);
		}
	}

	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	sedan.display();
	suv.print_inventory();

	cout<<"Type car from above to get more detail:";
	cin>>userSelectedModel;
	//search_car_in_inventory(userSelectedModel, sedan_list, suv_list);
	sedan = search_sedan(userSelectedModel, sedan_list);
	suv = search_suv(userSelectedModel, suv_list);

	cout<<"------Finance Info--------"<<endl;
	int financeAmt = sedan.finance_available(sedan.sedan_price);
	cout<<"finance available on "<< sedan.sedan_model<<": "<<financeAmt<<endl;

	cout<<"----------- remove element from the sedan list --------"<<endl;
	cout<<"Enter the car you want to remove:";
	cin>>userSelectedModel;
	int pos = car_position_in_list(userSelectedModel, sedan_list, suv_list);
	cout<<"car position: "<<pos<<endl;
	//vector<Sedan> sedan_cars;
	//sedan_cars = sedan.remove_element(pos);
	sedan_list.erase(sedan_list.begin() + pos);
	cout<<"size of sedan list after removing the element: "<<sedan_list.size()<<endl;
	//cout<<"list after removing element from sedan list"<<endl;
	sedan.display();






	return 0;
}


