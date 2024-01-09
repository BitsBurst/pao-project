#include <QFontDatabase>
#include "CustomElements.h"
#include "../../utility/Logger.h"

// Initialization
QFont *CustomElements::font_h1_instance_ = nullptr;
QFont *CustomElements::font_h2_instance_ = nullptr;
QFont *CustomElements::font_h3_instance_ = nullptr;
QFont *CustomElements::font_h4_instance_ = nullptr;
QFont *CustomElements::font_paragraph_instance_ = nullptr;
QFont *CustomElements::font_details_instance_ = nullptr;

const QFont& CustomElements::getFontH1()
{
    if (font_h1_instance_ == nullptr)
    {
        font_h1_instance_ = new QFont();
        font_h1_instance_->setFamily("roboto");
        font_h1_instance_->setPointSize(60);
        font_h1_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h1_instance_->setWeight(QFont::Normal);
    }

    return const_cast<QFont&>(*font_h1_instance_);
}

const QFont& CustomElements::getFontH2()
{
    if (font_h2_instance_ == nullptr)
    {
        font_h2_instance_ = new QFont();
        font_h2_instance_->setFamily("roboto");
        font_h2_instance_->setPointSize(32);
        font_h2_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h2_instance_->setWeight(QFont::Normal);
    }

    return const_cast<QFont&>(*font_h2_instance_);
}

const QFont& CustomElements::getFontH3()
{
    if (font_h3_instance_ == nullptr)
    {
        font_h3_instance_ = new QFont();
        font_h3_instance_->setFamily("roboto");
        font_h3_instance_->setPointSize(24);
        font_h3_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h3_instance_->setWeight(QFont::Normal);
    }

    return const_cast<QFont&>(*font_h3_instance_);
}

const QFont& CustomElements::getFontH4()
{
    if (font_h4_instance_ == nullptr)
    {
        font_h4_instance_ = new QFont();
        font_h4_instance_->setFamily("roboto");
        font_h4_instance_->setPointSize(18);
        font_h4_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h4_instance_->setWeight(QFont::Normal);
    }

    return const_cast<QFont&>(*font_h4_instance_);
}

const QFont& CustomElements::getFontParagraph()
{
    if (font_paragraph_instance_ == nullptr)
    {
        font_paragraph_instance_ = new QFont();
        font_paragraph_instance_->setFamily("roboto");
        font_paragraph_instance_->setPointSize(16);
        font_paragraph_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_paragraph_instance_->setWeight(QFont::Light);
    }

    return const_cast<QFont&>(*font_paragraph_instance_);
}

const QFont& CustomElements::getFontDetails()
{
    if (font_details_instance_ == nullptr)
    {
        font_details_instance_ = new QFont();
        font_details_instance_->setFamily("roboto");
        font_details_instance_->setPointSize(8);
        font_details_instance_->setWeight(QFont::Medium);
        font_details_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_details_instance_->setLetterSpacing(QFont::AbsoluteSpacing, 1);
        font_details_instance_->setCapitalization(QFont::AllUppercase);
    }

    return const_cast<QFont&>(*font_details_instance_);
}

QSpacerItem* CustomElements::getTerminalSpacer()
{
    return new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
}

void CustomElements::Init()
{
    // Import Fonts
    QFontDatabase::addApplicationFont(":/roboto-black.ttf");
    QFontDatabase::addApplicationFont(":/roboto-bold.ttf");
    QFontDatabase::addApplicationFont(":/roboto-light.ttf");
    QFontDatabase::addApplicationFont(":/roboto-medium.ttf");
    QFontDatabase::addApplicationFont(":/roboto-regular.ttf");
    QFontDatabase::addApplicationFont(":/roboto-thin.ttf");
}
