#include "Icons.h"
/**
 * @brief Get the icon based on the type
 * @param type Icon type
 * @return Icon
 */
QIcon Icons::getIcon(Icons::IconType type)
{
	QIcon icon;
	switch (type)
	{
	case SENSOR:
		icon = QIcon(":/icons/chart.svg");
		break;
	case CATEGORY:
		icon = QIcon(":/icons/list.svg");
		break;
	case SEARCH:
		icon = QIcon(":/icons/search.svg");
		break;
	case DELETE_I:
		icon = QIcon(":/icons/trash.svg");
		break;
	case EDIT:
		icon = QIcon(":/icons/pencil.svg");
		break;
	default:
		icon = QIcon();
		break;
	}
	return icon;
}
