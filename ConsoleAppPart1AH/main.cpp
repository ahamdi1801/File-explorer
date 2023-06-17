#include <iostream>
#include "commands.h"
#include "person.h"
#include "err_comp.h"
#include <boost/filesystem.hpp>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <regex>
#include <numeric>


int main()
{
    ErrorEnum err;
    Commands* com = new Commands();
    std::vector<std::shared_ptr<Person>> selected;

    auto t1 = boost::posix_time::from_time_t(boost::chrono::system_clock::to_time_t(boost::chrono::system_clock::now()));
    com->Load("data//2000//01//01", err);
    auto t2 = boost::posix_time::from_time_t(boost::chrono::system_clock::to_time_t(boost::chrono::system_clock::now()));
    auto time = (t2 - t1).total_seconds(); // measure load time

    FieldNameEnum fieldname = FieldNameEnum::First_Name;
    CompEnum comp = CompEnum::Equal;
    std::string value = "ABC";

    com->Select<std::string>(fieldname, comp, value, err);
    selected = com->GetSelected();

    for (size_t i = 0; i < selected.size(); i++)
    {
        selected.at(i)->GetAllData();
    }
    std::cout << "It took " << time << " seconds to run load(data,err)." << std::endl;
    com->GetError(err);
    delete com;
    com = nullptr;


    return 0;
}
