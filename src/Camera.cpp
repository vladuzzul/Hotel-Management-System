#include "Camera.h"

Camera::Camera(int id, double price, const std::string& type)
    : id(id), price(price), type(type) {}

int Camera::getId() const {
    return id;
}

double Camera::getPrice() const {
    return price;
}

std::string Camera::getType() const {
    return type;
}

void Camera::setPrice(double price) {
    this->price = price;
}
