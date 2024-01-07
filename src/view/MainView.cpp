#include "MainView.h"

MainView::MainView(QWidget* parent)
    :   QMainWindow(parent)
{
    setMinimumSize(QSize(640, 360));

    central_widget_ = new QWidget(this);

    // Create Components
    createMenu();
    createDefaultView();

    /*
     * TODO[Luca]: Remove Color palette.
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::darkBlue);
    central_widget_->setAutoFillBackground(true);
    central_widget_->setPalette(pal);
    */

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

    // Generate all views
    single_view_ = new SingleView();
    group_list_view_ = new GroupListView();
    modify_view_ = new ModifyView();
    create_view_ = new CreateView();
    settings_view_ = new SettingsView();

    // Sidebar Default
    sidebar_ = new SidebarContainer(group_list_view_, central_widget_);
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

void MainView::showCreateView() {
    content_->setCurrentView(create_view_);
}

void MainView::showSettingsView() {
    content_->setCurrentView(settings_view_);
}