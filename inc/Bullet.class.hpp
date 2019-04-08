/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:00:42 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 15:00:43 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include "retroDef.hpp"
# include "Point.class.hpp"

class Bullet : public Point {
	public:
		Bullet(int, int, int, char);

		Bullet(void);
		Bullet(Bullet const &src);
		Bullet & operator=(Bullet const &src);
		~Bullet(void);

		int		getVect(void) const;
		int		getSymb(void) const;
		void	changePosition(void);
	private:
		int		_vect;
		char	_symb;
		int		_numToChange;
};

#endif
