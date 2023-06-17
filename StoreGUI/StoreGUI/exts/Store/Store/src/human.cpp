#include "human.h"

store::Human::Human(const std::string& _id)
{
	m_id = _id;
}

store::Human::Human(const std::string& _id, int _age) :
	m_id(_id),
	m_age(_age)
{

}
