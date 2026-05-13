#include "DButton.hpp"

class Mediator;

// 示例按钮类，对应 Python 中的 SampleButton
class SampleButton : public DButton {
    Q_OBJECT

private:
    Mediator* med;

public:
    SampleButton(Mediator* mediator, QWidget* parent = nullptr) ;

    void comd() override;
};
