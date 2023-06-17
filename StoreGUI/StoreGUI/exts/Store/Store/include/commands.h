#ifndef COMMANDS_H
#define COMMANDS_H

#include "person.h"
#include "err_comp.h"
#include <boost\filesystem.hpp>
#include <boost/any.hpp>
#include <string>
#include <vector>
#include <memory>

#ifdef STORE_EXPORTS
#define STORE_API __declspec(dllexport)
#else
#define STORE_API __declspec(dllimport)
#endif

namespace store {
	class Commands
	{
	public:
		template<class T>
		STORE_API void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const T& _value, ErrorEnum& _err);
		template<>
		STORE_API void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const int& _value, ErrorEnum& _err);
		template<>
		STORE_API void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const float& _value, ErrorEnum& _err);
		template<>
		STORE_API void Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const std::string& _value, ErrorEnum& _err);
		STORE_API void SetData(std::vector<std::shared_ptr<Person>> _data) { m_data = _data; };
		STORE_API void clear();
		STORE_API void ClearSelected();
		
		std::map<std::string, store::FieldNameEnum> fieldname;
		std::map<std::string, store::CompEnum> comp;
		// Getters
		STORE_API std::vector<std::shared_ptr<Person>> GetData() { return m_data; };
		STORE_API std::vector<std::shared_ptr<Person>> GetSelected() { return m_selected; };
		STORE_API std::vector<int> countFiles(const boost::filesystem::path& _p);
		STORE_API std::string GetError(const ErrorEnum& _err);
		//
		STORE_API Commands();
		STORE_API ~Commands();

	private:
		std::vector<std::shared_ptr<Person>> m_data;//this vector will contain a lot of information so it is best to use the heap memory instead of stack
		std::vector<std::shared_ptr<Person>> m_selected;
		//std::vector<std::shared_ptr<std::string>> m_data_paths;
		//std::vector<std::shared_ptr<std::string>> m_selected_paths;
	};
}
#endif
