#include <iostream>
#include<string>

using namespace std;


class Product
{
	int id = 0;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0.0;
	double* priceHistory = nullptr;
	int itemsSold = 0;

public:
	Product(int _id, const char* _name, const char* _description, double _price, const double* _priceHistory, int _itemsSold) :
		id(_id), price(_price), priceHistory(_priceHistory), itemsSold(_itemsSold)
	{
		this->name = new const char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);

		this->description = new const [strlen(_description) + 1];
		strcpy_s(this->description, strlen(_description) + 1, _description);

		this->priceHistory = new const double[_itemsSold;]
			for (int index = 0; index <= itemsSold; index++)
				this->priceHistory[index] = _priceHistory[index];
	}

	//all setters
	void set_id(int _id) {
		this->id = _id;

	}

	void set_priceHistory(const double* _priceHistory, int _itemsSold) {
		this->itemsSold = _itemsSold;

		this->priceHistory = new const double[_itemsSold;]
			for (int index= 0; index <= itemsSold; index++)
				this->priceHistory[index] = _priceHistory[index];
	}

	void set_price(double _price) {
		if (this->price != _price)
			this->price = _price;	

		if (this->priceHistory != nullptr){
				delete[] this->priceHistory;

		}

		this->priceHistory = new double[_itemsSold + 1]
			for (int index = 0; index <= itemsSold; index++)
				this->priceHistory[index + 1] = _priceHistory[index];

		this->priceHistory[0] = this->price;
		this->itemsSold = _itemsSold + 1;
	}

	void set_name(const char* _name) {
		if _name == nullptr
			return nullptr
		this->name = new const char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1);

	}

	void set_description(const char* _description) {
		if _name == nullptr
			return nullptr
		this->description = new const char[strlen(_description) + 1];
		strcpy_s(this->name, strlen(_description) + 1);

	}

	int get_id() { return this->_id; }
	char* get_name() { return this->name; }
	char* get_description() { return this->description; }
	double get_price() { return this->price; }
	double* get_priceHistory() { return this->priceHistory; }
	int get_itemsSold() { return this->itemsSold; }



	double getPriceAverage(double* _priceHistory, int _itemsSold){
		double average;
		for (int index = 0; index <= _itemsSold; index++)
			average += _priceHistory[index];
		return average / _itemsSold

	}
	

	//ctr de copiere
	Product(const Product& product) :
		Product(product.id, product.name, product.description, product.price, product.priceHistory, product.itemsSold) {

	}


	~Product(){
		delete this->name;
		delete this->description;
		delete this->priceHistory;

	}
};