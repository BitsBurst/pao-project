#ifndef SMARTSENSORS_IVISITOR_H
#define SMARTSENSORS_IVISITOR_H

class Sensor;
class Category;

class IVisitor {
public:
    virtual ~IVisitor() {};
    virtual void visit(Sensor& sensor) = 0;
    virtual void visit(Category& category) = 0;
};

#endif //SMARTSENSORS_IVISITOR_H
