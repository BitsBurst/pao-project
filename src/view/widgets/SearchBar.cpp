#include "SearchBar.h"
#include "../../controller/LocatorController.h"
#include "../../utility/icons/Icons.h"
/**
 * @brief SearchBar::SearchBar
 * @param parent
 */
SearchBar::SearchBar(QWidget * parent)
    :
	AbstractWidget(new QFormLayout, parent),
	searchbar_(new QLineEdit("", this)),
	search_btn_(new QPushButton(Icons::getIcon(Icons::IconType::SEARCH), "", this)),
	btn_group_(new QButtonGroup(this)),
	sensor_filter(new QPushButton(Icons::getIcon(Icons::IconType::SENSOR), "", this)),
	category_filter(new QPushButton(Icons::getIcon(Icons::IconType::CATEGORY), "", this)),
	type_(ALL)
{
	sensor_filter->setCheckable(true);
	category_filter->setCheckable(true);
	sensor_filter->setChecked(true);
    QLayout* row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
    row->addWidget(searchbar_);
    row->addWidget(search_btn_);

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
/**
 * @brief SearchBar::searchItem
 */
void SearchBar::searchItem()
{
    LocatorController::BusinessControllerInstance()->showFilteredList(searchbar_->text(), type_);
}
/**
 * @brief SearchBar::switchButton
 * @param id
 */
void SearchBar::switchButton(int id)
{
    type_ = static_cast<SearchType>(id);
	switch (type_)
	{
	case SENSOR:
		category_filter->setChecked(false);
		sensor_filter->setChecked(true);
		break;
	case CATEGORY:
		sensor_filter->setChecked(false);
		category_filter->setChecked(true);
		break;
	case ALL:
		sensor_filter->setChecked(true);
		category_filter->setChecked(true);
	break;
	}
    searchItem();
}
/**
 * @brief SearchBar::~SearchBar
 */
SearchBar::~SearchBar()
{

}
