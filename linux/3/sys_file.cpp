#include <stdio.h>
#include "sys_file.h"

namespace forest
{
	SysFile::SysFile()
	{
		Clear();
	}

	SysFile::~SysFile()
	{
		Clear();
	}

	bool SysFile::Open(const std::string& path)
	{
		if (Valid())
		{
			return false;
		}

		filedes_ = open(path.c_str(), O_RDWR | O_APPEND);
		if (-1 == filedes_)
		{
			perror("open");
			return false;
		}
		else
		{
			path_ = path;
			return true;
		}
	}

	bool SysFile::Create(const std::string& path)
	{
		if (Valid())
		{
			return false;
		}

		filedes_ = open(path.c_str(), O_RDWR | O_APPEND | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG | S_IRWXO);
		if (-1 == filedes_)
		{
			perror("open");
			return false;
		}
		else
		{
			path_ = path;
			return true;
		}
	}

	void SysFile::Close()
	{
		Clear();
	}

	int SysFile::Read(char* buffer, int length)
	{
		if (!Valid() || NULL == buffer || 0 >= length)
		{
			return -1;
		}

		lseek(filedes_, read_off_set_, SEEK_SET);

		ssize_t res = read(filedes_, buffer, length);

		if (-1 == res)
		{
			perror("read");
		}
		else
		{
			read_off_set_ += res;
		}

		return res;
	}

	int SysFile::Write(const char* buffer, int length)
	{
		if (!Valid() || NULL == buffer || 0 >= length)
		{
			return -1;
		}

		return write(filedes_, buffer, length);
	}
}
