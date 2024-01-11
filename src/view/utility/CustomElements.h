#ifndef SMARTSENSORS_CUSTOMELEMENTS_H
#define SMARTSENSORS_CUSTOMELEMENTS_H

#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QFont>
#include <QSpacerItem>

enum LayoutPrototype {H_NO_BORDER, V_CONTAINER, SINGLE_SPACING, DOUBLE_SPACING, QUAD_SPACING};
enum SpacerDirection {VERTICAL, HORIZONTAL};

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

    static QSpacerItem* getTerminalSpacer(SpacerDirection direction = VERTICAL);

    static QVBoxLayout* getVerticalLayout(int margins = 0);
    static QVBoxLayout* getVerticalLayout(int h_margin, int v_margin);
    static QVBoxLayout* getVerticalLayout(int left_margin, int right_margin, int top_margin, int bottom_margin);

    static QHBoxLayout* getHorizontalLayout(int margins = 0);
    static QHBoxLayout* getHorizontalLayout(int h_margin, int v_margin);
    static QHBoxLayout* getHorizontalLayout(int left_margin, int right_margin, int top_margin, int bottom_margin);

    static QLayout* getCustomLayoutPrototype(LayoutPrototype);
};

#endif //SMARTSENSORS_CUSTOMELEMENTS_H
