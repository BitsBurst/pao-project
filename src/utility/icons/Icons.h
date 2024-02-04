#ifndef SMARTSENSORS_ICONS_H
#define SMARTSENSORS_ICONS_H

#include <QIcon>
/**
 * @brief Class to get icons
 */
class Icons {
public:
	enum IconType {
		SENSOR,
		CATEGORY,
		SEARCH,
		DELETE_I,
		EDIT,
	};
	static QIcon getIcon(IconType type);
};

#endif //SMARTSENSORS_ICONS_H
