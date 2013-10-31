#ifndef FOREST_SYS_FILE_H_
#define FOREST_SYS_FILE_H_
//封装关于文件IO的系统调用，提供同步的读写操作

#include <fcntl.h>
#include <unistd.h>
#include "file_interface.h"

namespace forest
{
	class SysFile : public FileInterface
	{
		public:
			SysFile();
			~SysFile();

		public:
			//打开文件
			virtual bool	Open(const std::string& path);
			//创建新文件
			virtual bool	Create(const std::string& path);
			//关闭文件
			virtual void	Close();
			//读取数据
			virtual int	Read(char* buffer, int length);
			//写入数据
			virtual int	Write(const char* buffer, int length);
			//是否有效
			virtual bool	Valid() const;
			
		private:
			void	Clear();

		private:
			int	filedes_;	//文件描述符
			off_t	read_off_set_;	//读偏移量
			std::string	path_;	//文件路径
	};

	inline bool SysFile::Valid() const
	{
		return -1 != filedes_;
	}

	inline void SysFile::Clear()
	{
		if (Valid())
		{
			close(filedes_);
		}

		filedes_ = -1;
		read_off_set_ = 0;
		path_ = "";
	}
}


#endif
