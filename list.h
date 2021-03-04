#ifndef DL_LIST_H
#define DL_LIST_H
#include <iostream>

namespace cop4530 {

	template <typename T>
		class List {
			private:
				struct Node {
					T data;
					Node *prev;
					Node *next;

					Node(const T & d = T{}, Node *p = nullptr, Node *n = nullptr) 
						: data{d}, prev{p}, next{n} {}
					Node(T && d, Node *p = nullptr, Node *n = nullptr)
						: data{std::move(d)}, prev{p}, next{n} {}
				};

			public:
				List();
				~List();
                bool search(const T& x);


			private:
				int theSize;
				Node *head;
				Node *tail;

				void init();
		};


#include "List.hpp"

}

#endif
