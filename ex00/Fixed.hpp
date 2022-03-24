#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int	_rawBits;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		
		~Fixed(void);
		
		int getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(const Fixed &other);
};

#endif
