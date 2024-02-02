#include "SearchBar.h"
#include "../../controller/LocatorController.h"

SearchBar::SearchBar(QWidget * parent)
    : AbstractWidget(new QFormLayout, parent), type_(ALL)
{
    searchbar_ = new QLineEdit("", this);
    search_btn_ = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_search), "");

    QPushButton * sensor_filter = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_chart_line), "");
    QPushButton * category_filter = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_list), "");

    QLayout* row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
    row->addWidget(searchbar_);
    row->addWidget(search_btn_);

    btn_group_ = new QButtonGroup(this);
    btn_group_->addButton(sensor_filter, 0);
    btn_group_->addButton(category_filter, 1);

    QLayout* row_btn_layout = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
    row_btn_layout->addWidget(sensor_filter);
    row_btn_layout->addWidget(category_filter);

    layout_->setContentsMargins(0, 8, 0, 8);
    static_cast<QFormLayout*>(layout_)->addRow(row);
    static_cast<QFormLayout*>(layout_)->addRow(row_btn_layout);

    connect(search_btn_, &QPushButton::released, this, &SearchBar::searchItem);
    connect(searchbar_, &QLineEdit::textChanged, this, &SearchBar::searchItem);

    connect(btn_group_, &QButtonGroup::idReleased, this, &SearchBar::switchButton );
}

void SearchBar::searchItem()
{
    LocatorController::BusinessControllerInstance()->showFilteredList(searchbar_->text(), type_);
}

void SearchBar::switchButton(int id)
{
    type_ = static_cast<SearchType>(id);
    searchItem();
}

SearchBar::~SearchBar()
{

}
