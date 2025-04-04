#ifndef CAMERA_H
#define CAMERA_H

#include <string>

class Camera {
private:
    int id;
    double price;
    std::string type;

public:
    Camera(int id, double price, const std::string& type);
    int getId() const;
    double getPrice() const;
    std::string getType() const;
    void setPrice(double price);
};

#endif // CAMERA_H
