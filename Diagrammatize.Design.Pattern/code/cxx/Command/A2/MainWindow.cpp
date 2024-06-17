#include "MainWindow.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include "drawer/DrawCommand.hpp"

MainWindow::MainWindow(const QString& title, QWidget *parent)
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

bool MainWindow::eventFilter(QObject* watched,QEvent* event)
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

void MainWindow::mouseDragged(QMouseEvent *e)
{
    std::shared_ptr<Command> cmd(new DrawCommand(canvas, e->pos()));
    history->append(cmd);
    cmd->execute();
}

void MainWindow::onClearButtonClicked()
{
    history->clear();
    canvas->repaint();
}

void MainWindow::onUndoButtonClicked()
{
    history->undo();
    canvas->repaint();
}

