#ifndef SMARTSENSORS_SETTINGSVIEW_H
#define SMARTSENSORS_SETTINGSVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"

class SettingsView : public AbstractView {
    Q_OBJECT
private:
    QLabel * label1_, *label2_;
public:
    explicit SettingsView(QWidget *parent = nullptr);
    void show();
};


#endif //SMARTSENSORS_SETTINGSVIEW_H
