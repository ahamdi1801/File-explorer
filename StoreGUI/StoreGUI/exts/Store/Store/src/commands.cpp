#include "commands.h"
#include <boost/filesystem.hpp>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>
#include <iostream> 
#include <fstream>
#include <regex>


store::Commands::Commands()
{
    fieldname["First name"] = store::FieldNameEnum::First_Name;
    fieldname["Last name"] = store::FieldNameEnum::Last_Name;
    fieldname["Gender"] = store::FieldNameEnum::Gender;
    fieldname["Age"] = store::FieldNameEnum::Age;
    fieldname["Height"] = store::FieldNameEnum::Height;
    fieldname["Position"] = store::FieldNameEnum::Position;
    fieldname["Confidence"] = store::FieldNameEnum::Confidence;

    comp["<"] = store::CompEnum::Lesser;
    comp[">"] = store::CompEnum::Greater;
    comp["="] = store::CompEnum::Equal;
}

store::Commands::~Commands()
{

}

void store::Commands::clear()
{
    m_data.clear();
    m_selected.clear();
}

void store::Commands::ClearSelected()
{
    m_selected.clear();
}

std::string store::Commands::GetError(const ErrorEnum& _err)
{
    switch (_err)
    {
    case ErrorEnum::No_Error:
        return "No errors, defined by ErrorEnum, were found.";
        break;
    case ErrorEnum::File_Could_Not_Opened:
        return "File could not be opened.";
        break;
    case ErrorEnum::Path_Does_Not_Exist:
        return "Path does not exist. Directory or file needs to be added in solution directory.";
        break;
    case ErrorEnum::Wrong_Data_Input:
        return "Wrong data input.";
        break;
    case ErrorEnum::Not_A_Regular_File_Or_Directory:
        return "Not a regular file or directory.";
        break;
    case ErrorEnum::Data_Vector_Is_Empty:
        return "Data vector is empty.";
        break;
    case ErrorEnum::Wrong_Data_Type:
        return "Wrong data type.";
        break;
    default:
        return "Unhandled error.";
    }
}

std::vector<int> store::Commands::countFiles(const boost::filesystem::path& _p)
{
    int counter = 0;
    int txt_counter = 0;
    for (boost::filesystem::directory_entry& x : boost::filesystem::recursive_directory_iterator(_p))
    {
        if (x.path().extension() == ".txt" | x.path().extension() == ".jpg")
        {
            counter++;
            if (x.path().extension() == ".txt")
                txt_counter++;
        }
    }
    return std::vector<int>({ counter, txt_counter });
}

template<>
void store::Commands::Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const int& _value, ErrorEnum& _err) // nested switch statement for _field_name and _comp
{
    int size = m_data.size();
    _err = ErrorEnum::No_Error;
    if (size == 0)
    {
        _err = ErrorEnum::Data_Vector_Is_Empty;
        return;
    }
    switch (_field_name)
    {
    case FieldNameEnum::Age:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (_value == m_data.at(i)->GetAge())
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Greater:
            for (int i = 0; i < size; i++)
            {
                if ( _value > m_data.at(i)->GetAge())
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Lesser:
            for (int i = 0; i < size; i++)
            {
                if (_value < m_data.at(i)->GetAge())
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    /*
    case FieldNameEnum::Confidence:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetConfidence() == _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Greater:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetConfidence() > _value)
                    m_selected.push_back(m_data.at(i));
            }
            break;
        case CompEnum::Lesser:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetConfidence() < _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    */
    default:
        _err = ErrorEnum::Wrong_Data_Input;
    }
}

template<>
void store::Commands::Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const float& _value, ErrorEnum& _err) // nested switch statement for _field_name and _comp
{
    int size = m_data.size();
    _err = ErrorEnum::No_Error;
    if (size == 0)
    {
        _err = ErrorEnum::Data_Vector_Is_Empty;
        return;
    }
    switch (_field_name)
    {
    /*case FieldNameEnum::Age:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetAge() == _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Greater:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetAge() > _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Lesser:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetAge() < _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    */
    case FieldNameEnum::Confidence:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (_value == m_data.at(i)->GetConfidence())
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        case CompEnum::Greater:
            for (int i = 0; i < size; i++)
            {
                if (_value > m_data.at(i)->GetConfidence())
                    m_selected.push_back(m_data.at(i));
            }
            break;
        case CompEnum::Lesser:
            for (int i = 0; i < size; i++)
            {
                if (_value <  m_data.at(i)->GetConfidence()  )
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    default:
        _err = ErrorEnum::Wrong_Data_Input;
    }
}


// simple implementation of regex for first name and last name -> input should be uppercase letters and output will be that of the names starting with these uppercase letters 
template<>
void store::Commands::Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const std::string& _value, ErrorEnum& _err) // nested switch statement for _field_name and _comp
{
    int size = m_data.size();
    _err = ErrorEnum::No_Error;
    if (size == 0)
    {
        _err = ErrorEnum::Data_Vector_Is_Empty;
        return;
    }
    switch (_field_name)
    {
    case FieldNameEnum::First_Name:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                std::regex* expr = new std::regex("[" + _value + "]\\w+");
                std::match_results<const char*>* cm = new std::match_results<const char*>;
                std::string* str = new std::string(m_data.at(i)->GetFirstName());
                if (std::regex_match(str->c_str(), *cm, *expr))
                {
                    m_selected.push_back(m_data.at(i));
                }
                delete expr;
                expr = nullptr;
                delete cm;
                cm = nullptr;
                delete str;
                str = nullptr;
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    case FieldNameEnum::Last_Name:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                std::regex* expr = new std::regex("[" + _value + "]\\w+");
                std::match_results<const char*>* cm = new std::match_results<const char*>;
                std::string* str = new std::string(m_data.at(i)->GetLastName());
                if (std::regex_match(str->c_str(), *cm, *expr))
                {
                    m_selected.push_back(m_data.at(i));
                }
                delete expr;
                expr = nullptr;
                delete cm;
                cm = nullptr;
                delete str;
                str = nullptr;
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    case FieldNameEnum::Gender:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetGender() == _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    case FieldNameEnum::Position:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetPosition() == _value)
                {
                    m_selected.push_back(m_data.at(i));
                }
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    default:
        _err = ErrorEnum::Wrong_Data_Input;
    }
}
