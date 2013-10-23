#ifndef LIBRARY_BOOK_H_
#define LIBRARY_BOOK_H_

#include <string>

//

namespace library
{
	class Book
	{
		public:
			typedef unsigned int PageNumber;

		public:
			//�鼮����
			enum BookType
			{};

			//�鼮��Դ
			enum BookSource
			{};

		public:
			Book();
			Book(const std::string& name, PageNumber total_page, const BookType& type, 
			     const BookSource& srouce);
			Book(const std::string& name, PageNumber total_page, PageNumber read_page,
			     const BookType& type, const BookSource& source);
			~Book();

		public:
			std::string	name() const { return name_; }
			void		set_name(const std::string& name) { name_ = name; }
			PageNumber	total_page() const { return total_page_; }
			void		set_total_page(PageNumber number) { total_page_ = number; }
			PageNumber	read_page() const { return read_page_; }
			void		set_read_page(PageNumber number) { read_page_ = number; }
			BookType	type() const { return type_; }
			void		set_type(const BookType& type) { type_ = type; }
			BookSource	source() const { return source_; }
			void		set_source(const BookSource& source) { source_ = source; }

		private:
			//��ʼ��
			void	Initialize(const std::string& name, PageNumber total_page, 
					   PageNumber read_page, const BookType& type, const BookSource& source);

		private:
			std::string	name_;		//����
			PagerNumber	total_page_;	//��ҳ��
			PagerNumber	read_page_;	//�Ѷ�ҳ��
			BookType	type_;		//�鼮����
			BookSource	source_;	//�鼮��Դ
	};
}

#endif
