/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:19:16 by mriant            #+#    #+#             */
/*   Updated: 2022/11/14 12:18:26 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

//==============================================================================
//  Constructors and Destructor
//==============================================================================

ClapTrap::ClapTrap(void) : _name("unnamed_trap"), _hitPoints(10),
						   _energyPoints(10), _attackDamages(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _energyPoints(10), _attackDamages(10)
{
	std::cout << "Named constructor called with " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src.getName()), _hitPoints(10),
										  _energyPoints(10), _attackDamages(10)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

//==============================================================================
//  Operators
//==============================================================================

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHit();
	this->_energyPoints = rhs.getEnergy();
	this->_attackDamages = rhs.getAttack();
	return *this;
}

//==============================================================================
//  Functions
//==============================================================================

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamages
				  << " points of damage !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name
				  << " can't attack because it has " << this->_energyPoints
				  << " energy points and " << this->_hitPoints << " hit points"
				  << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount
			  << " points of damage and has now " << this->_hitPoints
			  << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has repaired " << amount
				  << " point and has now " << this->_hitPoints << " hit points."
				  << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name
				  << " can't be repaired because it has " << this->_energyPoints
				  << " energy points and " << this->_hitPoints << " hit points"
				  << std::endl;
}
std::string ClapTrap::getName(void) const
{
	return this->_name;
}

unsigned int ClapTrap::getHit(void) const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergy(void) const
{
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttack(void) const
{
	return this->_attackDamages;
}
