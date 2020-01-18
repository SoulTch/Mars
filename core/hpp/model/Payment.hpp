#pragma once

enum class PaymentType {

};

class Payment {
public:
    PaymentType type;
    int maxunit;
    int consume;
    int produce;
};