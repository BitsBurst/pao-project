#ifndef SMARTSENSORS_ABSTRACTGRAPHICALELEMENT_H
#define SMARTSENSORS_ABSTRACTGRAPHICALELEMENT_H

#include <QWidget>
/**
 * @brief The AbstractGraphicalElement class
 */
class AbstractGraphicalElement : public QWidget {
    Q_OBJECT

protected:
    QLayout * layout_;
public:
    explicit AbstractGraphicalElement(QLayout * layout, QWidget * parent = nullptr);

    void setCustomLayout(QLayout * layout);
    QLayout* getLayout() const;
};

#endif //SMARTSENSORS_ABSTRACTGRAPHICALELEMENT_H
