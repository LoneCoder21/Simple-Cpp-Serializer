#ifndef Serializer_hpp
#define Serializer_hpp

#include "Serializer.h"

Storage::Storage(const std::string z) {
	Path = z;
}

template <typename Var>
Storage &Storage::operator<< (Var &value) {
	if (!FileW.is_open()) {
		FileW.open(Path, std::ios::out | std::ios::binary);
		assert(!FileW.fail());
	}
	FileW.write((char*)&value, sizeof(Var));
	return *this;
}

template <typename Var>
Storage &Storage::operator>> (Var &value) {
	if (!FileR.is_open()) {
		FileR.open(Path, std::ios::in | std::ios::binary);
		assert(!FileR.fail());
	}
	char Buffer[100]; static int i = 0; i += sizeof(Var);
	FileR.read(Buffer, i);
	value = *(Var*)Buffer;
	return *this;
}

void Storage::close() {
	if (FileW.is_open()) FileW.close();
	if (FileR.is_open()) FileR.close();
}

#endif