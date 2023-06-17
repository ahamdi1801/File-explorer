#ifndef COMMANDS_H
#define COMMANDS_H

#include "person.h"
#include "err_comp.h"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <memory>

class Commands
{
public:
	template<class T>
	void Select(const FieldNameEnum &_field_name, const CompEnum &_comp, const T &_value, ErrorEnum &_err);
	template<>
	void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const int& _value, ErrorEnum& _err);
	template<>
	void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const std::string& _value, ErrorEnum& _err);
	void Load(std::string _file, ErrorEnum &_err);
	// Getters
	std::vector<std::shared_ptr<Person>> GetData() { return m_data; };
	std::vector<std::shared_ptr<Person>> GetSelected() { return m_selected; };
	void GetError(ErrorEnum &_err);
	//
	Commands();
	~Commands();

private:
	std::vector<std::shared_ptr<Person>> m_data;//this vector will contain a lot of information so it is best to use the heap memory instead of stack
	std::vector<std::shared_ptr<Person>> m_selected;
};

#endif