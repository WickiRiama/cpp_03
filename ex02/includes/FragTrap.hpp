/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:28:06 by mriant            #+#    #+#             */
/*   Updated: 2022/11/25 10:37:33 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap(void);

public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &src);

	void highFivesGuys(void) const;
};

#endif