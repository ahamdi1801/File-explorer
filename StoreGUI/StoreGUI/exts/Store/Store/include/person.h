#ifndef PERSON_H
#define PERSON_H
#include "err_comp.h"
#include <string>
#include <vector>
#include <boost/variant.hpp>
#include <map>

#ifdef STORE_EXPORTS
#define STORE_API __declspec(dllexport)
#else
#define STORE_API __declspec(dllimport)
#endif

namespace store {
	class Person
	{
	public:
		STORE_API Person();
		//Getters
		STORE_API std::map<FieldNameEnum, boost::variant<int, float, std::string>> GetPerson() { return m_person; };
		STORE_API int GetAge();
		STORE_API std::string GetFirstName();
		STORE_API std::string GetLastName();
		STORE_API int GetHeight();
		STORE_API std::string GetGender();
		STORE_API std::string GetPosition();
		STORE_API float GetConfidence();
		STORE_API std::vector<int> GetDate() { return m_date; };
		STORE_API std::string GetPath();
		STORE_API std::string GetAllData();
		STORE_API int GetItemIndex();
		// Setters
		STORE_API void SetPerson(std::string _first_name, std::string _last_name, int _height, int _gender, std::string _position, float _confidence, std::string _path, int _item_index);
		STORE_API void SetDateAndAge(std::string ymd, std::string hmmsms);
		//
		STORE_API ~Person();
	private:
		//
		std::map<FieldNameEnum, boost::variant<int, float, std::string>> m_person; // male = 0, female = 1  //{Professor, Assistent, Student, External} 
		std::vector<int> m_date; // [year, month, day, hour, minutes, seconds, milliseconds] 
	};
}
#endif 