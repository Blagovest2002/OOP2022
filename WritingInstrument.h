#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
class WritingInstrument
{
protected:
	char* brand;
	unsigned int factYear;
	void copy(WritingInstrument &other);
	void erase();
public:
	WritingInstrument();
	WritingInstrument(char* _brand, unsigned int _factYear);
	WritingInstrument(WritingInstrument& other);
	WritingInstrument& operator=(WritingInstrument& other);
	~WritingInstrument();
	friend std::istream& operator>>(std::istream& input, WritingInstrument& obj);
	friend std::ostream& operator<<(std::ostream& output, WritingInstrument& obj);

};
void WritingInstrument::copy(WritingInstrument &other) {
	this->brand = new char[strlen(other.brand) + 1];
	strcpy_s(this->brand, strlen(other.brand) + 1, other.brand);
	this->factYear = other.factYear;
}
void WritingInstrument::erase() {
	delete[]this->brand;
}
WritingInstrument::WritingInstrument() {
	this->brand = new char[1];
	this->brand[0] = '\0';
	this->factYear = 0;
}
WritingInstrument::WritingInstrument(char* _brand, unsigned int _factYear) :
	brand(new char[strlen(_brand) + 1]),
	factYear(_factYear)
	{
	strcpy_s(this->brand, strlen(_brand) + 1, _brand);
}
WritingInstrument::WritingInstrument(WritingInstrument& other) {
	this->copy(other);
}
WritingInstrument& WritingInstrument::operator=(WritingInstrument& other) {
	this->copy(other);
	return *this;
}
WritingInstrument::~WritingInstrument() {
	std::cout << "called Destructor" << std::endl;
	this->erase();
}
std::istream& operator>>(std::istream& input, WritingInstrument& obj) {
	char _brand[256];
	input >> _brand >> obj.factYear;
	obj.brand = new char[strlen(_brand) + 1];
	strcpy_s(obj.brand, strlen(_brand) + 1, _brand);
	return input;
}
std::ostream& operator<<(std::ostream& output, WritingInstrument& obj) {
	output << obj.brand << " " << obj.factYear << std::endl;
	return output;
}
class Marker : public WritingInstrument {
private:
	char* color;
	void copy_m(Marker& other);
	void erase_m();
public:
	Marker();
	Marker(char* _color, char* _brand, unsigned int _factYear);
	Marker(Marker& other);
	Marker& operator=(Marker& other);
	~Marker();
	friend std::istream& operator>>(std::istream& input, Marker& obj);
	friend std::ostream& operator<<(std::ostream& output, Marker& obj);


};
void Marker::copy_m(Marker& other){
	this->copy(other);
	this->color = new char[strlen(other.color) + 1];
	strcpy_s(this->color, strlen(other.color) + 1, other.color);
}
void Marker::erase_m() {
	delete[]this->color;
}
Marker::Marker() : WritingInstrument(){ 
	this->color = new char[1];
	this->color[0] = '\0';
}
Marker::Marker(char* _color, char* _brand, unsigned int _factYear) 
	: WritingInstrument(_brand,_factYear) {
	this->color = new char[strlen(_color) + 1];
	strcpy_s(this->color, strlen(_color) + 1, _color);

}
Marker::Marker(Marker& other) {
	this->copy_m(other);
}
Marker& Marker::operator=(Marker& other) {
	this->copy_m(other);
	return *this;
}

Marker::~Marker() {
	this->erase_m();
	std::cout << "Called Marker Destructor" << std::endl;
}
std::istream& operator>>(std::istream& input, Marker& obj) {
	char _brand[256];
	char _color[256];
	input >>_color>> _brand >> obj.factYear;
	obj.color = new char[strlen(_color) + 1];
	strcpy_s(obj.color, strlen(_color) + 1, _color);
	obj.brand = new char[strlen(_brand) + 1];
	strcpy_s(obj.brand, strlen(_brand) + 1, _brand);
	return input;
}
std::ostream& operator<<(std::ostream& output, Marker& obj) {
	output <<obj.color<<" "<<obj.brand << " " << obj.factYear << std::endl;
	return output;
}
