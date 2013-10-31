#include <iostream>
#include "sys_file.h"

int main(int argc, char** argv)
{	
	if (1 >= argc)
	{
		std::cout<<"no input file path"<<std::endl;
		return 0;
	}

	forest::SysFile file;
 	if (!file.Create(argv[1]))
	{
		return 0;
	}

	std::string str;
	str = "hello1";
	if (str.size() != file.Write(str.c_str(), str.size()))
	{
		std::cout<<"write to file failed"<<std::endl;
	}
	str = "hello2";
	if (str.size() != file.Write(str.c_str(), str.size()))
	{
		std::cout<<"write to file failed"<<std::endl;
	}
	str = "hello3";
	if (str.size() != file.Write(str.c_str(), str.size()))
	{
		std::cout<<"write to file failed"<<std::endl;
	}

	char buffer[7] = {0};
	int res = 0;
	while (true)
	{
		res = file.Read(buffer, 6);
		if (0 == res)
		{
			std::cout<<"end of file"<<std::endl;
			break;
		}

		if (-1 == res)
		{
			std::cout<<"read failed"<<std::endl;
			break;
		}

		std::cout<<buffer<<std::endl;
	}

	return 0;
}
