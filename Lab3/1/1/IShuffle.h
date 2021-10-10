#pragma once
class IShuffle 
{

public:

    void virtual shuffle() = 0;
    void virtual shuffle(size_t i, size_t j)  =0;

};

