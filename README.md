# Simple-Cpp-Serializer

Usage
```
int main() {
	Storage Store("D:/Archivos/texto.txt");
	std::vector <std::vector <int>> X = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	std::vector <std::vector <int>> Y;

	Store.openWrite();
	Store << X;
	Store.closeWrite();
}
```
