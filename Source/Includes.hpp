#ifndef Includes_h
#define Includes_h

#include <iostream>
#include <string>

#include <cassert>
#include <fstream>

#define Serializer template <class Var> static void Serialize(Storage &Store, Var &Object)
#define Deserializer template <class Var> static void Deserialize(Storage &Store, Var &Object)

#endif