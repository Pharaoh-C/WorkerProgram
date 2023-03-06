#include <iostream>
#include "Worker.h"

using namespace std;


int main()
{
	Worker cihan{ "Cihan", 200 };
	Worker arda{ "Arda" };
	Worker::get_num_workers();
	Worker dila;
	Worker::get_workers();
}