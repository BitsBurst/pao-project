#include "DefaultView.h"

DefaultView::DefaultView(QWidget* parent)
    : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    QLabel* title = new QLabel("Titolo di Default");
    QLabel* description = new QLabel("Una descrizione per il titolo di Default");

    title->setFont(CustomElements::getFontH2());
    description->setFont(CustomElements::getFontParagraph());

    layout_->addWidget(title);
    layout_->addWidget(description);
    static_cast<QVBoxLayout*>(layout_)->addStretch();
}