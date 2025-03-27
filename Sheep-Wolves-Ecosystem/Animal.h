#pragma once

struct Animal
{
    Animal(bool isMale) : isMaleGender(isMale) { };
    ~Animal() = default;

    bool isMaleGender{ false };
};
