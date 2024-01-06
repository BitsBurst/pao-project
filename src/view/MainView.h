#ifndef SMARTSENSORS_MAINVIEW_H
#define SMARTSENSORS_MAINVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenuBar>
#include "../controller/Controller.h"
#include "AbstractContainer.h"
#include "SidebarContainer.h"
#include "MainContentContainer.h"
#include "GroupListView.h"
#include "SingleView.h"
#include "ModifyView.h"

class Controller;

class MainView : public QMainWindow {
    Q_OBJECT
private:
    Controller * controller_;

    QWidget * central_widget_;
    QLayout * layout_;

    AbstractContainer * sidebar_;
    AbstractContainer * content_;

    QMenuBar *menu_bar_;

    // Available Views
    SingleView * single_view_;
    GroupListView * group_list_view_;
    ModifyView * modify_view_;

    void createMenu();
    void createDefaultView();

public:
    explicit MainView(Controller * controller, QWidget * parent = nullptr);

public slots:
    void showSingleView();
    void showModifyView();

};

#endif //SMARTSENSORS_MAINVIEW_H
