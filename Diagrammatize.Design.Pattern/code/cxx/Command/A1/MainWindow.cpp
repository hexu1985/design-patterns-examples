#include "MainWindow.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include "drawer/DrawCommand.hpp"
#include "drawer/ColorCommand.hpp"

MainWindow::MainWindow(const QString& title, QWidget *parent)
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

void MainWindow::onRedButtonClicked()
{
    setColor(Qt::red);
}

void MainWindow::onGreenButtonClicked()
{
    setColor(Qt::green);
}

void MainWindow::onBlueButtonClicked()
{
    setColor(Qt::blue);
}

void MainWindow::setColor(QColor color)
{
    std::shared_ptr<Command> cmd(new ColorCommand(canvas, color));
    history->append(cmd);
    cmd->execute();
}

