//Builder.h
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>

class Product;

class Builder
{
public:
    virtual ~Builder();
    virtual void BuildPartA(const std::string& buildPara) = 0;
    virtual void BuildPartB(const std::string& buildPara) = 0;
    virtual void BuildPartC(const std::string& buildPara) = 0;
    virtual Product* GetProduct() = 0;

protected:
    Builder();

private:
};

class ConcreteBuilder:public Builder
{
public:
    ConcreteBuilder();
    ~ConcreteBuilder() override;
    void BuildPartA(const std::string& buildPara) override;
    void BuildPartB(const std::string& buildPara) override;
    void BuildPartC(const std::string& buildPara) override;
    Product* GetProduct() override;

protected:
private:
};

#endif //~_BUILDER_H_
