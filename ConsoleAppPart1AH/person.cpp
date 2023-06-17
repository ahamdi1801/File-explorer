#include "person.h"
#include <string>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>

Person::Person()
{

}

Person::~Person()
{

}

void Person::SetPerson(std::string _first_name, std::string _last_name, int _height, int _gender, std::string _position, int _confidence)
{
	m_person[FieldNameEnum::First_Name] = _first_name;
	m_person[FieldNameEnum::Last_Name] = _last_name;
	m_person[FieldNameEnum::Height] = _height;
	m_person[FieldNameEnum::Gender] = (_gender)?"Female":"Male";
	m_person[FieldNameEnum::Position] = _position;
	m_person[FieldNameEnum::Confidence] = _confidence;

}

void Person::SetDateAndAge(std::string ymd, std::string hmmsms)
{
	m_date.push_back(stoi(ymd.substr(0, 4)));
	std::string mdhmmsms = ymd.substr(4) + hmmsms;
	int j = 0;
	for (int i = 1; i < 7; i++)
	{
		if (i == 6)
		{
			m_date.push_back(stoi(mdhmmsms.substr(9, 3)));
			continue;
		}
		m_date.push_back(stoi(mdhmmsms.substr(j , 2)));
		j += 2;
	}
	//date array [year, month, day, hour, minutes, seconds,milliseconds]
	int nanoseconds = m_date.at(6) * 1000; // convert to nanoseconds because boost::posix_time_duration(hours, minutes, seconds, nanoseconds)
	auto current_time = boost::posix_time::from_time_t(boost::chrono::system_clock::to_time_t(boost::chrono::system_clock::now())); // create current time with ptime
	boost::posix_time::ptime t1(boost::gregorian::date(m_date.at(0), m_date.at(1), m_date.at(2)), boost::posix_time::time_duration(m_date.at(3), m_date.at(4), m_date.at(5), nanoseconds)); //convert to ptime so that we can calculate the time difference easily with (current_time - t1).total_milliseconds()

	m_person[FieldNameEnum::Age] = boost::numeric_cast<int>((current_time - t1).total_milliseconds() / 60000 / 60 / 24 / 365); // division to get age | data type is __int64 so boost::numeric_cast is used to convert to int
}

std::string Person::GetFirstName()
{
	auto it = m_person.find(FieldNameEnum::First_Name);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize first name." << std::endl;
		return "None";
	}
	else
	{
		return boost::get<std::string>(it->second);
	}
}

std::string Person::GetLastName()
{
	auto it = m_person.find(FieldNameEnum::Last_Name);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize last name." << std::endl;
		return "None";
	}
	else
	{
		return boost::lexical_cast<std::string>(it->second);
	}
}

int Person::GetHeight()
{
	auto it = m_person.find(FieldNameEnum::Height);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize height." << std::endl;
		return 0;
	}
	else
	{
		return boost::get<int>(it->second);
	}
}

std::string Person::GetGender()
{
	auto it = m_person.find(FieldNameEnum::Gender);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize gender." << std::endl;
		return "None";
	}
	else
	{
		return boost::get<std::string>(it->second);
	}
}

std::string Person::GetPosition()
{
	auto it = m_person.find(FieldNameEnum::Position);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize position." << std::endl;
		return "None";
	}
	else
	{
		return boost::get<std::string>(it->second);
	}
}

int Person::GetConfidence()
{
	auto it = m_person.find(FieldNameEnum::Confidence);
	if (it == m_person.end())
	{
		std::cout << "SetPerson() function has not been used yet to initialize confidence." << std::endl;
		return 0;
	}
	else
	{
		return boost::get<int>(it->second);
	}
}


int Person::GetAge()
{
	auto it = m_person.find(FieldNameEnum::Age);
	if (it == m_person.end())
	{
		std::cout << "SetDateAndAge() function has not been used yet to initialize age." << std::endl;
		return 0;
	}
	else
	{
		return boost::get<int>(it->second);
	}
}

void Person::GetAllData()
{
	std::cout << "First name: " << Person::GetFirstName()<< std::endl;
	std::cout << "Last name: " << Person::GetLastName() << std::endl;
	std::cout << "Age: " << Person::GetAge() << std::endl;
	std::cout << "Gender: " << Person::GetGender() << std::endl;
	std::cout << "Position: " << Person::GetPosition() << std::endl;
	std::cout << "Confidence: " << Person::GetConfidence() << std::endl;
}
