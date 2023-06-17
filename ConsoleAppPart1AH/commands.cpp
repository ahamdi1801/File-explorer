#include "commands.h"
#include <boost/filesystem.hpp>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>
#include <iostream> 
#include <fstream>
#include <regex>


Commands::Commands()
{

}

Commands::~Commands()
{
  
}
void Commands::GetError(ErrorEnum &_err)
{
    switch (_err)
    {
    case ErrorEnum::No_Error:
        std::cout << "No errors, defined by ErrorEnum, were found." << std::endl;
        break;
    case ErrorEnum::File_Could_Not_Opened:
        std::cout << "File could not be opened." << std::endl;
        break;
    case ErrorEnum::Path_Does_Not_Exist:
        std::cout << "Path does not exist. Directory or file needs to be added in solution directory." << std::endl;
        break;
    case ErrorEnum::Wrong_Data_Input:
        std::cout << "Wrong data input." << std::endl;
        break;
    case ErrorEnum::Not_A_Regular_File_Or_Directory:
        std::cout << "Not a regular file or directory." << std::endl;
        break;
    case ErrorEnum::Data_Vector_Is_Empty:
        std::cout << "Data vector is empty." << std::endl;  
        break;
    case ErrorEnum::Wrong_Data_Type:
        std::cout << "Wrong data type." << std::endl;      
        break;
    }
}

void Commands::Load(std::string _file, ErrorEnum &_err) 
{   
    _err = ErrorEnum::No_Error;
    const boost::filesystem::path p{ "..\\" + _file };


    std::fstream file_stream_read;
    std::string line;
    // try-catch statement taken from example for recursive directory iterator off the internet (can't find the link to site anymore)
    try
    {
        if (exists(p))
        {
            if (is_directory(p))
            {
                for (boost::filesystem::directory_entry& x : boost::filesystem::recursive_directory_iterator(p))
                {
                    if (x.path().extension() == ".txt")
                    {
                        file_stream_read.open(x.path().string());
                        if (file_stream_read.is_open())
                        {
                            std::vector<std::string>* vect = new std::vector<std::string>;
                            while (getline(file_stream_read, line))
                            {
                                vect->push_back(line.substr(3));
                            }
                            file_stream_read.close();
                            std::shared_ptr<Person> pers = std::make_shared<Person>();
                            pers->SetPerson(vect->at(2), vect->at(3), stoi(vect->at(4)), stoi(vect->at(5)), vect->at(6), stoi(vect->at(7)));
                            pers->SetDateAndAge(vect->at(0), vect->at(1));
                            m_data.push_back(pers);
                            delete vect;
                            vect = nullptr;
                            
                        }
                        else
                        {
                            _err = ErrorEnum::File_Could_Not_Opened;
                        }
                    }
                }
                    
            }
            else
                _err = ErrorEnum::Not_A_Regular_File_Or_Directory;
        }
        else
            _err = ErrorEnum::Path_Does_Not_Exist;
    }

    catch (const boost::filesystem::filesystem_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template<>
void Commands::Select(const FieldNameEnum &_field_name, const CompEnum &_comp, const int &_value, ErrorEnum &_err) // nested switch statement for _field_name and _comp
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
                if (m_data.at(i)->GetAge() == _value)
                    m_selected.push_back(m_data.at(i));
            }
            break;
        case CompEnum::Greater:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetAge() > _value)
                    m_selected.push_back(m_data.at(i));
            }
            break;
        case CompEnum::Lesser:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetAge() < _value)
                    m_selected.push_back(m_data.at(i));
            }
            break;
        default:
            _err = ErrorEnum::Wrong_Data_Input;
        }
        break;
    case FieldNameEnum::Confidence:
        switch (_comp)
        {
        case CompEnum::Equal:
            for (int i = 0; i < size; i++)
            {
                if (m_data.at(i)->GetConfidence() == _value)
                    m_selected.push_back(m_data.at(i));
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
                    m_selected.push_back(m_data.at(i));
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
void Commands::Select(const FieldNameEnum& _field_name, const CompEnum& _comp, const std::string& _value, ErrorEnum& _err) // nested switch statement for _field_name and _comp
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
                    m_selected.push_back(m_data.at(i));
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
                std::regex* expr = new std::regex("["+_value +"]\\w+");
                std::match_results<const char*>* cm = new std::match_results<const char*>;
                std::string* str = new std::string(m_data.at(i)->GetLastName());
                if(std::regex_match(str->c_str(),*cm, *expr))
                    m_selected.push_back(m_data.at(i));
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
                    m_selected.push_back(m_data.at(i));
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
                    m_selected.push_back(m_data.at(i));
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



