#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int v_int) : _rawBits(v_int << _bits)
{
	return ;
}

Fixed::Fixed(const float v_float) : _rawBits((int)roundf(v_float * (1 << _bits)))
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)_rawBits / (1 << _bits))));
}

std::ostream&	operator<<(std::ostream &flux, const Fixed &src)
{
	flux << src.toFloat();
	return (flux);
}

bool	Fixed::operator>(const Fixed &value) const
{
	if (this->_rawBits > value._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &value) const
{
	if (this->_rawBits < value._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &value)
{
	if (this->_rawBits >= value._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &value)
{
	if (this->_rawBits <= value._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &value)
{
	if (this->_rawBits == value._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &value)
{
	if (this->_rawBits != value._rawBits)
		return (true);
	return (false);
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	++(_rawBits);
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	
	temp.setRawBits(_rawBits);
	this->_rawBits++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	--(_rawBits);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp.setRawBits(_rawBits);
	this->_rawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

const Fixed&	Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed&	Fixed::max(Fixed &num1, Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

const Fixed&	Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}


Fixed::~Fixed(void)
{
	return ;
}
