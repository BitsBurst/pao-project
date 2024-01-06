#include <QLabel>
#include "MainContentContainer.h"

MainContentContainer::MainContentContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);
}