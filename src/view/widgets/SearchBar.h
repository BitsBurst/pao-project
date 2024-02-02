#ifndef SMARTSENSORS_SEARCHBAR_H
#define SMARTSENSORS_SEARCHBAR_H

#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include "../core/AbstractWidget.h"
#include "../utility/CustomElements.h"

class SearchBar : public AbstractWidget {
    Q_OBJECT

private:
    QLineEdit* searchbar_;
    QPushButton* search_btn_;

    void searchItem();

public:
    SearchBar(QWidget * parent = nullptr);
	~SearchBar();
};

#endif //SMARTSENSORS_SEARCHBAR_H
