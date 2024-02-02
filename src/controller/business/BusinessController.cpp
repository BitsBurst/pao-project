#include "BusinessController.h"
#include "../LocatorController.h"
#include "../../model/visitor/DeleteItem.h"

BusinessController::BusinessController()
{
    single_view_ = new SingleView(new Category());
    editor_view_ = new EditorView(new Sensor());
    default_view_ = new DefaultView();
    create_view_ = new CreateView();
    settings_view_ = new SettingsView();
	group_list_view_ = new GroupListView(LocatorController::StorageControllerInstance()->GetStorage()->getSensors(0));
}

bool BusinessController::Init()
{
	if(LocatorController::StorageControllerInstance()->isStorageReadyCheck()) {
		storageReady();
	}
	return true;
}
void BusinessController::subscribeToEvents()
{
    LocatorController::StorageControllerInstance()->beforeDestroy.subscribe(std::bind(&BusinessController::deleteInterface, this));

    // Signals
	connect(LocatorController::StorageControllerInstance(), &StorageController::StorageReady, this, &BusinessController::storageReady);

    connect(main_view_, &MainView::changeToSingleSensorView, this, &BusinessController::showSingleSensorView);
    connect(main_view_, &MainView::changeToSingleGroupView, this, &BusinessController::showSingleGroupView);
    connect(main_view_, &MainView::changeToCreateView, this, &BusinessController::showCreateView);
    //connect(main_view_, &MainView::changeToModifyView, this, &BusinessController::showModifyView);
    connect(main_view_, &MainView::changeToSettingsView, this, &BusinessController::showSettingsView);
    connect(group_list_view_, &GroupListView::showSingleItem, this, &BusinessController::showSingleView);
	connect(main_view_, &MainView::openSimulation, this, &BusinessController::openSimulation);
	connect(main_view_, &MainView::saveWithName, this, &BusinessController::saveSimulationByName);

    connect(editor_view_, &EditorView::cancelOperation, this, &BusinessController::cancelOperation);

    // Modify
    connect(single_view_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
    // connect(single_view_group_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
    connect(group_list_view_, &GroupListView::changeToModifyView, this, &BusinessController::showModifyView);

    // Create
    connect(main_view_, &MainView::changeToCreateCategory, this, &BusinessController::showCreateCategory);
    connect(main_view_, &MainView::changeToCreateSensor, this, &BusinessController::showCreateSensor);

    // Delete
    connect(group_list_view_, &GroupListView::deleteItem, this, &BusinessController::deleteItem);
	//connect(single_view_, &SingleView::deleteItem, this, &BusinessController::deleteItem);

    // Update Model
    connect(editor_view_, &EditorView::modelChanged, this, &BusinessController::updateSidebar);
    connect(editor_view_, &EditorView::addNewItem, [this] { main_view_->getSearch()->searchItem(); });
}

void BusinessController::setDataField(MainView* main_view, QStackedWidget* content_stack, QStackedWidget* sidebar_stack)
{
    main_view_ = main_view;
    content_stack_ = content_stack;
    sidebar_stack_ = sidebar_stack;

    // Create Stack
    content_stack_->addWidget(single_view_);
    // content_stack_->addWidget(single_view_group_);
    content_stack_->addWidget(editor_view_);
    content_stack_->addWidget(create_view_);
    content_stack_->addWidget(settings_view_);
    content_stack_->addWidget(default_view_);

    sidebar_stack_->addWidget(group_list_view_);
}

void BusinessController::Destroy()
{

}
void BusinessController::storageReady()
{
	if(!single_view_)
	single_view_ = new SingleView(new Category());
	if(!editor_view_)
	editor_view_ = new EditorView(new Category());
	if(!group_list_view_)
	group_list_view_ = new GroupListView(QVector<AbstractItem*>());

	content_stack_->addWidget(single_view_);
	content_stack_->addWidget(editor_view_);

	sidebar_stack_->addWidget(group_list_view_);
	subscribeToEvents();

	main_view_->createDefaultView(
			content_stack_->indexOf(default_view_),
			sidebar_stack_->indexOf(group_list_view_));
	showDefaultView();
	BusinessController::updateSidebar();
	LocatorController::WindowControllerInstance()->setDisabled(false);
}

void BusinessController::showDefaultView()
{
    main_view_->setContentView(content_stack_->indexOf(default_view_));
}

void BusinessController::showSingleSensorView()
{
    main_view_->setContentView(content_stack_->indexOf(single_view_));
}

void BusinessController::showSingleGroupView()
{
    QVector<Sensor *> list;
    for (int i = 0; i < 4; ++i) {
        list.push_back(new Sensor(QString::fromStdString("Sensor " + std::to_string(i)), Category()));
    }

    // single_view_group_->setSensors(list);

    // main_view_->setContentView(content_stack_->indexOf(single_view_group_));
}

void BusinessController::showModifyView(AbstractItem* item)
{
    editor_view_->setItem(item);
    editor_view_->setNewObject(false);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
}

void BusinessController::showCreateView()
{
    main_view_->setContentView(content_stack_->indexOf(create_view_));
}

void BusinessController::showSettingsView()
{
    main_view_->setContentView(content_stack_->indexOf(settings_view_));
}

void BusinessController::showCreateCategory()
{
	Category* temp = new Category();
    editor_view_->setItem(temp);
    editor_view_->setNewObject(true);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
	LocatorController::StorageControllerInstance()->GetStorage()->addCategory(temp);
}

void BusinessController::showCreateSensor()
{
	Sensor* temp = new Sensor();
    editor_view_->setItem(temp);
    editor_view_->setNewObject(true);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
	LocatorController::StorageControllerInstance()->GetStorage()->addSensor(temp);
}

void BusinessController::updateSidebar()
{
    group_list_view_->setItems(LocatorController::StorageControllerInstance()->GetStorage()->getSensors(0));
}

void BusinessController::deleteItem(GroupItemWidget* item)
{
	if (item == nullptr) return;

	QMessageBox deleteConfirm;
	deleteConfirm.setText("Eliminazione.");
	deleteConfirm.setInformativeText("Sei sicuro di voler procedere con l'eliminazione?");
	deleteConfirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	deleteConfirm.setDefaultButton(QMessageBox::Ok);
	int res = deleteConfirm.exec();

	DeleteItem delete_item;
	AbstractItem* item_ = item->getItem();
	switch (res) {
	case QMessageBox::Ok:
        group_list_view_->deleteListItem(item);
		item_->accept(delete_item);
		break;
	case QMessageBox::Cancel:
		// Cancel was clicked
		break;
	default:
		// should never be reached
		break;
	}
}

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

void BusinessController::showSingleView(AbstractItem* item)
{
    single_view_->setItem(item);
    main_view_->setContentView(content_stack_->indexOf(single_view_));
}


void BusinessController::openSimulation()
{
	LocatorController::WindowControllerInstance()->setDisabled(true);
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
		Logger::Log(LogLevel::_WARNING_, __FILE__, __LINE__, __FUNCTION__, "No file selected");
	}
	LocatorController::WindowControllerInstance()->setDisabled(false);
}

void BusinessController::saveSimulationByName()
{
	LocatorController::WindowControllerInstance()->setDisabled(true);
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
	LocatorController::WindowControllerInstance()->setDisabled(false);
}

void BusinessController::cancelOperation()
{
    QMessageBox cancelConfirm;
    cancelConfirm.setText("Annulla Operazioni");
    cancelConfirm.setInformativeText("Sei sicuro di voler procedere? Non sarà possibile recuperare le modifiche attuate.");
    cancelConfirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    cancelConfirm.setDefaultButton(QMessageBox::Ok);
    int res = cancelConfirm.exec();

    DeleteItem delete_item;

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

void BusinessController::deleteInterface()
{
    main_view_->setContentView(content_stack_->indexOf(default_view_));
    main_view_->setSidebarView(content_stack_->indexOf(default_view_));

    content_stack_->removeWidget(single_view_);
    content_stack_->removeWidget(editor_view_);

    sidebar_stack_->removeWidget(group_list_view_);

    delete single_view_;
	single_view_ = nullptr;
    delete editor_view_;
	editor_view_ = nullptr;
    delete group_list_view_;
	group_list_view_ = nullptr;
}
