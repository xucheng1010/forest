#include "library_book.h"

namespace library
{
	Book::Book()
	{
		Initialize(std::string(), 0, 0);
	}

	Book::Book(const std::string& name, PageNumber total_page,
		   const BookType& type, const BookSource& source)
	{
		Initialize(name, total_page, 0, type, srouce);
	}

	Book::Book(const std::string& name, PageNumber total_page, PageNumber read_page,
		   const BookType& type, const BookSource& source)
	{
		Initialize(name, total_page, read_page, type, source);
	}

	Book::~Book()
	{

	}

	void Book::Initialize(const std::string& name, PageNumber total_page, PageNumber read_page,
			      const BookType& type, const BookSource& source)
	{
		name_ = name;
		total_page_ = total_page;
		read_page_ = read_page;
		type_ = type;
		source_ = source;
	}
}
