#include <iostream>
#include <utility> // for std::pair

using namespace std;

typedef std::pair<int, int> pii;

class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

ostream& operator<<(ostream& os, const Rectangle& rect)
{
    os  << "(leftX: " << rect.getLeftX() << ", bottomY: " << rect.getBottomY()
        << ", width: " << rect.getWidth() << ", height: " << rect.getHeight() << ")";
    return os;
}

/*
    Logic: we need to find the common intervals of the x and the y coordinates among two rectangles.
           If the common intervals are the same as one of the common intervals pair of one rectangle,
           it means that rectangle is contained, and we return that rectangle.
           Otherwise if any interval is (0,0), it means we have one touching edge or corner,
           then there is no possibility we have any crossed rectangle where its area is greater than 0,
           so we return an empty rectangle - Rectangle(0, 0, 0, 0).
           Finally, if non of those above cases match, return the bottomLeft point's coordinates
           where x is the largest of the two, and y is the smallest of the two.
           The width is the subtraction of the two elements in the x-interval.
           The height is the subtraction of the two elements in the y-interval.
*/

auto overlappingInterval(const pii &interval_1, const pii &interval_2) -> pii {
    pii ans;
    
    if (interval_1 == interval_2)
        return interval_1;
    
    if (interval_1.second <= interval_2.first || interval_2.second <= interval_1.first)
        ans = std::make_pair(0, 0);
    else {
        ans = std::make_pair(std::max(interval_1.first, interval_2.first), 
                             std::min(interval_1.second, interval_2.second));
    }
    
    return ans;
}

Rectangle findRectangularOverlap(const Rectangle& rect1, const Rectangle& rect2)
{
    pii rect1_x_interval = std::make_pair(rect1.getLeftX(), rect1.getLeftX() + rect1.getWidth()),
        rect1_y_interval = std::make_pair(rect1.getBottomY(), rect1.getBottomY() + rect1.getHeight());
    
    pii rect2_x_interval = std::make_pair(rect2.getLeftX(), rect2.getLeftX() + rect2.getWidth()),
        rect2_y_interval = std::make_pair(rect2.getBottomY(), rect2.getBottomY() + rect2.getHeight());
    
    pii overlapping_x_interval = overlappingInterval(rect1_x_interval, rect2_x_interval),
        overlapping_y_interval = overlappingInterval(rect1_y_interval, rect2_y_interval);
        
    if (overlapping_x_interval == std::make_pair(0, 0) || overlapping_y_interval == std::make_pair(0, 0)) {
        return Rectangle();
    }
    else if (overlapping_x_interval == rect1_x_interval && overlapping_y_interval == rect1_y_interval)
        return rect1;
    else if (overlapping_x_interval == rect2_x_interval && overlapping_y_interval == rect2_y_interval)
        return rect2;
    else {
        int leftX = overlapping_x_interval.first,
            bottomY = overlapping_y_interval.first,
            width = overlapping_x_interval.second - overlapping_x_interval.first,
            height = overlapping_y_interval.second - overlapping_y_interval.first;
        
        return Rectangle(leftX, bottomY, width, height);
    }
}