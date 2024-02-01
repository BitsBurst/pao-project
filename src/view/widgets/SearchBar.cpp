#include "SearchBar.h"
#include "../../controller/LocatorController.h"

SearchBar::SearchBar(QWidget * parent)
    : AbstractWidget(new QFormLayout, parent)
{
    searchbar_ = new QLineEdit("", this);
    search_btn_ = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_search), "");

    QLayout* row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
    row->addWidget(searchbar_);
    row->addWidget(search_btn_);

    layout_->setContentsMargins(0, 8, 0, 8);
    static_cast<QFormLayout*>(layout_)->addRow(row);

    connect(search_btn_, &QPushButton::released, this, &SearchBar::searchItem);
    connect(searchbar_, &QLineEdit::textChanged, this, &SearchBar::searchItem);
}

void SearchBar::searchItem()
{
    LocatorController::BusinessControllerInstance()->showFilteredList(searchbar_->text());
}
