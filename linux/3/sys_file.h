#ifndef FOREST_SYS_FILE_H_
#define FOREST_SYS_FILE_H_
//��װ�����ļ�IO��ϵͳ���ã��ṩͬ���Ķ�д����

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
			//���ļ�
			virtual bool	Open(const std::string& path);
			//�������ļ�
			virtual bool	Create(const std::string& path);
			//�ر��ļ�
			virtual void	Close();
			//��ȡ����
			virtual int	Read(char* buffer, int length);
			//д������
			virtual int	Write(const char* buffer, int length);
			//�Ƿ���Ч
			virtual bool	Valid() const;
			
		private:
			void	Clear();

		private:
			int	filedes_;	//�ļ�������
			off_t	read_off_set_;	//��ƫ����
			std::string	path_;	//�ļ�·��
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
