# Simple-Cpp-Serializer
---------------------------------------------------------------
Description

---------------------------------------------------------------
---------------------------------------------------------------

Example Code
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
`//Vector X contain the next 3 vectors`

`Data 3 Serialized`

`//Vector X[0] contain the next 3 elements`

`Data 3 Serialized`

`Data 1 Serialized`

`Data 2 Serialized`

`Data 3 Serialized`

`//Vector X[1] contain the next 3 elements`

`Data 3 Serialized`

`Data 4 Serialized`

`Data 5 Serialized`

`Data 6 Serialized`

`//Vector X[2] contain the next 3 elements`

`Data 3 Serialized`

`Data 7 Serialized`

`Data 8 Serialized`

`Data 9 Serialized`

---------------------------------------------------------------
---------------------------------------------------------------

So you are saving the amount of elements and the elements
