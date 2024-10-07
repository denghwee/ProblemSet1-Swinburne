#pragma once

#include <Polygon.h>
 
Polygon::Polygon() :
    fNumberOfVertices(0)
{}

void Polygon::readData( std::istream &aIStream ) {
    while (aIStream >> fVertices[fNumberOfVertices])
    {
        fNumberOfVertices++;
    }
}

size_t Polygon::getNumberOfVertices() const {
    return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex( size_t aIndex ) const {
    if (aIndex < fNumberOfVertices)
    {
        return fVertices[aIndex];
    }
}

float Polygon::getPerimeter() const {
    float fPerimeter = 0.0f;

    if (fNumberOfVertices > 2)
    {
        for (size_t i = 1; i < fNumberOfVertices; i++)
        {
            fPerimeter += (fVertices[i] - fVertices[i - 1]).length();
        }

        fPerimeter += (fVertices[0] - fVertices[fNumberOfVertices - 1]).length();
    }

    return fPerimeter;
}

Polygon Polygon::scale( float aScalar ) const {
    Polygon Result = *this;
    
    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
        Result.fVertices[i] = fVertices[i] * aScalar;
    }
    
    return Result;
}

float Polygon::getSignedArea() const {
    float fArea = 0.0f;

    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
        const Vector2D& current = fVertices[i];
        const Vector2D& next = fVertices[(i + 1) % fNumberOfVertices];

        fArea += (current.getX() * next.getY()) - (current.getY() * next.getX());
    }

    fArea /= 2.0f;

    return fArea;
}