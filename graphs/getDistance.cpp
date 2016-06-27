/*
Consider a city where the streets are perfectly laid out to form an infinite square grid. In this city finding the shortest path between two given points (an origin and a destination) is much easier than in other more complex cities. As a new Uber developer, you are tasked to create an algorithm that does this calculation.

Given user's departure and destination coordinates, each of them located on some street, find the length of the shortest route between them assuming that cars can only move along the streets.

Example

For departure = [0.4, 1] and destination = [0.9, 3], the output should be
perfectCity(departure, destination) = 2.7.
*/

double getDistance(double first, double second) {
    using namespace std;
    if (int(first) == int(second)) {
        double leftside = first - int(first) + second - int(second);
        double rightside = 2 - leftside;
        return min(leftside,rightside);
    }
    else return fabs(second-first);
}
double perfectCity(std::vector<double> departure, std::vector<double> destination) {
    return getDistance(departure[0],destination[0]) + getDistance(departure[1], destination[1]);

}

