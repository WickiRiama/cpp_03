/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:56:23 by mriant            #+#    #+#             */
/*   Updated: 2022/11/21 16:26:56 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

//==============================================================================
//  Constructors and Destructor
//==============================================================================

ScavTrap::ScavTrap(void) : ClapTrap(), _keeperMode(false)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "unnamed_scavtrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamages = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _keeperMode(false)
{
	this->_name = name;
	std::cout << "ScavTrap named constructor called with " << this->_name
			  << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamages = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

//==============================================================================
//  Operators
//==============================================================================

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHit();
		this->_energyPoints = rhs.getEnergy();
		this->_attackDamages = rhs.getAttack();
		this->_keeperMode = rhs.getKeeper();
	}
	return *this;
}

//==============================================================================
//  Functions
//==============================================================================

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamages
				  << " points of damage !" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name
				  << " can't attack because it has " << this->_energyPoints
				  << " energy points and " << this->_hitPoints << " hit points"
				  << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!this->_keeperMode)
	{
		std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode"
				  << std::endl;
		this->_keeperMode = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name
				  << " is already in gate keeper mode" << std::endl;
	}
}

bool ScavTrap::getKeeper(void) const
{
	return this->_keeperMode;
}