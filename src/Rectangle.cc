/*
 * Rectangle.cc
 *
 *  Created on: Jan 7, 2015
 *      Author: rasdaman
 */

#include <stdexcept>
#include "Rectangle.hh"

Rectangle::Rectangle(std::vector<boost::uint64_t> lower, std::vector<boost::uint64_t>upper)
{
    if (lower.size() != upper.size())
    {
        throw std::runtime_error(
            "Lower and upper bounds have different dimensions.");
    }

    this->lower = lower;
    this->upper = upper;
}

std::vector<boost::uint64_t>Rectangle::getCenter() const
{
    std::vector<boost::uint64_t> center;

    for (size_t i = 0; i < this->lower.size(); i++)
    {
        center.push_back((this->lower[i] + this->upper[i]) / 2);
    }

    return center;
}

const std::vector<boost::uint64_t>& Rectangle::getLower() const
{
    return lower;
}

const std::vector<boost::uint64_t>& Rectangle::getUpper() const
{
    return upper;
}

bool Rectangle::intersects(const Rectangle &rect)
{
    bool intersect = true;

    if(this->lower.size()!=rect.lower.size())
    {
        throw std::runtime_error("Rectangles are not of the same dimension.");
    }

    for(size_t i=0; i<this->lower.size() && intersect == true; ++i)
    {
        intersect&= (this->lower[i]<=rect.upper[i] && rect.lower[i]<= this->upper[i]);
    }

    return intersect;
}
