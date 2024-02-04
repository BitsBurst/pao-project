#include <QPushButton>
#include "SidebarLowControlWidget.h"
#include "../utility/CustomElements.h"

/**
 * @brief SidebarLowControlWidget::SidebarLowControlWidget
 * @param parent
 */
SidebarLowControlWidget::SidebarLowControlWidget(QWidget* parent)
    : AbstractWidget(CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING), parent) {

    // Initialization
    QPushButton* new_sensor = new QPushButton("Crea Sensore");
    QPushButton* new_category = new QPushButton("Crea Categoria");

    // Layout Widgets
    layout_->addWidget(new_sensor);
    layout_->addWidget(new_category);

    connect(new_sensor, &QPushButton::released, this, &SidebarLowControlWidget::createSensor);
    connect(new_category, &QPushButton::released, this, &SidebarLowControlWidget::createCategory);
}
/**
 * @brief SidebarLowControlWidget::~SidebarLowControlWidget
 */
SidebarLowControlWidget::~SidebarLowControlWidget()
{}
