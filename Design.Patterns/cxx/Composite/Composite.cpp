//Composite.cpp
#include "Composite.h"
#include "Component.h"

#include <algorithm>

Composite::Composite()
{
}

Composite::~Composite()
{
}

void Composite::Operation()
{
    vector<Component*>::iterator comIter = comVec.begin();

    for (;comIter != comVec.end();comIter++)
    {
        (*comIter)->Operation();
    }
}

void Composite::Add(Component* com)
{
    comVec.push_back(com);
}

void Composite::Remove(Component* com)
{
    vector<Component*>::iterator iter = std::find(comVec.begin(), comVec.end(), com);
    if (iter == comVec.end()) {
        return;
    }

    std::iter_swap(iter, comVec.end()-1);
    comVec.pop_back();
}

Component* Composite::GetChild(int index)
{
    return comVec[index];
} 
