#include "Checkbox.hpp"

Checkbox::Checkbox(QWidget* parent, const QString& text)
    : QCheckBox(text, parent), m_text(text) {

    // Internet joke about Pineapple on pizza - prevent Pineapple on pizza
    if (m_text == "Pineapple") {
        this->setEnabled(false);
    }
}

