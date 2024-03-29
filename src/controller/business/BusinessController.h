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
/**
 * @brief BusinessController class
 * @details This class is the controller for the business logic of the application.
 * It is responsible for handling the communication between the views and the storage.
 */
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
    EditorView * editor_view_;
    GroupListView * group_list_view_;
    DefaultView * default_view_;

    MainView * main_view_;

    // QStackWidget
    QStackedWidget * content_stack_;
    QStackedWidget * sidebar_stack_;

	// Shurtcuts
	QShortcut *open_simulation_;
	QShortcut *save;
	QShortcut *create_sensor_;
	QShortcut *create_category_;

	void unsubscribeToEvents();
	void subscribeToEvents();
	void subscribeToViewEvents(AbstractView*);
	void unsubscribeToViewEvents(AbstractView*);
	void storageReady();
	void subscribeToShurtcuts();
	void unsubscribeToShurtcuts();

    void deleteInterface();

public slots:
    void showDefaultView();
    void showSingleView(AbstractItem* item);
    void showModifyView(AbstractItem* item);
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
