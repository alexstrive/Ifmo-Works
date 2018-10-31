#include <string>
#include "AirplaneBuilder.h"

AirplaneBuilder::AirplaneBuilder(Frame frame, Metal metal, TurbineNumber turbineNumber) : frame(frame),
                                                                                          metal(metal),
                                                                                          turbineNumber(turbineNumber) {}

Airplane *AirplaneBuilder::build() {
    return new Airplane(this->frame, this->metal, this->turbineNumber, "Custom");
}

