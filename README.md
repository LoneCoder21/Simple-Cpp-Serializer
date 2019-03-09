# Simple-Cpp-Serializer
---------------------------------------------------------------
Description

---------------------------------------------------------------
---------------------------------------------------------------

First Example Code
```
int main() {
	Storage Store("D:/Archivos/texto.txt");
	std::vector <std::vector <int>> X = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	Store.openWrite();
	Store << X;
	Store.closeWrite();
}
```

Console Output
-
`Data 3 Serialized //Vector X contain the next 3 vectors`

`Data 3 Serialized //Vector X[0] contain the next 3 elements`

`Data 1 Serialized`

`Data 2 Serialized`

`Data 3 Serialized`

`Data 3 Serialized //Vector X[1] contain the next 3 elements`

`Data 4 Serialized`

`Data 5 Serialized`

`Data 6 Serialized`

`Data 3 Serialized //Vector X[2] contain the next 3 elements`

`Data 7 Serialized`

`Data 8 Serialized`

`Data 9 Serialized`

So you are saving the amount of elements and the elements

---------------------------------------------------------------
---------------------------------------------------------------

Second Example Code
```cpp
class Data {
	private:
		std::vector <std::vector <int>> X = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	public:
		static void Serialize(Storage &Store, const Data &Object) {
			Store.openWrite();
			Store << Object.X;
			Store.closeWrite();
		}
};

int main() {
	Storage Store("D:/Archivos/texto.txt");
	Data Instance;

	Data::Serialize(Store, Instance);
	return 0;
}
```

You can Convert the Serializer As a class Serializer easly

-----------------------------
Cooming Soon Fatures
-
	Deserializer
