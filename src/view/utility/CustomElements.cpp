#include <QFontDatabase>
#include "CustomElements.h"
#include "../../utility/Logger.h"

QFont* CustomElements::getFontH1()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(60);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setWeight(QFont::Normal);

    return font;
}

QFont* CustomElements::getFontH2()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(32);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setWeight(QFont::Normal);;

    return font;
}

QFont* CustomElements::getFontH3()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(24);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setWeight(QFont::Normal);

    return font;
}

QFont* CustomElements::getFontH4()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(18);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setWeight(QFont::Normal);

    return font;
}

QFont* CustomElements::getFontParagraph()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(16);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setWeight(QFont::Light);

    return font;
}

QFont* CustomElements::getFontDetails()
{
    QFont * font = new QFont();
    font->setFamily("roboto");
    font->setPointSize(8);
    font->setWeight(QFont::Medium);
    font->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
    font->setLetterSpacing(QFont::AbsoluteSpacing, 1);
    font->setCapitalization(QFont::AllUppercase);

    return font;
}

QSpacerItem* CustomElements::getTerminalSpacer()
{
    return new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
}

void CustomElements::Init()
{
    QFontDatabase::addApplicationFont(":/roboto-black.ttf");
    QFontDatabase::addApplicationFont(":/roboto-bold.ttf");
    QFontDatabase::addApplicationFont(":/roboto-light.ttf");
    QFontDatabase::addApplicationFont(":/roboto-medium.ttf");
    QFontDatabase::addApplicationFont(":/roboto-regular.ttf");
    QFontDatabase::addApplicationFont(":/roboto-thin.ttf");
}
