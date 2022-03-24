#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int	_rawBits;
		const static int	_bits = 8;
		
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(const int v_int);
		Fixed(const float v_float);
		
		~Fixed(void);
		
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed&	operator=(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);

		bool	operator>(const Fixed &value) const;
		bool	operator<(const Fixed &value) const;
		bool	operator>=(const Fixed &value);
		bool	operator<=(const Fixed &value);
		bool	operator==(const Fixed &value);
		bool	operator!=(const Fixed &value);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed&	min(Fixed &num1, Fixed &num2);
		static const Fixed&	min(const Fixed &num1, const Fixed &num2);
		static Fixed&	max(Fixed &num1, Fixed &num2);
		static const Fixed& max(const Fixed &num1, const Fixed &num2);

		float toFloat(void) const;
		int	toInt(void) const;
};

std::ostream& operator<<(std::ostream &flux, const Fixed &src);

#endif
