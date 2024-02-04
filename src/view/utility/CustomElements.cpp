#include <QFontDatabase>
#include <QFile>
#include <QApplication>
#include "CustomElements.h"

// Initialization
QFont *CustomElements::font_h1_instance_ = nullptr;
QFont *CustomElements::font_h2_instance_ = nullptr;
QFont *CustomElements::font_h3_instance_ = nullptr;
QFont *CustomElements::font_h4_instance_ = nullptr;
QFont *CustomElements::font_paragraph_instance_ = nullptr;
QFont *CustomElements::font_details_instance_ = nullptr;
/**
 * @brief CustomElements::getFontH1
 * @return
 * Returns a reference to the H1 font
 */
QFont& CustomElements::getFontH1()
{
    if (font_h1_instance_ == nullptr)
    {
        font_h1_instance_ = new QFont();
        font_h1_instance_->setFamily("roboto");
        font_h1_instance_->setPixelSize(60);
        font_h1_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h1_instance_->setWeight(QFont::Normal);
    }

    return *font_h1_instance_;
}
/**
 * @brief CustomElements::getFontH2
 * @return
 * Returns a reference to the H2 font
 */
QFont& CustomElements::getFontH2()
{
    if (font_h2_instance_ == nullptr)
    {
        font_h2_instance_ = new QFont();
        font_h2_instance_->setFamily("roboto");
        font_h2_instance_->setPixelSize(32);
        font_h2_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h2_instance_->setWeight(QFont::Normal);
    }

    return *font_h2_instance_;
}
/**
 * @brief CustomElements::getFontH3
 * @return
 * Returns a reference to the H3 font
 */
QFont& CustomElements::getFontH3()
{
    if (font_h3_instance_ == nullptr)
    {
        font_h3_instance_ = new QFont();
        font_h3_instance_->setFamily("roboto");
        font_h3_instance_->setPixelSize(24);
        font_h3_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h3_instance_->setWeight(QFont::Normal);
    }

    return *font_h3_instance_;
}
/**
 * @brief CustomElements::getFontH4
 * @return
 * Returns a reference to the H4 font
 */
QFont& CustomElements::getFontH4()
{
    if (font_h4_instance_ == nullptr)
    {
        font_h4_instance_ = new QFont();
        font_h4_instance_->setFamily("roboto");
        font_h4_instance_->setPixelSize(18);
        font_h4_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_h4_instance_->setWeight(QFont::Normal);
    }

    return *font_h4_instance_;
}
/**
 * @brief CustomElements::getFontParagraph
 * @return
 * Returns a reference to the paragraph font
 */
QFont& CustomElements::getFontParagraph()
{
    if (font_paragraph_instance_ == nullptr)
    {
        font_paragraph_instance_ = new QFont();
        font_paragraph_instance_->setFamily("roboto");
        font_paragraph_instance_->setPixelSize(16);
        font_paragraph_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_paragraph_instance_->setWeight(QFont::Light);
    }

    return *font_paragraph_instance_;
}
/**
 * @brief CustomElements::getFontDetails
 * @return
 * Returns a reference to the details font
 */
QFont& CustomElements::getFontDetails()
{
    if (font_details_instance_ == nullptr)
    {
        font_details_instance_ = new QFont();
        font_details_instance_->setFamily("roboto");
        font_details_instance_->setPixelSize(12);
        font_details_instance_->setWeight(QFont::Normal);
        font_details_instance_->setHintingPreference(QFont::HintingPreference::PreferNoHinting);
        font_details_instance_->setLetterSpacing(QFont::AbsoluteSpacing, 1);
        font_details_instance_->setCapitalization(QFont::AllUppercase);
    }

    return *font_details_instance_;
}
/**
 * @brief CustomElements::getTerminalSpacer
 * @param direction
 * @return
 * Returns a spacer item
 */
QSpacerItem* CustomElements::getTerminalSpacer(SpacerDirection direction)
{
    QSpacerItem *temp = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    switch (direction) {
    case VERTICAL:
		if(temp != nullptr)
			delete temp;
        temp = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        break;
    case HORIZONTAL:
		if(temp != nullptr)
			delete temp;
        temp = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
        break;
    }

    return temp;
}
/**
 * @brief CustomElements::Init
 * Initializes the custom elements
 */
void CustomElements::Init()
{
    // Import Fonts
    QFontDatabase::addApplicationFont(":/roboto-black.ttf");
    QFontDatabase::addApplicationFont(":/roboto-bold.ttf");
    QFontDatabase::addApplicationFont(":/roboto-light.ttf");
    QFontDatabase::addApplicationFont(":/roboto-medium.ttf");
    QFontDatabase::addApplicationFont(":/roboto-regular.ttf");
    QFontDatabase::addApplicationFont(":/roboto-thin.ttf");
	QFile styleFile( ":/styles/styles.qss" );
	styleFile.open(QFile::ReadOnly);
	qApp->setStyleSheet(styleFile.readAll());
}
/**
 * @brief CustomElements::getVerticalLayout
 * @param margin
 * @return
 * Returns a vertical layout with the specified margin
 */
QVBoxLayout* CustomElements::getVerticalLayout(int margin)
{
    auto * temp = new QVBoxLayout;
    temp->setContentsMargins(margin, margin, margin, margin);
    return temp;
}
/**
 * @brief CustomElements::getVerticalLayout
 * @param h_margin
 * @param v_margin
 * @return
 * Returns a vertical layout with the specified horizontal and vertical margins
 */
QVBoxLayout* CustomElements::getVerticalLayout(int h_margin, int v_margin)
{
    auto * temp = new QVBoxLayout;
    temp->setContentsMargins(h_margin,v_margin,h_margin,v_margin);
    return temp;
}
/**
 * @brief CustomElements::getVerticalLayout
 * @param left_margin
 * @param right_margin
 * @param top_margin
 * @param bottom_margin
 * @return
 * Returns a vertical layout with the specified left, right, top, and bottom margins
 */
QVBoxLayout* CustomElements::getVerticalLayout(int left_margin, int right_margin, int top_margin, int bottom_margin)
{
    auto * temp = new QVBoxLayout;
    temp->setContentsMargins(left_margin,top_margin,right_margin,bottom_margin);

    return temp;
}
/**
 * @brief CustomElements::getHorizontalLayout
 * @param margin
 * @return
 * Returns a horizontal layout with the specified margin
 */
QHBoxLayout* CustomElements::getHorizontalLayout(int margin)
{
    auto * temp = new QHBoxLayout;
    temp->setContentsMargins(margin, margin, margin, margin);

    return temp;
}
/**
 * @brief CustomElements::getHorizontalLayout
 * @param h_margin
 * @param v_margin
 * @return
 * Returns a horizontal layout with the specified horizontal and vertical margins
 */
QHBoxLayout* CustomElements::getHorizontalLayout(int h_margin, int v_margin)
{
    auto * temp = new QHBoxLayout;
    temp->setContentsMargins(h_margin,v_margin,h_margin,v_margin);

    return temp;
}
/**
 * @brief CustomElements::getHorizontalLayout
 * @param left_margin
 * @param right_margin
 * @param top_margin
 * @param bottom_margin
 * @return
 * Returns a horizontal layout with the specified left, right, top, and bottom margins
 */
QHBoxLayout* CustomElements::getHorizontalLayout(int left_margin, int right_margin, int top_margin, int bottom_margin)
{
    auto * temp = new QHBoxLayout;
    temp->setContentsMargins(left_margin,top_margin,right_margin,bottom_margin);

    return temp;
}
/**
 * @brief CustomElements::getCustomLayoutPrototype
 * @param prototype
 * @return
 * Returns a custom layout prototype
 */
QLayout* CustomElements::getCustomLayoutPrototype(LayoutPrototype prototype)
{
    QLayout * temp = CustomElements::getVerticalLayout(16);

    switch (prototype) {
        case V_CONTAINER:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getVerticalLayout(16);
            temp->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            temp->setSpacing(8);
            break;
        case H_NO_BORDER:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getHorizontalLayout(0);
            temp->setSpacing(0);
            temp->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            break;
        case SINGLE_SPACING:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getVerticalLayout(0);
            temp->setSpacing(8);
            break;
        case H_SINGLE_SPACING:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getHorizontalLayout(0);
            temp->setSpacing(8);
            break;
        case DOUBLE_SPACING:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getVerticalLayout(0);
            temp->setSpacing(16);
            break;
        case QUAD_SPACING:
			if(temp != nullptr)
				delete temp;
            temp = CustomElements::getVerticalLayout(0);
            temp->setSpacing(32);
            break;
    }

    return temp;
}