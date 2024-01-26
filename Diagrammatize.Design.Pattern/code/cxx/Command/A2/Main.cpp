#include "Main.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <iostream>
#include <QApplication>
#include "drawer/DrawCommand.hpp"

Main::Main(const QString& title, QWidget *parent)
	: QWidget(parent)
{
    history = std::shared_ptr<MacroCommand>(new MacroCommand);

    setWindowTitle(title);    

    QHBoxLayout *buttonBox = new QHBoxLayout;

    clearButton = new QPushButton("clear", this);
    buttonBox->addWidget(clearButton);

    undoButton = new QPushButton("undo", this);
    buttonBox->addWidget(undoButton);

    QVBoxLayout *mainBox = new QVBoxLayout();

    mainBox->addLayout(buttonBox);
    
    canvas = new DrawCanvas(400, 400, history);
    mainBox->addWidget(canvas);

    setLayout(mainBox);

//    setMinimumSize(600,400);

    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(undoButton, SIGNAL(clicked()), this, SLOT(onUndoButtonClicked()));
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

void Main::onUndoButtonClicked()
{
    history->undo();
    canvas->repaint();
}

int
main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    Main m("Command Pattern Sample");
    m.show();
    return app.exec();
}
