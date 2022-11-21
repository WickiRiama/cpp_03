/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:01 by mriant            #+#    #+#             */
/*   Updated: 2022/11/21 13:39:32 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

int main(void)
{
	std::cout << std::endl
			  << CYN << "=== ClapTraps ===" << RES << std::endl;
	ClapTrap clap;
	ClapTrap katara((std::string)BLU+"Katara"+RES);
	ClapTrap toph((std::string)GRN+"Toph"+RES);

	std::cout << std::endl
			  << CYN << "=== ScavTraps ===" << RES << std::endl;
	ScavTrap zuko((std::string)RED+"Zuko"+RES);

	std::cout << std::endl
			  << CYN << "=== FragTraps ===" << RES << std::endl;
	FragTrap aang((std::string)YEL+"Aang"+RES);

	std::cout << std::endl
			  << CYN << "=== Attacks ===" << RES << std::endl;
	katara.attack("Toph");
	toph.takeDamage(katara.getAttack());
	toph.attack("Katara");
	katara.takeDamage(toph.getAttack());
	toph.beRepaired(5);
	zuko.attack("Toph");
	toph.takeDamage(zuko.getAttack());
	toph.beRepaired(5);
	katara.attack("Zuko");
	zuko.takeDamage(katara.getAttack());
	aang.attack("Zuko");
	zuko.takeDamage(aang.getAttack());

	std::cout << std::endl
			  << CYN << "=== High Fives ===" << RES << std::endl;
	aang.highFivesGuys();

	std::cout << std::endl
			  << CYN << "=== Guard gate mode ===" << RES << std::endl;
	zuko.guardGate();
	zuko.guardGate();

	std::cout << std::endl
			  << CYN << "=== Final state ===" << RES << std::endl;
	std::cout << clap.getName() << " has now " << clap.getHit()
			  << " hit points and " << clap.getEnergy() << " energy points."
			  << std::endl;
	std::cout << katara.getName() << " has now " << katara.getHit()
			  << " hit points and " << katara.getEnergy() << " energy points."
			  << std::endl;
	std::cout << toph.getName() << " has now " << toph.getHit()
			  << " hit points and " << toph.getEnergy() << " energy points."
			  << std::endl;
	std::cout << zuko.getName() << " has now " << zuko.getHit()
			  << " hit points and " << zuko.getEnergy() << " energy points."
			  << std::endl;
	std::cout << aang.getName() << " has now " << aang.getHit()
			  << " hit points and " << aang.getEnergy() << " energy points."
			  << std::endl;

	std::cout << std::endl
			  << CYN << "=== Destructors ===" << RES << std::endl;

	return 0;
}