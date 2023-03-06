#include "Worker.h"
#include <fstream>
#include <iostream>

using namespace std;

int Worker::num_workers{ 0 };
//create
Worker::Worker(std::string name_val, int wage_val)
	:name{ name_val }, wage{ wage_val }
{
    std::ofstream dosya;
    dosya.open("dosya.txt", std::ios_base::app);//dosyayý yazma modunda açar bu ve üstteki

    if (dosya.is_open()) // Dosyanýn açýlýp açýlmadýðýný kontrol edin
    {
        cout << "File opened succesfully for writing!" << endl;

        dosya << name_val << "\t\t" << wage_val << endl;
        cout << name_val << " dosyaya yazildi." << endl;

        dosya.close();
    }
    else
    {
        std::cerr << "Cant open file for writing!" << endl;
        throw std::runtime_error("Cant open file");
    }
}
//copy
Worker::Worker(const Worker& source)
    :Worker{ source.name,source.wage }
{
}
Worker::~Worker()
{
}

void Worker::get_workers()
{
    ifstream dosya("dosya.txt");
    cout << endl;
    if (dosya.is_open())
    {
        std::string line;
        while (getline(dosya, line))
        {
            cout << "----------------------------------" << endl;
            cout << line << endl;
        }
        dosya.close();
    }
    else
    {
        cerr << "Cant open file!" << endl;
    }
}



int Worker::get_num_workers()
{
    num_workers = 0;
    std::ifstream dosya;
    dosya.open("dosya.txt", std::ios_base::in); //dosyayý okuma modunda açar bu ve üstteki 
   
    if (dosya.is_open()) // Dosyanýn açýlýp açýlmadýðýný kontrol edin
    {
        cout << "File opened succesfully for reading!" << endl;
        std::string line;
        while (getline(dosya,line))
        {
            ++num_workers;
        }
        dosya.close();
        cout << "We have " << num_workers << " employees." << endl;
        return num_workers;
    }
    else
    {
        std::cerr << "Cant open file for reading!" << std::endl;
        throw std::runtime_error("Cant open file");
    }	
}


