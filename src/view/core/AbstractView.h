#ifndef SMARTSENSORS_ABSTRACTVIEW_H
#define SMARTSENSORS_ABSTRACTVIEW_H

#include <QWidget>
#include <QLayout>

class AbstractView : public QWidget {
    Q_OBJECT

protected:
    QLayout *layout_;

public:
    explicit AbstractView(QWidget *parent = nullptr);
    explicit AbstractView(QLayout * layout = nullptr, QWidget *parent = nullptr);
    void toggle();
    void show();

    void setCustomLayout(QLayout* layout);
};

#endif //SMARTSENSORS_ABSTRACTVIEW_H
