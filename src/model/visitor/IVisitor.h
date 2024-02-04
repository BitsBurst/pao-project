#ifndef SMARTSENSORS_IVISITOR_H
#define SMARTSENSORS_IVISITOR_H

class Sensor;
class Category;
/**
 * @brief Interface for a visitor that can visit a sensor or a category
 */
class IVisitor {
public:
    virtual ~IVisitor() {};
    virtual void visit(Sensor& sensor) = 0;
    virtual void visit(Category& category) = 0;
};

#endif //SMARTSENSORS_IVISITOR_H
