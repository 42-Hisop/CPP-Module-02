#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int v_int) : _rawBits(v_int << _bits)
{
	std::cout << "Int construtor called" << std::endl;
	return ;
}

Fixed::Fixed(const float v_float) : _rawBits((int)roundf(v_float * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member fuction called" << std::endl;
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

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, const Fixed &src)
{
	flux << src.toFloat();
	return (flux);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

