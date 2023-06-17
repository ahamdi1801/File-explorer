#ifndef PERSON_H
#define PERSON_H
#include "err_comp.h"
#include <string>
#include <vector>
#include <boost/variant.hpp>
#include <map>


class Person 
{
public:
	Person();
	//Getters
	std::map<FieldNameEnum, boost::variant<int, std::string>> GetPerson() { return m_person; };
	int GetAge();
	std::string GetFirstName();
	std::string GetLastName();
	int GetHeight();
	std::string GetGender();
	std::string GetPosition();
	int GetConfidence();
	std::vector<int> GetDate() { return m_date; };
	void GetAllData();
	// Setters
	void SetPerson(std::string _first_name, std::string _last_name, int _height, int _gender, std::string _position, int _confidence);
	void SetDateAndAge(std::string ymd, std::string hmmsms);
	//
	~Person();
private:
	//
	std::map<FieldNameEnum, boost::variant<int, std::string>> m_person;
	// male = 0, female = 1  
	//{Professor, Assistent, Student, External} 
	std::vector<int> m_date; // [year, month, day, hour, minutes, seconds, milliseconds] 
};

#endif 