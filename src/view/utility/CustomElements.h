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

    static const QFont& getFontH1();
    static const QFont& getFontH2();
    static const QFont& getFontH3();
    static const QFont& getFontH4();

    static const QFont& getFontParagraph();
    static const QFont& getFontDetails();

    static QSpacerItem* getTerminalSpacer();

};

#endif //SMARTSENSORS_CUSTOMELEMENTS_H
