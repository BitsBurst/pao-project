#ifndef SMARTSENSORS_SETTINGSVIEW_H
#define SMARTSENSORS_SETTINGSVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"

class SettingsView : public AbstractView {
    Q_OBJECT
private:
    QLabel * label1_, *label2_;
public:
    explicit SettingsView(QLayout * layout = nullptr, QWidget *parent = nullptr);
    void show();
};


#endif //SMARTSENSORS_SETTINGSVIEW_H
