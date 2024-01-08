#ifndef SMARTSENSORS_MAINVIEW_H
#define SMARTSENSORS_MAINVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenuBar>
#include "core/AbstractContainer.h"
#include "containers/SidebarContainer.h"
#include "containers/MainContentContainer.h"
#include "views/GroupListView.h"
#include "views/SingleView.h"
#include "views/ModifyView.h"
#include "views/SettingsView.h"
#include "views/CreateView.h"

class MainView : public QMainWindow {
    Q_OBJECT
private:
    QWidget * central_widget_;
    QLayout * layout_;

    AbstractContainer * sidebar_;
    AbstractContainer * content_;

    QMenuBar *menu_bar_;

    // Available Views
    SingleView * single_view_;
    GroupListView * group_list_view_;
    /*
    ModifyView * modify_view_;
    CreateView * create_view_;
    SettingsView * settings_view_;
    */


    void createMenu();
    void createDefaultView();

public:
    explicit MainView(QWidget * parent = nullptr);

public slots:
    void showSingleView();
    /*
    void showModifyView();
    void showCreateView();
    void showSettingsView();
    */
};

#endif //SMARTSENSORS_MAINVIEW_H
