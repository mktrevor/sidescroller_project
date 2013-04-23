#include "mainwindow.h"

/** Default constructor for MainWindow */
MainWindow::MainWindow() {
		error = new QErrorMessage;
		
		//MENU BAR
		/*mb = menuBar();
		file = new QMenu("File");
		
    quit = new QAction("Quit", file);
    start = new QAction("Start Game", file);
    
    file->addAction(start);
    file->addAction(quit);
       
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(start, SIGNAL(triggered()), this, SLOT(pressStart()));*/
    
    //mb->addMenu(file);
    
    //TOOL BAR
    //toolBar = new QToolBar();
    
    //GAME BOARD
    game = new GraphicsWindow();
    setCentralWidget(game->getView());
		
		this->setMinimumSize(1200, 700);
}

/** Deconstructor - deallocates all memory from the MainWindow */
MainWindow::~MainWindow() {
	delete error;

	//Deallocation of menu bar
	/*delete start;
	delete quit;
	delete file;*/

	
	//Deallocation of game board
	delete game;
}

/** Displays the MainWindow */
void MainWindow::show() {
	QMainWindow::show();
}
