#ifndef SMARTSENSORS_CUSTOMELEMENTS_H
#define SMARTSENSORS_CUSTOMELEMENTS_H

#include <QObject>
#include <QFont>
#include <QSpacerItem>

class CustomElements : QObject {
private:
    static QFont* font_h1_instance_;
    static QFont* font_h2_instance_;
    static QFont* font_h3_instance_;
    static QFont* font_h4_instance_;
    static QFont* font_paragraph_instance_;
    static QFont* font_details_instance_;

public:

    static void Init();

    static QFont& getFontH1();
    static QFont& getFontH2();
    static QFont& getFontH3();
    static QFont& getFontH4();

    static QFont& getFontParagraph();
    static QFont& getFontDetails();

    static QSpacerItem* getTerminalSpacer();

};

#endif //SMARTSENSORS_CUSTOMELEMENTS_H
