#pragma once

#include "CoreMinimal.h"
#include "EElement.h"
#include "PlayerCharacter.h"

// Base class for elemental effects
class YOURGAME_API ElementEffect
{
public:
    virtual ~ElementEffect() = default;

    // Function to calculate damage after applying element effects
    virtual float CalculateDamage(float BaseDamage, EElement AttackerElement) const = 0;

    // Function to modify player stats (speed, health regen, etc.)
    virtual void ApplyElementalBonus(APlayerCharacter* Player) const = 0;

    // Optional: Function to remove bonus after switching elements
    virtual void RemoveElementalBonus(APlayerCharacter* Player) const {}
};