#include "mainwindow.h"

/** Default constructor for MainWindow */
MainWindow::MainWindow() {
	
	error = new QErrorMessage;
	inputName = new QInputDialog();
	inputName->setLabelText("Please enter your name");
	inputName->setInputMode(QInputDialog::TextInput);
	
	//MENU BAR
	mb = menuBar();
	file = new QMenu("File");
	
  quit = new QAction("Quit", file);
  start = new QAction("Start Game", file);
  
  file->addAction(start);
  file->addAction(quit);
     
  connect(quit, SIGNAL(triggered()), this, SLOT(quitGame()));
  connect(start, SIGNAL(triggered()), this, SLOT(startSlot()));
  
  mb->addMenu(file);
  
  //TOOL BAR
  toolBar = new QToolBar();
  
  startButton = new QPushButton("Start (F1)");
  quitButton = new QPushButton("Quit (Esc)");
  pauseButton = new QPushButton("Pause/Resume (P)");
  
  connect(startButton, SIGNAL(clicked()), this, SLOT(startSlot()));
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitGame()));
  connect(pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
  
  toolBar->addWidget(startButton);
  toolBar->addSeparator();
  toolBar->addWidget(quitButton);
  toolBar->addSeparator();
  toolBar->addWidget(pauseButton);
  
  addToolBar(toolBar);
  
  //TOP WIDGET
  display = new QDockWidget;
  displayWidget = new DisplayWidget;
  display->setWidget(displayWidget);
  addDockWidget(Qt::TopDockWidgetArea, display);
  display->setMaximumSize(1200, 100);
  display->setFeatures(0x00);
  
  //GAME DISPLAY
  title = new InfoScreen(0);
  gameOver = new InfoScreen(1);
  setCentralWidget(title);
  gameInProgress = 0;
	
	setMinimumSize(1200, 700);
	setMaximumSize(1200, 700);
	
	paused = 0;
	setWindowTitle("MAGIC NINJA");
	setFocus();
}

/** Deconstructor - deallocates all memory from the MainWindow */
MainWindow::~MainWindow() {
	delete error;
	delete inputName;

	//Deallocation of menu bar
	delete start;
	delete quit;
	delete file;
	
	//Deallocation of toolbar
	delete startButton;
	delete quitButton;
	delete pauseButton;
	delete toolBar;
	
	//Deallocation of game board
	if(gameInProgress) {
		delete game;
	}
	
	//Deallocation of top widget
	delete displayWidget;
	delete display;
}

/** Displays the MainWindow */
void MainWindow::show() {
	QMainWindow::show();
}

void MainWindow::quitGame() {
	if(!paused && gameInProgress) {
		pause();
	}
	question = new QuestionBox("Are you sure you want to quit?", "Quit Game");
	if(question->exec() == QMessageBox::No) {
		setFocus();
		delete question;
		if(gameInProgress) {
			pause();
		}
		return;
	}
		qApp->quit();
}
	
void MainWindow::startSlot() { 
	question = new QuestionBox("Start a new game?", "New Game");
	if(gameInProgress && !paused) {
		pause();
	}
	if(question->exec() == QMessageBox::No) {
		setFocus();
		delete question;
		if(gameInProgress) {
			pause();
		}
		return;
	}
	if(!gameInProgress && !paused) {
		
		bool ok;
		name = inputName->getText(this, tr("Name"), tr("Please enter your name."), QLineEdit::Normal, "", &ok);
		if(!ok) {
			setFocus();
			return;
		}
		displayWidget->setName(name);
		game = new GraphicsWindow;
		setCentralWidget(game);
		connect(game->getTimer(), SIGNAL(timeout()), this, SLOT(update()));
		game->start();
		gameInProgress = 1;
	} else if(game->getTimer()->isActive() || paused) {
		bool ok;
		name = inputName->getText(this, tr("Name"), tr("Please enter your name."), QLineEdit::Normal, "", &ok);
		if(!ok) {
			setFocus();
			return;
		}
		displayWidget->setName(name);
		delete game;
		game = new GraphicsWindow;
		setCentralWidget(game);
		connect(game->getTimer(), SIGNAL(timeout()), this, SLOT(update()));
		game->start();	
		gameInProgress = 1;
	}
	setFocus();
}

void MainWindow::pause() {
	if(!gameInProgress) {
		return;
	}
	if(game->getTimer()->isActive()) {
		game->getTimer()->stop();
	} else {
		game->getTimer()->start();
	}
	paused = !paused;
	setFocus();
}

void MainWindow::update() {
	displayWidget->setScore(QString::number(game->getScore()));
	displayWidget->setHealth(QString::number(game->getNinja()->getHealth()));
	displayWidget->setLives(QString::number(game->getNinja()->getLives()));
	
	if(game->gameOver()) {
		gameInProgress = 0;
		pause();
		delete game;
		gameOver = new InfoScreen(1);
		setCentralWidget(gameOver);
	}
	if(!game->getTimer()->isActive()) {
		paused = 1;
	}
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
	if(gameInProgress) {
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
	}
	if(e->key() == Qt::Key_F1) {
		startSlot();
	}
	if(e->key() == Qt::Key_Escape) {
		quitGame();
	}
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {
	if(gameInProgress) {
		if(e->key() ==  Qt::Key_D || e->key() == Qt::Key_A) {
			game->getNinja()->stop();
		}
	}
}
