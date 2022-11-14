/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:01 by mriant            #+#    #+#             */
/*   Updated: 2022/11/14 12:14:09 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap katara("Katara");
	ClapTrap toph("Toph");

	katara.attack("Toph");
	toph.takeDamage(katara.getAttack());
	toph.attack("Katara");
	toph.beRepaired(5);

	std::cout << katara.getName() << " has now " << katara.getHit()
			  << " hit points and " << katara.getEnergy() << " energy points."
			  << std::endl;
	std::cout << toph.getName() << " has now " << toph.getHit()
			  << " hit points and " << toph.getEnergy() << " energy points."
			  << std::endl;
	return 0;
}