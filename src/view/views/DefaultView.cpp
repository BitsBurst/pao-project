#include "DefaultView.h"
/**
 * @brief DefaultView::DefaultView is the constructor of the class.
 * @param parent is the parent widget of the view.
 */
DefaultView::DefaultView(QWidget* parent)
    : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    QLabel* title = new QLabel("SmartSensor");
    QLabel* description = new QLabel("Seleziona un sensore per visualizzare la simulazione dei dati");

    QLabel* key_1 = new QLabel("<b>Ctrl + o</b> : Apri una simulazione esistente");
    QLabel* key_2 = new QLabel("<b>Ctrl + s</b> : Esporta la simulazione corrente");
    QLabel* key_3 = new QLabel("<b>Ctrl + n</b> : Crea un nuovo sensore");
    QLabel* key_4 = new QLabel("<b>Ctrl + Shift + n</b> : Crea una nuova categoria");

    title->setFont(CustomElements::getFontH2());
    description->setFont(CustomElements::getFontParagraph());
    key_1->setFont(CustomElements::getFontParagraph());
    key_2->setFont(CustomElements::getFontParagraph());
    key_3->setFont(CustomElements::getFontParagraph());
    key_4->setFont(CustomElements::getFontParagraph());

    layout_->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    layout_->addWidget(title);
    layout_->addWidget(description);
    layout_->addItem(new QSpacerItem(0,20));
    layout_->addWidget(key_1);
    layout_->addWidget(key_2);
    layout_->addWidget(key_3);
    layout_->addWidget(key_4);
    static_cast<QVBoxLayout*>(layout_)->addStretch();
}