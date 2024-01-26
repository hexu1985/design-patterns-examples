#include "Main.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <iostream>
#include <QApplication>
#include "drawer/DrawCommand.hpp"
#include "drawer/ColorCommand.hpp"

Main::Main(const QString& title, QWidget *parent)
	: QWidget(parent)
{
    history = std::shared_ptr<MacroCommand>(new MacroCommand);

    setWindowTitle(title);    

    QHBoxLayout *buttonBox = new QHBoxLayout;

    clearButton = new QPushButton("clear", this);
    buttonBox->addWidget(clearButton);

    redButton = new QPushButton("red", this);
    buttonBox->addWidget(redButton);

    greenButton = new QPushButton("green", this);
    buttonBox->addWidget(greenButton);

    blueButton = new QPushButton("blue", this);
    buttonBox->addWidget(blueButton);
   
    QVBoxLayout *mainBox = new QVBoxLayout;

    mainBox->addLayout(buttonBox);
    
    canvas = new DrawCanvas(400, 400, history);
    mainBox->addWidget(canvas);

    setLayout(mainBox);

//    setMinimumSize(600,400);

    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(redButton, SIGNAL(clicked()), this, SLOT(onRedButtonClicked()));
    connect(greenButton, SIGNAL(clicked()), this, SLOT(onGreenButtonClicked()));
    connect(blueButton, SIGNAL(clicked()), this, SLOT(onBlueButtonClicked()));
	canvas->installEventFilter(this);
}

bool Main::eventFilter(QObject* watched,QEvent* event)
{
	if(watched == canvas)
	{
		if(event->type() == QEvent::MouseMove)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;	
            mouseDragged(mouseEvent);
		}		
	}

	return QWidget::eventFilter(watched,event);	
}

void Main::mouseDragged(QMouseEvent *e)
{
    std::shared_ptr<Command> cmd(new DrawCommand(canvas, e->pos()));
    history->append(cmd);
    cmd->execute();
}

void Main::onClearButtonClicked()
{
    history->clear();
    canvas->repaint();
}

void Main::onRedButtonClicked()
{
    setColor(Qt::red);
}

void Main::onGreenButtonClicked()
{
    setColor(Qt::green);
}

void Main::onBlueButtonClicked()
{
    setColor(Qt::blue);
}

void Main::setColor(QColor color)
{
    std::shared_ptr<Command> cmd(new ColorCommand(canvas, color));
    history->append(cmd);
    cmd->execute();
}

int
main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    Main m("Command Pattern Sample");
    m.show();
    return app.exec();
}
