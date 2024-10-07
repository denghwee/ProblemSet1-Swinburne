#pragma once

#include <iostream>

#define MAX_POLYNOMIAL 10
#define MAX_DEGREE MAX_POLYNOMIAL*2+1

class Polynomial
{
private:
	size_t fDegree;
	double fCoeffs[MAX_DEGREE+1];

public:

	Polynomial();

	Polynomial operator*( const Polynomial& aRHS ) const;
    bool operator==( const Polynomial& aRHS ) const;

	friend std::istream& operator>>( std::istream& aIStream, Polynomial& aObject );
	friend std::ostream& operator<<( std::ostream& aOStream, const Polynomial& aObject );

    double operator()( double aX ) const;

    Polynomial getDerivative() const;

    Polynomial getIndefiniteIntegral() const;

    double getDefiniteIntegral( double aXLow, double aXHigh ) const;
};
