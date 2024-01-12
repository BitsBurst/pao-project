#include "MainView.h"
#include "views/SingleViewSensor.h"

MainView::MainView(QStackedWidget * content, QStackedWidget * sidebar, QWidget* parent)
    : QMainWindow(parent), central_widget_(new QWidget), layout_(CustomElements::getCustomLayoutPrototype(H_NO_BORDER))
{
    // General Settings
    setMinimumSize(QSize(640, 360));

    // Initialization
    content_ = new MainContentContainer(content, this);
    sidebar_ = new SidebarContainer(sidebar, this);

    // Creation Calls
    createMenu();

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
    connect(single_view, &QAction::triggered, this, &MainView::changeToSingleView);
    connect(modify_view, &QAction::triggered, this, &MainView::changeToModifyView);
    connect(create_view, &QAction::triggered, this, &MainView::changeToCreateView);
    connect(settings_view, &QAction::triggered, this, &MainView::changeToSettingsView);

    setMenuBar(menu_bar_);
}

void MainView::createDefaultView(int content_id, int sidebar_id) {
    content_->setCurrentView(content_id);
    sidebar_->setCurrentView(sidebar_id);
}


void MainView::setContentView(int content_id)
{
    content_->setCurrentView(content_id);
}

void MainView::setSidebarView(int sidebar_id)
{
    sidebar_->setCurrentView(sidebar_id);
}
