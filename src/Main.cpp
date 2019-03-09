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

		template <typename Var, typename = typename std::enable_if <std::is_class<Var>::value>::type>
		Storage &operator<< (const Var &Object) {
			return *this;
		}

		template <typename Var, typename = typename std::enable_if <!std::is_class <Var>::value>::type>
		Storage &operator<< (const Var value) {
			FileW.write((char*) &value, sizeof(Var));
			std::cout << "Dato " << value << " Serializado " << '\n';
			return *this;
		}

		template <template <class, class> class Container, class A, class B>
		Storage &operator<< (const Container <A, B> &X) {
			if (typeid(Container) != typeid(std::forward_list)) *this << X.size();
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

int main() {
	Storage Store("D:/Archivos/texto.txt");
	std::vector <std::vector <int>> X = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	std::vector <std::vector <int>> Y;

	Store.openWrite();
	Store << X;
	Store.closeWrite();

	Store.openGet();
	Store >> Y;
	Store.closeGet();

	std::cout << "\n. . ."; std::cin.get(); return 0;
}




/*
	Storage Store("D:/Archivos/texto.txt");
	std::array <int, 3> Array = { 5, 4, 10 };
	std::deque <float> Deque = { 2.3f, 4.f, 1.1f };
	//std::forward_list <double> ForwardList = { 4.3, 7.6 };
	std::list <char> List = { 'z', 'w', 'l' };
	std::map <std::string, bool> Map = { {"True", true}, {"NoTrue", false} };
	std::queue <int> Queue;
	{
		Queue.push(8);
		Queue.push(3);
		Queue.push(6);
		Queue.push(1);
	}
	std::set <float> Set = { 3.1f, 2.4f, 5.1f, 4.8f, 1.f };
	std::stack <double> Stack;
	{
		Stack.push(2.3);
		Stack.push(4.6);
		Stack.push(1.9);
		Stack.push(3.8);
	}
	std::unordered_map <std::string, int> UnorderedMap = { {"One", 1}, {"Two", 1}, {"Three", 3} };
	std::unordered_set <double> UnorderedSet = { 5.12, 12.14, 14.0 };
	std::vector <float> Vector = { 4.3f, 5.7f, 8.9f };
	Store.openWrite();
	Store << Array << Deque << List << Map << Queue << Set << Stack << UnorderedMap << UnorderedSet << Vector;
	Store.closeWrite();

	std::cout << "\n\n";

	Store.openGet();
	Store >> Array >> Deque >> List >> Map >> Queue >> Set >> Stack >> UnorderedMap >> UnorderedSet >> Vector;
	Store.closeGet();
*/