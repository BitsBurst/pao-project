#include "MainView.h"

MainView::MainView(QWidget* parent)
    :   QMainWindow(parent)
{
    setMinimumSize(QSize(640, 360));

    central_widget_ = new QWidget(this);
    central_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create Components
    createMenu();
    createDefaultView();

    // Pallet. TODO: Remove
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::darkBlue);
    central_widget_->setAutoFillBackground(true);
    central_widget_->setPalette(pal);

    // Layout Settings
    layout_ = new QHBoxLayout(central_widget_);
    layout_->setContentsMargins(0,0,0,0);
    layout_->setSpacing(0);

    layout_->addWidget(sidebar_);
    layout_->addWidget(content_);

    central_widget_->setLayout(layout_);

    setCentralWidget(central_widget_);
}

void MainView::createMenu() {
    menu_bar_ = new QMenuBar(this);

    // set MenuBar
    QMenu * file = new QMenu("File", menu_bar_);
    QMenu * sensors = new QMenu("Sensori", menu_bar_);
    menu_bar_->addMenu(file);
    menu_bar_->addMenu(sensors);

    // Menu Sensors
    QAction * single_view = new QAction("Visione Singola", sensors);
    QAction * modify_view = new QAction("Modifica Sensore", sensors);

    sensors->addAction(single_view);
    sensors->addAction(modify_view);

    // Connect Action
    connect(single_view, SIGNAL(triggered()), this, SLOT(showSingleView()));
    connect(modify_view, SIGNAL(triggered()), this, SLOT(showModifyView()));

    setMenuBar(menu_bar_);
}

void MainView::createDefaultView() {

    // Generate all views
    single_view_ = new SingleView();
    group_list_view_ = new GroupListView();
    modify_view_ = new ModifyView();

    // Sidebar Default
    sidebar_ = new SidebarContainer(group_list_view_, central_widget_);
    sidebar_->setMaximumWidth(200);
    sidebar_->show();

    // Content Default
    content_ = new MainContentContainer(single_view_, central_widget_);
    content_->show();
}


// Slots
void MainView::showSingleView() {
    content_->setCurrentView(single_view_);
}

void MainView::showModifyView() {
    content_->setCurrentView(modify_view_);
}