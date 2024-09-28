#include "EarthElementEffect.h"

float EarthElementEffect::CalculateDamage(float BaseDamage, EElement AttackerElement) const
{
    if (AttackerElement == EElement::Air)
        return BaseDamage * 1.2f; // More damage from air attacks
    return BaseDamage * 0.8f; // Less damage from all other attacks
}

void EarthElementEffect::ApplyElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseDefense(1.2f); // Earth reduces damage taken
}

void EarthElementEffect::RemoveElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseDefense(1.0f); // Reset defense to normal
}