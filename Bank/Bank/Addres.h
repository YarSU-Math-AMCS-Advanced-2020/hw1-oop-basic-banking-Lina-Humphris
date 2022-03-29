#pragma once
#include <string>
#include <iostream>

using namespace std;

class Addres
{
private:
	string _country;
	string _region;
	string _locality; //Населенный пункт
	string _street;
	string _index;
	int _house;
	int _flat;
public:
	Addres(string country = "Russia", string region = "", string locality="Yaroslavl", 
		string street="", string index="000000", int house = 0, int flat = 0);

	void set_country(string country) { _country = country; };
	void set_region(string region) { _region = region; };
	void set_locality(string locality) { _locality = locality; };
	void set_street(string street) { _street = street; };
	void set_index(string index) { _index = index; };
	void set_house(int house) { _house = house; };
	void set_flat(int flat) { _flat = flat; };

	string get_country() { return _country; };
	string get_region() { return _region; };
	string get_locality() { return _locality; };
	string get_street() { return _street; };
	string get_index() { return _index; };
	int get_house() { return _house; };
	int get_flat() { return _flat; };

	Addres operator=(Addres a);

	friend std::istream& operator>>(istream& in, Addres& t);
	friend std::ostream& operator<<(ostream& out, Addres& t);

};


