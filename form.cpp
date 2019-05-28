#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>

Form::Form(QWidget *parent) :
    game(NULL),
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;

    QPushButton* newgame = new QPushButton();
    QPushButton* exitgame = new QPushButton();

    newgame->setText("New Game");
    exitgame->setText("Exit");

    QFont font("Verdana", 10);
    newgame->setFont(font);
    exitgame->setFont(font);

    connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(exitgame, SIGNAL(clicked()), this, SLOT(exitGame()));

    settingsLayout->addWidget(newgame);
    settingsLayout->addWidget(exitgame);

    layout->setContentsMargins(2, 2, 2, 2);
    layout->addLayout(settingsLayout);
    newGame();

    setLayout(layout);
}

Form::~Form()
{
    delete ui;
}

void Form::newGame()
{
    if(game)
    {
        layout->removeWidget(game);
        delete game;
    }

    game = new Game(/*4, */this);
    layout->addWidget(game);

    layout->update();

    resize(sizeHint());
}

void Form::exitGame()
{
    MainWindow *f = new MainWindow();
    f->show();
    this->close();
}
