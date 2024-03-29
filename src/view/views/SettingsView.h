#ifndef SMARTSENSORS_SETTINGSVIEW_H
#define SMARTSENSORS_SETTINGSVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"
/**
 * @brief SettingsView is a class that inherits from AbstractView and is used to display the settings view of the application.
 */
class SettingsView : public AbstractView {
    Q_OBJECT
private:
    QLabel * label1_, *label2_;
public:
    explicit SettingsView(QWidget *parent = nullptr);
};


#endif //SMARTSENSORS_SETTINGSVIEW_H
