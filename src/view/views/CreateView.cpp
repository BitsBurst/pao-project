#include "CreateView.h"
/**
 * @brief CreateView::CreateView
 * @param parent
 */
CreateView::CreateView(QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    label1_ = new QLabel("Create View");
    label2_ = new QLabel("Create View");

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
}