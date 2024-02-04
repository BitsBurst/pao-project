#include "BusinessController.h"
#include "../LocatorController.h"
#include "../../model/visitor/DeleteItem.h"
#include "../../model/visitor/AddItem.h"
/**
 * @brief BusinessController class
 * @details This class is the controller for the business logic of the application.
 * It is responsible for handling the communication between the views and the storage.
 */
BusinessController::BusinessController():
	single_view_(nullptr),
	editor_view_(nullptr),
	group_list_view_(nullptr),
	default_view_(new DefaultView()),
	main_view_(nullptr),
	content_stack_(nullptr),
	sidebar_stack_(nullptr),
	open_simulation_(nullptr),
	save(nullptr),
	create_sensor_(nullptr),
	create_category_(nullptr)
{}
/**
 * @brief Init function
 * @details This function initializes the BusinessController.
 * @return bool
 */
bool BusinessController::Init()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, "Init BusinessController");
	if(LocatorController::StorageControllerInstance()->isStorageReadyCheck()) {
		storageReady();
	}
	subscribeToEvents();
	return true;
}
/**
 * @brief Subscribe to view events
 * @details This function subscribes to the events of the view.
 * @param o AbstractView*
 */
void BusinessController::subscribeToViewEvents(AbstractView* o) {
	if(typeid(*o) == typeid(EditorView)) {
		connect(editor_view_, &EditorView::modelChanged, this, &BusinessController::updateSidebar);
		connect(editor_view_, &EditorView::addNewItem, this, &BusinessController::addNewItem);
		connect(editor_view_, &EditorView::cancelOperation, this, &BusinessController::cancelOperation);
        connect(editor_view_, &EditorView::changeToSingleView, this, &BusinessController::showSingleView);
	}
	else if(typeid(*o) == typeid(GroupListView)) {
		connect(group_list_view_, &GroupListView::showSingleItem, this, &BusinessController::showSingleView);
		connect(group_list_view_, &GroupListView::changeToModifyView, this, &BusinessController::showModifyView);
		connect(group_list_view_, &GroupListView::deleteItem, this, &BusinessController::deleteFromGraphicalElement);
	} else if(typeid(*o) == typeid(SingleView)) {
		connect(single_view_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
		connect(single_view_, &SingleView::deleteItem, this, &BusinessController::deleteFromGraphicalElement);
	}
	else {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, "Subscribing to unknown view");
	}
}
/**
 * @brief Unsubscribe to view events
 * @details This function unsubscribes to the events of the view.
 * @param o AbstractView*
 */
void BusinessController::unsubscribeToViewEvents(AbstractView* o) {
	if(typeid(*o) == typeid(EditorView)) {
		disconnect(editor_view_, &EditorView::modelChanged, this, &BusinessController::updateSidebar);
		disconnect(editor_view_, &EditorView::addNewItem, this, &BusinessController::addNewItem);
		disconnect(editor_view_, &EditorView::cancelOperation, this, &BusinessController::cancelOperation);
        disconnect(editor_view_, &EditorView::changeToSingleView, this, &BusinessController::showSingleView);
	}
	else if(typeid(*o) == typeid(GroupListView)) {
		disconnect(group_list_view_, &GroupListView::showSingleItem, this, &BusinessController::showSingleView);
		disconnect(group_list_view_, &GroupListView::changeToModifyView, this, &BusinessController::showModifyView);
		disconnect(group_list_view_, &GroupListView::deleteItem, this, &BusinessController::deleteFromGraphicalElement);
	} else if(typeid(*o) == typeid(SingleView)) {
		disconnect(single_view_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
		disconnect(single_view_, &SingleView::deleteItem, this, &BusinessController::deleteFromGraphicalElement);
	} else {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, "Unsubscribing to unknown view");
	}
}
/**
 * @brief Subscribe to events
 * @details This function subscribes to the events of the BusinessController.
 */
void BusinessController::subscribeToEvents()
{
	unsubscribeToEvents();
    LocatorController::StorageControllerInstance()->beforeDestroy.subscribe(std::bind(&BusinessController::deleteInterface, this));
    // Signals
	connect(LocatorController::StorageControllerInstance(), &StorageController::StorageReady, this, &BusinessController::storageReady);
    //connect(main_view_, &MainView::changeToModifyView, this, &BusinessController::showModifyView);
	connect(main_view_, &MainView::openSimulation, this, &BusinessController::openSimulation);
	connect(main_view_, &MainView::saveWithName, this, &BusinessController::saveSimulationByName);
    connect(main_view_, &MainView::changeToCreateCategory, this, &BusinessController::showCreateCategory);
    connect(main_view_, &MainView::changeToCreateSensor, this, &BusinessController::showCreateSensor);
}
/**
 * @brief Unsubscribe to events
 * @details This function unsubscribes to the events of the BusinessController.
 */
void BusinessController::unsubscribeToEvents()
{
	LocatorController::StorageControllerInstance()->beforeDestroy.unsubscribe(std::bind(&BusinessController::deleteInterface, this));
	// Signals
	disconnect(LocatorController::StorageControllerInstance(), &StorageController::StorageReady, this, &BusinessController::storageReady);
	//disconnect(main_view_, &MainView::changeToModifyView, this, &BusinessController::showModifyView);
	disconnect(main_view_, &MainView::openSimulation, this, &BusinessController::openSimulation);
	disconnect(main_view_, &MainView::saveWithName, this, &BusinessController::saveSimulationByName);
	disconnect(main_view_, &MainView::changeToCreateCategory, this, &BusinessController::showCreateCategory);
	disconnect(main_view_, &MainView::changeToCreateSensor, this, &BusinessController::showCreateSensor);
}
/**
 * @brief Set data field
 * @details This function sets the data field of the BusinessController.
 * @param main_view MainView*
 * @param content_stack QStackedWidget*
 * @param sidebar_stack QStackedWidget*
 */
void BusinessController::setDataField(MainView* main_view, QStackedWidget* content_stack, QStackedWidget* sidebar_stack)
{
    main_view_ = main_view;
    content_stack_ = content_stack;
    sidebar_stack_ = sidebar_stack;
    content_stack_->addWidget(default_view_);
	open_simulation_ = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_O), main_view_);
	save = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), main_view_);
	create_sensor_ = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_X), main_view_);
	create_category_ = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_C), main_view_);
}
/**
 * @brief Destroy function
 * @details This function destroys the BusinessController.
 */
void BusinessController::Destroy()
{

}
/**
 * @brief Storage ready
 * @details This function is called when the storage is ready.
 */
void BusinessController::storageReady()
{
	subscribeToShurtcuts();
	subscribeToEvents();
	if(!single_view_){
		single_view_ = new SingleView(new Category());
		subscribeToViewEvents(single_view_);
		content_stack_->addWidget(single_view_);
	}
	if(!editor_view_){
		editor_view_ = new EditorView(new Category(), nullptr);
		subscribeToViewEvents(editor_view_);
		content_stack_->addWidget(editor_view_);
	}
	if(!group_list_view_){
		group_list_view_ = new GroupListView(QVector<AbstractItem*>());
		subscribeToViewEvents(group_list_view_);
		sidebar_stack_->addWidget(group_list_view_);
	}

	main_view_->createDefaultView(
			content_stack_->indexOf(default_view_),
			sidebar_stack_->indexOf(group_list_view_));

	showDefaultView();
	BusinessController::updateSidebar();
	LocatorController::WindowControllerInstance()->setDisabled(false);
}
/**
 * @brief Show default view
 * @details This function shows the default view.
 */
void BusinessController::showDefaultView()
{
    main_view_->setContentView(content_stack_->indexOf(default_view_));
}
/**
 * @brief Show modify view
 * @details This function shows the modify view.
 * @param item AbstractItem*
 */
void BusinessController::showModifyView(AbstractItem* item)
{
    editor_view_->setItem(item);
    editor_view_->setNewObject(false);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
}
/**
 * @brief Show create category
 * @details This function shows the create category view.
 */
void BusinessController::showCreateCategory()
{
	Category* temp = new Category();
    editor_view_->setItem(temp);
    editor_view_->setNewObject(true);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
}
/**
 * @brief Show create sensor
 * @details This function shows the create sensor view.
 */
void BusinessController::showCreateSensor()
{
	Sensor* temp = new Sensor();
    editor_view_->setItem(temp);
    editor_view_->setNewObject(true);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
}
/**
 * @brief Update sidebar
 * @details This function updates the sidebar.
 */
void BusinessController::updateSidebar()
{
    group_list_view_->setItems(LocatorController::StorageControllerInstance()->GetStorage()->getSensors(0));
}
/**
 * @brief Delete element
 * @details This function deletes an element.
 * @param item AbstractItem*
 */
void BusinessController::deleteElement(AbstractItem* item)
{
	DeleteItem delete_item;
	if (static_cast<AbstractView*>(content_stack_->currentWidget())->getItem() == item){
		showDefaultView();
	}
	if (single_view_->getItem() == item) {
		unsubscribeToViewEvents(single_view_);
		content_stack_->removeWidget(single_view_);
		delete single_view_;
		single_view_ = new SingleView(new Category());
		subscribeToViewEvents(single_view_);
		single_view_->setItem(new Category());
		content_stack_->addWidget(single_view_);

	}
	if (editor_view_->getItem() == item) {
		unsubscribeToViewEvents(editor_view_);
		content_stack_->removeWidget(editor_view_);
		delete editor_view_;
		editor_view_ = new EditorView(new Category(), nullptr);
		subscribeToViewEvents(editor_view_);
		editor_view_->setItem(new Category());
		content_stack_->addWidget(editor_view_);

	}
	group_list_view_->deleteListItem(group_list_view_->getGroupItem(item));
	item->accept(delete_item);
}
/**
 * @brief Delete from graphical element
 * @details This function deletes an element from the graphical element.
 * @param item AbstractItem*
 */
void BusinessController::deleteFromGraphicalElement(AbstractItem* item)
{
	if (item == nullptr) return;

	QMessageBox deleteConfirm;
	deleteConfirm.setText("Eliminazione.");
	deleteConfirm.setInformativeText("Sei sicuro di voler procedere con l'eliminazione?");
	deleteConfirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	deleteConfirm.setDefaultButton(QMessageBox::Ok);
	int res = deleteConfirm.exec();

	switch (res) {
	case QMessageBox::Ok:
		deleteElement(item);
		break;
	case QMessageBox::Cancel:
		// Cancel was clicked
		break;
	default:
		// should never be reached
		break;
	}
}

/**
 * @brief Show filtered list
 * @details This function shows the filtered list.
 * @param query QString
 * @param type SearchType
 */
void BusinessController::showFilteredList(QString query, SearchType type)
{
    switch (type) {
    case SENSOR:
        group_list_view_->setItems(LocatorController::StorageControllerInstance()->GetStorage()->filterSensorsByName(query));
        break;
    case CATEGORY:
        group_list_view_->setItems(LocatorController::StorageControllerInstance()->GetStorage()->filterCategoriesByName(query));
        break;
    case ALL:
        group_list_view_->setItems(LocatorController::StorageControllerInstance()->GetStorage()->filterSensorsByName(query));
        break;
    }
}
/**
 * @brief Show single view
 * @details This function shows the single view.
 * @param item AbstractItem*
 */
void BusinessController::showSingleView(AbstractItem* item)
{
    single_view_->setItem(item);
    main_view_->setContentView(content_stack_->indexOf(single_view_));
}

/**
 * @brief Open simulation
 * @details This function opens a simulation.
 */
void BusinessController::openSimulation()
{
	LocatorController::WindowControllerInstance()->setDisabled(true);
	unsubscribeToShurtcuts();
	QString selfilter = tr("JSON (*.json)");
	QString fileName = QFileDialog::getOpenFileName(
			main_view_,
			"Seleziona un file di una simulazione",
			QDir::homePath(),
			tr("JSON (*.json );; All files (*.*)" ),
			&selfilter
	);
	if (!fileName.isEmpty()) {
		LocatorController::StorageControllerInstance()->changeStorageFile(fileName);
		LocatorController::WindowControllerInstance()->setTitle("SmartSensors - " + fileName);
	} else {
		subscribeToShurtcuts();
		Logger::Log(LogLevel::_WARNING_, __FILE__, __LINE__, __FUNCTION__, "No file selected");
	}
	LocatorController::WindowControllerInstance()->setDisabled(false);
}
/**
 * @brief Save simulation by name
 * @details This function saves a simulation by name.
 */
void BusinessController::saveSimulationByName()
{
	LocatorController::WindowControllerInstance()->setDisabled(true);
	unsubscribeToShurtcuts();
	QString selfilter = tr("JSON (*.json)");
	QString fileName = QFileDialog::getSaveFileName(
			main_view_,
			"Salva un file di una simulazione con nome",
			QDir::homePath()+QString("/simulazione_%1.json").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss")),
			tr("JSON (*.json )" ),
			&selfilter
	);
	if (!fileName.isEmpty()) {
		LocatorController::StorageControllerInstance()->saveStorageByName(fileName);
	} else {
		Logger::Log(LogLevel::_WARNING_, __FILE__, __LINE__, __FUNCTION__, "No file name selected");
	}
	subscribeToShurtcuts();
	LocatorController::WindowControllerInstance()->setDisabled(false);
}
/**
 * @brief Cancel operation
 * @details This function cancels an operation.
 */
void BusinessController::cancelOperation()
{
    QMessageBox cancelConfirm;
    cancelConfirm.setText("Annulla Operazioni");
    cancelConfirm.setInformativeText("Sei sicuro di voler procedere? Non sarà possibile recuperare le modifiche attuate.");
    cancelConfirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    cancelConfirm.setDefaultButton(QMessageBox::Ok);
    int res = cancelConfirm.exec();

    switch (res) {
    case QMessageBox::Ok:
        showDefaultView();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        break;
    default:
        // should never be reached
        break;
    }
}
/**
 * @brief Delete interface
 * @details This function deletes the interface.
 */
void BusinessController::deleteInterface()
{
    main_view_->setContentView(content_stack_->indexOf(default_view_));
    main_view_->setSidebarView(content_stack_->indexOf(default_view_));

    content_stack_->removeWidget(single_view_);
    content_stack_->removeWidget(editor_view_);

    sidebar_stack_->removeWidget(group_list_view_);
	unsubscribeToViewEvents(single_view_);
    delete single_view_;
	single_view_ = nullptr;
	unsubscribeToViewEvents(editor_view_);
    delete editor_view_;
	editor_view_ = nullptr;
	unsubscribeToViewEvents(group_list_view_);
    delete group_list_view_;
	group_list_view_ = nullptr;
}
/**
 * @brief Add new item
 * @details This function adds a new item.
 * @param item AbstractItem*
 */
void BusinessController::addNewItem(AbstractItem* item)
{
    AddItem add_item;
    item->accept(add_item);

    main_view_->getSearch()->searchItem();
}
/**
 * @brief Subscribe to shurtcuts
 * @details This function subscribes to the shurtcuts.
 */
void BusinessController::subscribeToShurtcuts()
{
	connect(open_simulation_, &QShortcut::activated, this, &BusinessController::openSimulation);
	connect(save, &QShortcut::activated, this, &BusinessController::saveSimulationByName);
	connect(create_sensor_, &QShortcut::activated, this, &BusinessController::showCreateSensor);
	connect(create_category_, &QShortcut::activated, this, &BusinessController::showCreateCategory);
}
/**
 * @brief Unsubscribe to shurtcuts
 * @details This function unsubscribes to the shurtcuts.
 */
void BusinessController::unsubscribeToShurtcuts()
{
	disconnect(open_simulation_, &QShortcut::activated, this, &BusinessController::openSimulation);
	disconnect(save, &QShortcut::activated, this, &BusinessController::saveSimulationByName);
	disconnect(create_sensor_, &QShortcut::activated, this, &BusinessController::showCreateSensor);
	disconnect(create_category_, &QShortcut::activated, this, &BusinessController::showCreateCategory);
}
