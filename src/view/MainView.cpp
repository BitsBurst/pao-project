#include "MainView.h"

MainView::MainView(QWidget* parent)
    : QMainWindow(parent), central_widget_(new QWidget), layout_(new QHBoxLayout)
{
    // General Settings
    setMinimumSize(QSize(640, 360));
	setDisabled(true);
    // Creation Calls
    createMenu();
    createDefaultView();

    // Layout Settings
    layout_->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    // Layout Widgets
    layout_->addWidget(sidebar_);
    layout_->addWidget(content_);

    // Central Widget
    central_widget_->setLayout(layout_);
    central_widget_->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    setCentralWidget(central_widget_);
}

void MainView::createMenu() {

    // Initialization
    menu_bar_ = new QMenuBar(this);

    // Menu Bar
    QMenu * file = new QMenu("File", menu_bar_);
    QMenu * sensors = new QMenu("Sensori", menu_bar_);
    menu_bar_->addMenu(file);
    menu_bar_->addMenu(sensors);

    // Menu Sensors
    QAction * single_view = new QAction("Visione Singola", sensors);
    QAction * modify_view = new QAction("Modifica Sensore", sensors);
    QAction * create_view = new QAction("Crea Sensore", sensors);

    sensors->addAction(single_view);
    sensors->addAction(modify_view);
    sensors->addAction(create_view);

    // Menu File
    QAction * settings_view = new QAction("Impostazioni App", file);

    file->addAction(settings_view);

    // Connect Action
    connect(single_view, SIGNAL(triggered()), this, SLOT(showSingleView()));
    connect(modify_view, SIGNAL(triggered()), this, SLOT(showModifyView()));
    connect(create_view, SIGNAL(triggered()), this, SLOT(showCreateView()));
    connect(settings_view, SIGNAL(triggered()), this, SLOT(showSettingsView()));

    setMenuBar(menu_bar_);
}

void MainView::createDefaultView() {

    // Initialization - Views
    single_view_ = new SingleView();
    modify_view_ = new ModifyView();
    create_view_ = new CreateView();
    settings_view_ = new SettingsView();

    group_list_view_ = new GroupListView();

    // Initialization - Contianer
    content_ = new MainContentContainer(single_view_, central_widget_);
    content_->show();

    sidebar_ = new SidebarContainer(group_list_view_, central_widget_);
    sidebar_->show();
}


// Slots
void MainView::showSingleView() {
    content_->setCurrentView(single_view_);
}

void MainView::showModifyView() {
    content_->setCurrentView(modify_view_);
}

void MainView::showCreateView() {
    content_->setCurrentView(create_view_);
}

void MainView::showSettingsView() {
    content_->setCurrentView(settings_view_);
}