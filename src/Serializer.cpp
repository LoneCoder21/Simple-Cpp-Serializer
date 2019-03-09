#include <iostream>
#include <string>

#include <fstream>
#include <algorithm>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Storage {
	private:
		std::ofstream FileW;
		std::ifstream FileR;
		std::string Path;
		char Buffer[100];
	public:
		Storage(const std::string x) : Path(x) {}

		template <typename Var, typename = typename std::enable_if <!std::is_class <Var>::value>::type>
		Storage &operator<< (const Var value) {
			FileW.write((char*) &value, sizeof(Var));
			std::cout << "Data " << value << " Serialized " << '\n';
			return *this;
		}

		template <template <class, class> class Container, class A, class B>
		Storage &operator<< (const Container <A, B> &X) {
			*this << X.size();
			for (typename Container <A, B>::const_iterator it = X.cbegin(); it != X.cend(); it++) {
				*this << (*it);
			} return *this;
		}

		template <template <class, std::size_t> class Container, class A, std::size_t B>
		Storage &operator<< (const Container <A, B> &X) {
			*this << X.size();
			for (auto it = X.cbegin(); it != X.cend(); it++) {
				*this << (*it);
			} return *this;
		}

		template <template <class, class, class, class> class Container, class A, class B, class C, class D>
		Storage &operator<< (const Container <A, B, C, D> &X) {
			*this << X.size();
			for (typename Container <A, B, C, D>::const_iterator it = X.cbegin(); it != X.cend(); it++) {
				*this << it->first << it->second;
			} return *this;
		}

		//

		template <class A, class B, class C, class D>
		Storage &operator<< (const std::unordered_map <A, B, C, D> &X) {
			*this << X.size();
			for (typename std::unordered_map <A, B, C, D>::const_iterator it = X.cbegin(); it != X.cend(); it++) {
				*this << it->first << it->second;
			} return *this;
		}

		template <class A, class B>
		Storage &operator<< (const std::set <A, B> &X) {
			*this << X.size();
			for (typename std::set <A, B>::const_iterator it = X.cbegin(); it != X.cend(); it++) {
				*this << (*it);
			} return *this;
		}

		template <class A, class B, class C, class D>
		Storage &operator<< (const std::unordered_set <A, B, C, D> &X) {
			*this << X.size();
			for (typename std::unordered_set <A, B, C, D>::const_iterator it = X.cbegin(); it != X.cend(); it++) {
				*this << (*it);
			} return *this;
		}

		template <class A, class B>
		Storage &operator<< (std::stack <A, B> X) {
			*this << X.size();
			while (!X.empty()) {
				*this << (X.top()); X.pop();
			} return *this;
		}

		template <class A, class B>
		Storage &operator<< (std::queue <A, B> X) {
			*this << X.size();
			while (!X.empty()) {
				*this << (X.front()); X.pop();
			} return *this;
		}

		//

		void openWrite() {
			FileW.open(Path, std::ios::out | std::ios::binary);
		}
		void closeWrite() {
			FileW.close();
		}
		void openGet() {
			FileR.open(Path, std::ios::in | std::ios::binary);
		}
		void closeGet() {
			FileR.close();
		}

		//
};
