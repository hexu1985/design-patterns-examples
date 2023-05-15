//Context.h
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class Strategy;

/**
 * 这个类是 Strategy 模式的关键，也是 Strategy模式和 Template 模式的根本区别所在。
 * Strategy 通过“组合”（委托）方式实现算法（实现）的异构，而 Template 模式则采取的是继承的方式
 * 这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
 */
class Context {
public:
    Context(Strategy* stg);
    ~Context();
    void DoAction();
protected:
private:
    Strategy* _stg;
};

#endif //~_CONTEXT_H_ 
