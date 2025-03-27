#pragma once

//for better std::vector optimizations (bit-packing) we could use bool directly instead of `struct Animal`

#pragma pack(push, 1)
struct Animal
{
    Animal(bool isMale) : isMaleGender(isMale) { };
    ~Animal() = default;

    bool isMaleGender{ false };
};
#pragma pack(pop)
