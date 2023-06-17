#ifndef ERR_COMP_H
#define ERR_COMP_H
#include <map>

namespace store {
	enum class ErrorEnum
	{
		No_Error,
		Wrong_Data_Input,
		Path_Does_Not_Exist,
		File_Could_Not_Opened,
		Not_A_Regular_File_Or_Directory,
		Data_Vector_Is_Empty,
		Wrong_Data_Type
	};

	enum class CompEnum
	{
		Greater,
		Equal,
		Lesser
	};

	enum class FieldNameEnum
	{
		First_Name,
		Last_Name,
		Age,
		Height,
		Gender,
		Position,
		Confidence,
		Path,
		Item_Index
	};
}
#endif
