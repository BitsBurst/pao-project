#include "MainView.h"

MainView::MainView(Controller * controller, QWidget* parent)
    :   QMainWindow(parent), controller_(controller)
{
    setMinimumSize(QSize(640, 360));

    QSize view_size(600, 450);
    resize(view_size);

    central_widget_ = new QWidget(this);
    central_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create Components
    createMenu();

    sidebar_ = new SidebarWidget(central_widget_);
    sidebar_->setMaximumWidth(200);
    sidebar_->show();
    content_ = new MainContentWidget(central_widget_);
    content_->show();

    // Pallet. TODO: Remove
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::darkBlue);
    central_widget_->setAutoFillBackground(true);
    central_widget_->setPalette(pal);

    // Layout Settings
    layout_ = new QHBoxLayout(central_widget_);
    layout_->setContentsMargins(0,0,0,0);
    layout_->setSpacing(0);

    layout_->addWidget(sidebar_);
    layout_->addWidget(content_);

    central_widget_->setLayout(layout_);

    setCentralWidget(central_widget_);
}

void MainView::createMenu() {
    menu_bar_ = new QMenuBar(this);

    // set MenuBar
    QMenu * file = new QMenu("File", menu_bar_);
    QMenu * sensors = new QMenu("Sensori", menu_bar_);
    menu_bar_->addMenu(file);
    menu_bar_->addMenu(sensors);

    setMenuBar(menu_bar_);
}