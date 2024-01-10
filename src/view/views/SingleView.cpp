#include "SingleView.h"

SingleView::SingleView(QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    label1_ = new QLabel("Titolo H1");
    label1_->setFont(CustomElements::getFontH1());

    label2_ = new QLabel("Titolo H2");
    label2_->setFont(CustomElements::getFontH2());

    label3_ = new QLabel("Titolo H3");
    label3_->setFont(CustomElements::getFontH3());

    label4_ = new QLabel("Titolo H4");
    label4_->setFont(CustomElements::getFontH4());

    label5_ = new QLabel("Paragrafo: Questo è un esempio di paragrafo.");
    label5_->setFont(CustomElements::getFontParagraph());

    label6_ = new QLabel("Detail");
    label6_->setFont(CustomElements::getFontDetails());

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
    layout_->addWidget(label3_);
    layout_->addWidget(label4_);
    layout_->addWidget(label5_);
    layout_->addWidget(label6_);

    layout_->addItem(CustomElements::getTerminalSpacer());
}

void SingleView::show() {
    label1_->show();
    label2_->show();
    label3_->show();
    label4_->show();
    label5_->show();
    label6_->show();
}
