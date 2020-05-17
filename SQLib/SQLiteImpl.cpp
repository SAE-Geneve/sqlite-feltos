#include "SQLiteImpl.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>

namespace sql {

	static int Callback(void* ptr, int ac, char** av, char** column_name) 
	{
		auto* sqlite_impl = static_cast<SQLiteImpl*>(ptr);

		return 0;
	}

	//DONE
	SQLiteImpl::SQLiteImpl(const std::string& file)
	{
		auto sqlOpen = sqlite3_open(file.c_str(),&db_);

		if (sqlOpen != 0) {
			throw std::runtime_error("SqlOpen error");
		}
	}

	//DONE
	SQLiteImpl::~SQLiteImpl()
	{
		sqlite3_close(db_);
	}

	bool SQLiteImpl::ExecuteString(const std::string& cmd)
	{
		error_.clear();
		table_.clear();

		auto test = &error_;

		//can't reach adress of error
		//sqlite3_exec(db_,cmd.c_str(),Callback,this,error pointers);
		return true;
	}

	sql::value_t SQLiteImpl::GetValue(const std::string& str) const
	{
		if (str.empty()) { return nullptr;}

		//check for double
		int nb_points = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '.') { nb_points++; }
		}
		if (nb_points <= 1) {
			return str;
		}

		return str;
	}

} // End namespace sql.
