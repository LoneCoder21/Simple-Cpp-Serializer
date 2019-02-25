#ifndef Serializer_h
#define Serializer_h

#include "Includes.hpp"

struct Storage {
	private:
		std::ofstream FileW;
		std::ifstream FileR;
		std::string Path;
	public:
		Storage(const std::string);
		//
		template <typename Var>
		Storage &operator<< (Var &);
		//
		template <typename Var>
		Storage &operator>> (Var &);
		//
		void close();
};

#endif