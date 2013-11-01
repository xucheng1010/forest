#include <iostream>
#include <vector>
#include "sys_file.h"

int DupEx(int filedes, int filedes2)
{
	if (filedes == filedes2)
	{
		return filedes2;
	}

	close(filedes);

	int size = filedes2 - filedes;

	size = size > 0 ? size : -size;

	std::vector<int> filede(size);

	int begin_res = 0;
	int end_res = 0;

	begin_res = end_res = dup(filedes);

	while (true)
	{
		if (end_res >= filedes2 || -1 == end_res)
		{
			break;
		}
		filede.push_back(end_res);

		end_res = dup(filedes);
	}

	if (-1 == end_res || end_res > filedes2)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < filede.size(); ++i)
		{
			close(filede[i]);
		}

		return filedes2;
	}
}

int main(int argc, char** argv)
{
	if (1 >= argc)
	{
		std::cout<<"no input file"<<std::endl;
		return 0;
	}

	int filedes = open(argv[1], O_RDWR);
	if (-1 == filedes)
	{
		perror("open");
		return 0;
	}

	int dup_filedes = DupEx(filedes, 100);
	if (-1 == dup_filedes)
	{
		perror("dup");
		return 0;
	}

	char buffer[6] = {0};
	int res = 0;
	while (true)
	{
		res = read(filedes, buffer, 5);
		if (-1 == res)
		{
			perror("read");
			break;
		}

		if (0 == res)
		{
			std::cout<<"filedes end of file"<<std::endl;
			break;
		}

		std::cout<<"filedes buffer = "<<buffer<<std::endl;

		res = read(dup_filedes, buffer, 5);
		if (-1 == res)
		{
			perror("read");
			break;
		}

		if (0 == res)
		{
			std::cout<<"dup_filedes end of file"<<std::endl;
			break;
		}

		std::cout<<"dup_filedes buffer = "<<buffer<<std::endl;
	}
}
