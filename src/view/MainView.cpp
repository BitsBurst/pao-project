#include "MainView.h"
#include "widgets/SingleWidget/SingleSensorWidget.h"

MainView::MainView(QStackedWidget * content, QStackedWidget * sidebar, QWidget* parent)
    : QMainWindow(parent), central_widget_(new QWidget), layout_(CustomElements::getCustomLayoutPrototype(H_NO_BORDER))
{
    // General Settings
    setMinimumSize(QSize(640, 360));


    // Initialization
    content_ = new MainContentContainer(content, this);
    sidebar_ = new SidebarContainer(sidebar, this);
    searchbar_ = static_cast<SidebarContainer*>(sidebar_)->getSearch();

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
    QMenu * categories = new QMenu("Categorie", menu_bar_);
    menu_bar_->addMenu(file);
    menu_bar_->addMenu(sensors);
    menu_bar_->addMenu(categories);

    // Menu Sensors
    QAction * single_sensor_view = new QAction("Visione Singola", sensors);
    QAction * single_group_view = new QAction("Visione Singola di gruppo", sensors);
    QAction * create_sensor = new QAction("Crea", sensors);

    sensors->addAction(create_sensor);
    sensors->addAction(single_sensor_view);
    sensors->addAction(single_group_view);

    // Menu File
    QAction * opensimulation = new QAction("Apri file simulazione", file);
	QAction * exportsimulation = new QAction("Esporta file simulazione", file);

    file->addAction(opensimulation);
	file->addAction(exportsimulation);

    // Menu Categories
    QAction * create_category = new QAction("Crea", categories);

    categories->addAction(create_category);

    // Connect Action
    connect(single_sensor_view, &QAction::triggered, this, &MainView::changeToSingleSensorView);
    connect(single_group_view, &QAction::triggered, this, &MainView::changeToSingleGroupView);

    //connect(settings_view, &QAction::triggered, this, &MainView::changeToSettingsView);
	connect(opensimulation, &QAction::triggered, this, &MainView::openSimulation);
	connect(exportsimulation, &QAction::triggered, this, &MainView::saveWithName);
    connect(create_sensor, &QAction::triggered, this, &MainView::changeToCreateSensor);
    connect(create_category, &QAction::triggered, this, &MainView::changeToCreateCategory);

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

// Slots
void MainView::emitChangeToModifyView(AbstractItem& item)
{
    emit changeToModifyView(item);
}

SearchBar* MainView::getSearch() const
{
    return searchbar_;
}
