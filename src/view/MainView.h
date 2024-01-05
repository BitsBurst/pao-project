#ifndef SMARTSENSORS_MAINVIEW_H
#define SMARTSENSORS_MAINVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenuBar>
#include "../controller/Controller.h"
#include "AbstractContainer.h"
#include "SidebarWidget.h"
#include "MainContentWidget.h"

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

    void createMenu();

public:
    explicit MainView(Controller * controller, QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_MAINVIEW_H
