#ifndef SMARTSENSORS_SIDEBARCONTAINER_H
#define SMARTSENSORS_SIDEBARCONTAINER_H

#include <QLabel>
#include "../core/AbstractContainer.h"
#include "../widgets/SidebarLowControlWidget.h"
#include "../widgets/SearchBar.h"
/**
 * @brief The SidebarContainer class
 */
class SidebarContainer : public AbstractContainer {
    Q_OBJECT
signals:
    void createSensor();
    void createCategory();
    
private:
    SidebarLowControlWidget * low_control_widget_;
    SearchBar* search_bar_;

public:
    explicit SidebarContainer(QStackedWidget * current_view = new QStackedWidget,QWidget * parent = nullptr);

    SearchBar* getSearch() const;
};

#endif //SMARTSENSORS_SIDEBARCONTAINER_H
