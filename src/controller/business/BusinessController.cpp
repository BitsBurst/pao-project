#include "BusinessController.h"
#include "../LocatorController.h"

BusinessController::BusinessController()
{
    // Initialization - Views
    Category temp;
    single_view_ = new SingleView(new Category("Default Item", "KM"));
    // single_view_group_ = new SingleViewGroup(QVector<Sensor *>());
    editor_view_ = new EditorView(new Sensor("Editor", temp));


    create_view_ = new CreateView();
    settings_view_ = new SettingsView();

    /*QVector<AbstractItem *> list;
    for (int i = 0; i < 2; ++i) {
        list.push_back(new Sensor(QString::fromStdString("Sensor " + std::to_string(i)), Category(QString::fromStdString("Cat " + std::to_string(i)), "KM")));
        list.push_back(new Category(QString::fromStdString("Cat " + std::to_string(i)), "KM"));
    }
*/
	group_list_view_ = new GroupListView(LocatorController::StorageControllerInstance()->GetStorage()->getSensors(0));
}

bool BusinessController::Init()
{
	subscribeToEvents();
	if(LocatorController::StorageControllerInstance()->isStorageReadyCheck()) {
		storageReady();
	}
    main_view_->createDefaultView(content_stack_->indexOf(single_view_), sidebar_stack_->indexOf(group_list_view_));

	return true;
}
void BusinessController::subscribeToEvents()
{
	connect(LocatorController::StorageControllerInstance(), &StorageController::StorageReady, this, &BusinessController::storageReady);
    connect(main_view_, &MainView::changeToSingleSensorView, this, &BusinessController::showSingleSensorView);
    connect(main_view_, &MainView::changeToSingleGroupView, this, &BusinessController::showSingleGroupView);
    connect(main_view_, &MainView::changeToCreateView, this, &BusinessController::showCreateView);
    //connect(main_view_, &MainView::changeToModifyView, this, &BusinessController::showModifyView);
    connect(main_view_, &MainView::changeToSettingsView, this, &BusinessController::showSettingsView);

    // Modify
    connect(single_view_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
    // connect(single_view_group_, &SingleView::changeToModifyView, this, &BusinessController::showModifyView);
    connect(group_list_view_, &GroupListView::changeToModifyView, this, &BusinessController::showModifyView);

    // Create
    connect(main_view_, &MainView::changeToCreateCategory, this, &BusinessController::showCreateCategory);
    connect(main_view_, &MainView::changeToCreateSensor, this, &BusinessController::showCreateSensor);

	//connect(editor_view_, &EditorView::applyChanges, this, &BusinessController::editItem);

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

    sidebar_stack_->addWidget(group_list_view_);
}

void BusinessController::Destroy()
{

}
void BusinessController::storageReady()
{
	LocatorController::WindowControllerInstance()->setDisabled(false);
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
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
}

void BusinessController::editItem(AbstractItem* item)
{

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
    editor_view_->setActiveForm(1);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
	LocatorController::StorageControllerInstance()->GetStorage()->addCategory(temp);
}

void BusinessController::showCreateSensor()
{
	Sensor* temp = new Sensor();
    editor_view_->setItem(nullptr);
    editor_view_->setActiveForm(0);
    main_view_->setContentView(content_stack_->indexOf(editor_view_));
	LocatorController::StorageControllerInstance()->GetStorage()->addSensor(temp);
}
