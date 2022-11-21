/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:18:29 by mriant            #+#    #+#             */
/*   Updated: 2022/11/21 18:00:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

//==============================================================================
//  Contructors and destructors
//==============================================================================

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "unnamed_diamondtrap";
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	std::cout << "DiamondTrap named constructor called with " << this->_name
			  << std::endl;
	this->ClapTrap::_name = name + "_clap_name";
	this->_attackDamages = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 50;

}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->_name
			  << std::endl;
}

//==============================================================================
//  Operators
//==============================================================================

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->ClapTrap::_name = rhs.ClapTrap::getName();
		this->_hitPoints = rhs.getHit();
		this->_energyPoints = rhs.getEnergy();
		this->_attackDamages = rhs.getAttack();
	}
	return *this;
}

//==============================================================================
//  Functions
//==============================================================================

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "I am " << this->_name << " and my clap name is "
			  << this->ClapTrap::_name << std::endl;
}