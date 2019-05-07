/*
 * helperfunc.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: sumit
 */

#include "helperfunc.hpp"
#include "car.hpp"
#include "sedan.hpp"
#include "suv.hpp"
#include <iostream>
#include <string>

using namespace std;


/*
 * This function search in both sedan and suv inventory also prints the finance available along with car info
 */
void search_car_in_inventory(string carName, vector<Sedan> sedan_list, vector<Suv> suv_list)
{
	bool found = false;
	int financeAmt;

	for(int i=0; i<sedan_list.size(); i++){
		cout<<"Looking into sedan list first"<<endl;
		if(sedan_list[i].sedan_model.compare(carName) == 0) {
			cout<<"Found in sedan list. Here is the car info"<<endl;
			sedan_list[i].print_info();
			financeAmt = sedan_list[i].finance_available(sedan_list[i].sedan_price);
			cout<<"Finance avialable: $"<< financeAmt;
			found = true;
		}
		else {
			cout<<"car is not in Sedan inventory"<<endl;
		}
	}

	if(found != true && suv_list.size()!= 0){
		cout<<"looking into SUV list now"<<endl;
		for(int i=0; i<suv_list.size(); i++){
			if(suv_list[i].suv_model.compare(carName) == 0){
				cout<<"Found in SUV list. Here is the car info"<<endl;
				suv_list[i].print_info();
				financeAmt = suv_list[i].finance_available(suv_list[i].suv_price);
				cout<<"Finance avialable: $"<< financeAmt;
			}
			else{
				cout<<"car is not in SUV inventory"<<endl;
			}
		}
	}
	else{
		cout<<"We don't have any SUV in inventory, so no car found here either"<<endl;
	}
}

/*
 * This function is just for sedan car search
 * it returns the ref to the sedan car obj if car found
 */

Sedan search_sedan(string carName, vector<Sedan> sedan_list)
{
	Sedan sedanCar;
	bool found = false;

	if(sedan_list.size() != 0){
		cout<<"Looking into sedan list"<<endl;
		for(int i=0; i<sedan_list.size(); i++){
			if(sedan_list[i].sedan_model.compare(carName) == 0) {
				cout<<"Found in sedan list. Here is the car info"<<endl;
				sedan_list[i].print_info();
				sedanCar = sedan_list[i];
				found = true;
				break;
			}
		}
		if(found != true){
			cout<<"car is not found in sedan list"<<endl;
		}
	}
	else{
		cout<<"Note: No car in Sedan section. Please call Honda to send some"<<endl;
	}

	return sedanCar;
}

Suv search_suv(string carName, vector<Suv> suv_list)
{
	Suv suvCar;
	bool found = false;

	if(suv_list.size() != 0){
		cout<<"Looking into suv list"<<endl;
		for(int i=0; i<suv_list.size(); i++){
			if(suv_list[i].suv_model.compare(carName) == 0) {
				cout<<"Found in suv list. Here is the car info"<<endl;
				suv_list[i].print_info();
				suvCar = suv_list[i];
				found = true;
				break;
			}
		}
		if(found != true){
			cout<<"car is not in SUV inventory"<<endl;
		}
	}
	else{
		cout<<"Note: No car in SUV section. Please call Honda to send some."<<endl;
	}

	return suvCar;
}

int car_position_in_list(string carName, vector<Sedan> sedan_list, vector<Suv> suv_list)
{
	bool found = false;
	int pos = 0;
	if(sedan_list.size() != 0 || suv_list.size() != 0) {
		cout<<"Looking into sedan list first"<<endl;
		for(int i=0; i<sedan_list.size(); i++){
			if(sedan_list[i].sedan_model.compare(carName) == 0) {
				cout<<"Found in sedan list. Here is the car position in sedan list:"<<endl;
				found = true;
				pos = i;
				break;
			}
			else {
				cout<<"car is not in Sedan inventory"<<endl;
			}
		}

		if(!found){
			if(suv_list.size() != 0){
				cout<<"looking into SUV list now"<<endl;
					for(int i=0; i<suv_list.size(); i++){
						if(suv_list[i].suv_model.compare(carName) == 0){
							cout<<"Found in SUV list. Here is the car position in SUV list"<<endl;
							pos = i;
							break;
						}
						else{
							cout<<"car is not in SUV inventory"<<endl;
						}
					}
			}
			else{
				cout<<"We don't have any SUV in inventory, so no car found here either"<<endl;
			}

		}
	}
	else {
		cout<<"Both list are empty"<<endl;
	}

	return pos;
}


int finance_avialable_on_car(Sedan sed)
{
	int amt;
	amt = sed.finance_available(sed.sedan_price);

	return amt;
}
