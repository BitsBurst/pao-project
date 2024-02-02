#ifndef SMARTSENSORS_SEARCHBAR_H
#define SMARTSENSORS_SEARCHBAR_H

#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include "../core/AbstractWidget.h"
#include "../utility/CustomElements.h"

enum SearchType { SENSOR, CATEGORY, ALL };

class SearchBar : public AbstractWidget {
    Q_OBJECT

private:
    QLineEdit* searchbar_;
    QPushButton* search_btn_;
    QButtonGroup * btn_group_;
    SearchType type_;

    void searchItem();
    void switchButton(int id);

public:
    SearchBar(QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_SEARCHBAR_H
