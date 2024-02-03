#ifndef SMARTSENSORS_BUSINESSCONTROLLER_H
#define SMARTSENSORS_BUSINESSCONTROLLER_H

#include "../core/AbstractController.h"
#include "../storage/StorageController.h"
#include "../../view/views/SingleView/SingleView.h"
#include "../../view/views/GroupListView.h"
#include "../../view/views/Editor/EditorView.h"
#include "../../view/views/CreateView.h"
#include "../../view/views/SettingsView.h"
#include "../../view/widgets/SingleWidget/SingleSensorWidget.h"
#include "../../view/MainView.h"
#include "../../view/widgets/SingleWidget/SingleViewGroup.h"
#include "../../view/views/DefaultView.h"

class BusinessController: public AbstractController {
Q_OBJECT
public:
	BusinessController();
	bool Init();
	void Destroy();

    void setDataField(MainView * main_view, QStackedWidget * content_stack, QStackedWidget * sidebar_stack);

private:
    // Available Views
    SingleView * single_view_;
    DefaultView * default_view_;
    SingleViewGroup * single_view_group_;
    GroupListView * group_list_view_;
    EditorView * editor_view_;
    CreateView * create_view_;
    SettingsView * settings_view_;

    MainView * main_view_;

    // QStackWidget
    QStackedWidget * content_stack_;
    QStackedWidget * sidebar_stack_;

	void unsubscribeToEvents();
	void subscribeToEvents();
	void subscribeToViewEvents(AbstractView*);
	void unsubscribeToViewEvents(AbstractView*);
	void storageReady();

    void deleteInterface();

public slots:
    void showDefaultView();
    void showSingleView(AbstractItem* item);
    void showModifyView(AbstractItem* item);
    void showCreateView();
    void showCreateCategory();
    void showCreateSensor();
	void openSimulation();
	void saveSimulationByName();

    void updateSidebar();
    void showFilteredList(QString query, SearchType type);
    void deleteFromGraphicalElement(AbstractItem* item);
    void addNewItem(AbstractItem* item);

    void cancelOperation();
	void deleteElement(AbstractItem* item);
};

#endif //SMARTSENSORS_BUSINESSCONTROLLER_H
