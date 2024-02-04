#ifndef SMARTSENSORS_ICONSTVISITOR_H
#define SMARTSENSORS_ICONSTVISITOR_H

class Sensor;
class Category;
/**
 * @brief Interface for a visitor that can visit a sensor or a category
 */
class IConstVisitor {
public:
    virtual ~IConstVisitor() {};
    virtual void visit(const Sensor& sensor) = 0;
    virtual void visit(const Category& category) = 0;
};

#endif //SMARTSENSORS_ICONSTVISITOR_H
