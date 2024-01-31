#ifndef SMARTSENSORS_BUSINESSCONTROLLER_H
#define SMARTSENSORS_BUSINESSCONTROLLER_H

#include "../core/AbstractController.h"
#include "../storage/StorageController.h"
#include "../../view/views/AbstractSingleView.h"
#include "../../view/views/GroupListView.h"
#include "../../view/views/Editor/EditorView.h"
#include "../../view/views/CreateView.h"
#include "../../view/views/SettingsView.h"
#include "../../view/views/SingleViewSensor.h"
#include "../../view/MainView.h"
#include "../../view/views/SingleViewGroup.h"

class BusinessController: public AbstractController {
Q_OBJECT
public:
	BusinessController();
	bool Init();
	void Destroy();

    void setDataField(MainView * main_view, QStackedWidget * content_stack, QStackedWidget * sidebar_stack);

private:
    // Available Views
    SingleViewSensor * single_view_sensor_;
    SingleViewGroup * single_view_group_;
    GroupListView * group_list_view_;
    EditorView * editor_view_;
    CreateView * create_view_;
    SettingsView * settings_view_;

    MainView * main_view_;

    // QStackWidget
    QStackedWidget * content_stack_;
    QStackedWidget * sidebar_stack_;

	void subscribeToEvents();
	void loadStorageError();
	void storageReady();

public slots:
    void showSingleSensorView();
    void showSingleGroupView();
    void showModifyView(AbstractItem* item);
    void showCreateView();
    void showCreateCategory();
    void showCreateSensor();
    void showSettingsView();
};

#endif //SMARTSENSORS_BUSINESSCONTROLLER_H
