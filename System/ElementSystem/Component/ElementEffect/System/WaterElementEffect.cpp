#include "WaterElementEffect.h"

float WaterElementEffect::CalculateDamage(float BaseDamage, EElement AttackerElement) const
{
    if (AttackerElement == EElement::Fire)
        return BaseDamage * 0.8f; // Less damage from fire attacks
    if (AttackerElement == EElement::Earth)
        return BaseDamage * 1.2f; // More damage from earth attacks
    return BaseDamage;
}

void WaterElementEffect::ApplyElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseHealthRegeneration(1.2f); // Water increases health regeneration
}

void WaterElementEffect::RemoveElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseHealthRegeneration(1.0f); // Reset health regeneration to normal
}