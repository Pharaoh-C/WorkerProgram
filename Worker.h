#pragma once
#include <string>

class Worker
{
private:
	std::string name;
	int wage;
	static int num_workers;
	
public:
	std::string get_name() { return name; }
	int get_wage() { return wage; }

	Worker(std::string name_val = "None", int wage_val = 0);

	Worker(const Worker& source);

	~Worker();

	static int get_num_workers();
	static void get_workers();
};