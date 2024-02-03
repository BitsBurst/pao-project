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
	QPushButton * sensor_filter;
	QPushButton * category_filter;
    SearchType type_;

    void switchButton(int id);

public:
    SearchBar(QWidget * parent = nullptr);
	~SearchBar();

    void searchItem();
};

#endif //SMARTSENSORS_SEARCHBAR_H
