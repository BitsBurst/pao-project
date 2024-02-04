#include "MainView.h"
#include "widgets/SingleWidget/SingleSensorWidget.h"
/**
 * @brief MainView::MainView is the constructor of the class.
 * @param content is the content widget of the view.
 * @param sidebar is the sidebar widget of the view.
 * @param parent is the parent widget of the view.
 */
MainView::MainView(QStackedWidget * content, QStackedWidget * sidebar, QWidget* parent)
    : QMainWindow(parent), central_widget_(new QWidget), layout_(CustomElements::getCustomLayoutPrototype(H_NO_BORDER))
{
    // General Settings
    setMinimumSize(QSize(640, 360));
	QSize size = qApp->screens()[0]->size();
	resize(QSize(size.width()*0.5, size.height()*0.5));
	setScreen(qApp->screens()[0]);

	setWindowIcon(QIcon(":/icons/logo.jpg"));

	// Initialization
    content_ = new MainContentContainer(content, this);
    sidebar_ = new SidebarContainer(sidebar, this);
    searchbar_ = sidebar_->getSearch();

    // Creation Calls
    createMenu();

    // Layout Widgets
    layout_->addWidget(sidebar_);
    layout_->addWidget(content_);

    // Central Widget
    central_widget_->setLayout(layout_);
    central_widget_->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    setCentralWidget(central_widget_);

    connect(sidebar_, &SidebarContainer::createSensor, this, &MainView::changeToCreateSensor);
    connect(sidebar_, &SidebarContainer::createCategory, this, &MainView::changeToCreateCategory);
}
/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
void MainView::createMenu() {

    // Initialization
    menu_bar_ = new QMenuBar(this);

    // Menu Bar
    QMenu * file = new QMenu("File", menu_bar_);
    QMenu * sensors = new QMenu("Sensori", menu_bar_);
    QMenu * categories = new QMenu("Categorie", menu_bar_);
    QMenu * help = new QMenu("Help", menu_bar_);
    menu_bar_->addMenu(file);
    menu_bar_->addMenu(sensors);
    menu_bar_->addMenu(categories);
    menu_bar_->addMenu(help);

    // Menu Sensors
    QAction * create_sensor = new QAction("Crea", sensors);

    sensors->addAction(create_sensor);

    // Menu File
    QAction * opensimulation = new QAction("Apri file simulazione", file);
	QAction * exportsimulation = new QAction("Esporta file simulazione", file);

    file->addAction(opensimulation);
	file->addAction(exportsimulation);

    // Menu Categories
    QAction * create_category = new QAction("Crea", categories);

    categories->addAction(create_category);

    // Menu Categories
    QAction * show_default = new QAction("Mostra Shortcut", help);

    help->addAction(show_default);

    // Connect Action
	connect(opensimulation, &QAction::triggered, this, &MainView::openSimulation);
	connect(exportsimulation, &QAction::triggered, this, &MainView::saveWithName);
    connect(create_sensor, &QAction::triggered, this, &MainView::changeToCreateSensor);
    connect(create_category, &QAction::triggered, this, &MainView::changeToCreateCategory);
    connect(show_default, &QAction::triggered, this, &MainView::changeToDefaultView);

    setMenuBar(menu_bar_);
}
/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
void MainView::createDefaultView(int content_id, int sidebar_id) {
    content_->setCurrentView(content_id);
    sidebar_->setCurrentView(sidebar_id);
}

/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
void MainView::setContentView(int content_id)
{
	if(content_->getCurrentView() == content_id) {
		return;
	}
    content_->setCurrentView(content_id);
}
/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
void MainView::setSidebarView(int sidebar_id)
{
    sidebar_->setCurrentView(sidebar_id);
}

// Slots
/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
void MainView::emitChangeToModifyView(AbstractItem& item)
{
    emit changeToModifyView(item);
}
/**
 * @brief MainView::changeToSingleSensorView is a slot that is used to change the view to the single sensor view.
 */
SearchBar* MainView::getSearch() const
{
    return searchbar_;
}
