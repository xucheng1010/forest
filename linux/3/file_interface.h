#ifndef FOREST_FILE_INTERFACE_H_
#define FOREST_FILE_INTERFACE_H_

#include <string>

namespace forest
{
	class FileInterface
	{
		public:
			FileInterface(){}
			virtual ~FileInterface(){};

		public:
			virtual bool	Open(const std::string& path) = 0;
			virtual bool	Create(const std::string& path) = 0;
			virtual void	Close() = 0;
			virtual int	Read(char* buffer, int length) = 0;
			virtual int	Write(const char* buffer, int length) = 0;
			virtual bool	Valid() const = 0;
	};
}

#endif
