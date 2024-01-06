#include "mainwindow.h"
#include "tests/testDavide.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	TestDavide::runTestV2();
}

MainWindow::~MainWindow() {}
