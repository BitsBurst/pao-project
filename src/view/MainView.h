#ifndef SMARTSENSORS_MAINVIEW_H
#define SMARTSENSORS_MAINVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QStackedWidget>
#include "core/AbstractContainer.h"
#include "containers/SidebarContainer.h"
#include "containers/MainContentContainer.h"
#include "views/GroupListView.h"
#include "views/SingleView/SingleView.h"
#include "views/Editor/EditorView.h"
#include "views/SettingsView.h"
#include "views/CreateView.h"
/**
 * @brief MainView is a class that inherits from QMainWindow and is used to display the main view of the application.
 */
class MainView : public QMainWindow {
    Q_OBJECT
signals:
    void changeToSingleSensorView();
    void changeToSingleGroupView();
    void changeToModifyView(AbstractItem& item);
    void changeToCreateCategory();
    void changeToCreateSensor();
    void changeToDefaultView();
	void openSimulation();
	void saveWithName();
private:
    QWidget * central_widget_;
    QLayout * layout_;

    SidebarContainer * sidebar_;
    MainContentContainer * content_;

    QMenuBar * menu_bar_;
    SearchBar * searchbar_;

    void createMenu();

private slots:
    void emitChangeToModifyView(AbstractItem& item);

public:
    explicit MainView(QStackedWidget * content, QStackedWidget * sidebar, QWidget * parent = nullptr);

    void setContentView(int content_id);
    void setSidebarView(int sidebar_id);

    void createDefaultView(int content_id, int sidebar_id);

    SearchBar* getSearch() const;
};

#endif //SMARTSENSORS_MAINVIEW_H
