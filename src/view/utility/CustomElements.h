#ifndef SMARTSENSORS_CUSTOMELEMENTS_H
#define SMARTSENSORS_CUSTOMELEMENTS_H

#include <QObject>
#include <QFont>
#include <QSpacerItem>

class CustomElements : QObject {
public:

    static void Init();

    static QFont* getFontH1();
    static QFont* getFontH2();
    static QFont* getFontH3();
    static QFont* getFontH4();

    static QFont* getFontParagraph();
    static QFont* getFontDetails();

    static QSpacerItem* getTerminalSpacer();

};

#endif //SMARTSENSORS_CUSTOMELEMENTS_H
