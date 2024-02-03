#ifndef SMARTSENSORS_ICONS_H
#define SMARTSENSORS_ICONS_H

#include <QIcon>
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
