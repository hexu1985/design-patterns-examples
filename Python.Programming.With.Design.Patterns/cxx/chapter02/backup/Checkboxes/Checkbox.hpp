#pragma once

#include <QCheckBox>
#include <QString>

// Checkbox class derived from QCheckBox
class Checkbox : public QCheckBox {
    Q_OBJECT
public:
    Checkbox(QWidget* parent, const QString& text);

    QString getText() const { return m_text; }
    bool getVar() const { return this->isChecked(); }

private:
    QString m_text;
};
