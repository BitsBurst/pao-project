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
#include "views/AbstractSingleView.h"
#include "views/Editor/EditorView.h"
#include "views/SettingsView.h"
#include "views/CreateView.h"

class MainView : public QMainWindow {
    Q_OBJECT
signals:
    void changeToSingleSensorView();
    void changeToSingleGroupView();
    void changeToModifyView(AbstractItem& item);
    void changeToCreateView();
    void changeToSettingsView();
    void changeToCreateCategory();

private:
    QWidget * central_widget_;
    QLayout * layout_;

    AbstractContainer * sidebar_;
    AbstractContainer * content_;

    QMenuBar * menu_bar_;

    void createMenu();

private slots:
    void emitChangeToModifyView(AbstractItem& item);

public:
    explicit MainView(QStackedWidget * content, QStackedWidget * sidebar, QWidget * parent = nullptr);

    void setContentView(int content_id);
    void setSidebarView(int sidebar_id);

    void createDefaultView(int content_id, int sidebar_id);

};

#endif //SMARTSENSORS_MAINVIEW_H
