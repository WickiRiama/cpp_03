/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:27:54 by mriant            #+#    #+#             */
/*   Updated: 2022/11/21 17:36:00 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

//==============================================================================
//  Constructors and Destructor
//==============================================================================

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "unnamed_fragtrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamages = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	std::cout << "FragTrap named constructor called with " << this->_name
			  << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamages = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

//==============================================================================
//  Operators
//==============================================================================

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHit();
		this->_energyPoints = rhs.getEnergy();
		this->_attackDamages = rhs.getAttack();
	}
	return *this;
}

//==============================================================================
//  Functions
//==============================================================================

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamages
				  << " points of damage !" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name
				  << " can't attack because it has " << this->_energyPoints
				  << " energy points and " << this->_hitPoints << " hit points"
				  << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " wants to do a high fives."
			  << std::endl;
}