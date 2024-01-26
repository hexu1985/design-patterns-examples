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

    QHBoxLayout *hboxLayout = new QHBoxLayout;

    clearButton = new QPushButton("clear", this);
    hboxLayout->addWidget(clearButton);

    redButton = new QPushButton("red", this);
    hboxLayout->addWidget(redButton);

    greenButton = new QPushButton("green", this);
    hboxLayout->addWidget(greenButton);

    blueButton = new QPushButton("blue", this);
    hboxLayout->addWidget(blueButton);
   
    QVBoxLayout *defaultLayout = new QVBoxLayout;

    defaultLayout->addLayout(hboxLayout);
    
    canvas = new DrawCanvas(400, 400, history);
    defaultLayout->addWidget(canvas);

    setLayout(defaultLayout);

//    setMinimumSize(600,400);

    connect(clearButton, SIGNAL(clicked()), canvas, SLOT(clear()));
    connect(redButton, SIGNAL(clicked()), this, SLOT(setRedColor()));
    connect(greenButton, SIGNAL(clicked()), this, SLOT(setGreenColor()));
    connect(blueButton, SIGNAL(clicked()), this, SLOT(setBlueColor()));
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

void Main::setRedColor()
{
    setColor(Qt::red);
}

void Main::setGreenColor()
{
    setColor(Qt::green);
}

void Main::setBlueColor()
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
