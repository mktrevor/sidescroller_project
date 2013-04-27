#include "mainwindow.h"

/** Default constructor for MainWindow */
MainWindow::MainWindow() {
	error = new QErrorMessage;
	
	//MENU BAR
	mb = menuBar();
	file = new QMenu("File");
	
  quit = new QAction("Quit", file);
  start = new QAction("Start Game", file);
  
  file->addAction(start);
  file->addAction(quit);
     
  connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
  connect(start, SIGNAL(triggered()), this, SLOT(startSlot()));
  
  mb->addMenu(file);
  
  //TOOL BAR
  toolBar = new QToolBar();
  
  startButton = new QPushButton("Start (F1)");
  quitButton = new QPushButton("Quit (Esc)");
  pauseButton = new QPushButton("Pause (P)");
  optionButton = new QPushButton("Options");
  
  connect(startButton, SIGNAL(clicked()), this, SLOT(startSlot()));
  connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
  connect(optionButton, SIGNAL(clicked()), this, SLOT(options()));
  
  toolBar->addWidget(startButton);
  toolBar->addSeparator();
  toolBar->addWidget(quitButton);
  toolBar->addSeparator();
  toolBar->addWidget(pauseButton);
  toolBar->addSeparator();
  toolBar->addWidget(optionButton);
  
  addToolBar(toolBar);
  
  //TOP WIDGET
  display = new QDockWidget;
  displayWidget = new DisplayWidget;
  display->setWidget(displayWidget);
  addDockWidget(Qt::TopDockWidgetArea, display);
  display->setMaximumSize(1200, 100);
  display->setFeatures(0x00);
  
  //GAME BOARD
  game = new GraphicsWindow();
  setCentralWidget(game);
  connect(game->getTimer(), SIGNAL(timeout()), this, SLOT(update()));
	
	setMinimumSize(1200, 700);
	setMaximumSize(1200, 700);
	
	paused = 0;
	setWindowTitle("MAGIC NINJA");
	setFocus();
}

/** Deconstructor - deallocates all memory from the MainWindow */
MainWindow::~MainWindow() {
	delete error;

	//Deallocation of menu bar
	delete start;
	delete quit;
	delete file;
	
	//Deallocation of game board
	delete game;
}

/** Displays the MainWindow */
void MainWindow::show() {
	QMainWindow::show();
}

void MainWindow::startSlot() { 
	if(game->getTimer()->isActive() || paused) {
		delete game;
		game = new GraphicsWindow;
		setCentralWidget(game);
		connect(game->getTimer(), SIGNAL(timeout()), this, SLOT(update()));
	}
	game->start();	
	setFocus();
}

void MainWindow::pause() {
	if(game->getTimer()->isActive()) {
		game->getTimer()->stop();
	} else {
		game->getTimer()->start();
	}
	paused = !paused;
	setFocus();
}

void MainWindow::options() { }

void MainWindow::update() {
	if(game->gameOver()) {
		error->showMessage("GAME OVER");
		pause();
	}
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
	if(e->key() ==  Qt::Key_D) {
		game->getNinja()->moveRight();
	}
	if(e->key() == Qt::Key_A) {
		game->getNinja()->moveLeft();
	}
	if(e->key() == Qt::Key_W) {
		game->getNinja()->jump();
	}
	if(e->key() ==  Qt::Key_Right) {
		game->fireball(0);
	}
	if(e->key() == Qt::Key_Left) {
		game->fireball(1);
	}
	if(e->key() == Qt::Key_Up) {
		game->fireball(2);
	}
	if(e->key() == Qt::Key_Down) {
		game->fireball(3);
	}
	if(e->key() == Qt::Key_P) {
		pause();
	}
	if(e->key() == Qt::Key_F1) {
		startSlot();
	}
	if(e->key() == Qt::Key_Escape) {
		qApp->quit();
	}
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {
	if(e->key() ==  Qt::Key_D || e->key() == Qt::Key_A) {
		game->getNinja()->stop();
	}
}
