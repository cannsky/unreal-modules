#include "FireElementEffect.h"

float FireElementEffect::CalculateDamage(float BaseDamage, EElement AttackerElement) const
{
    if (AttackerElement == EElement::Fire)
        return BaseDamage * 0.8f; // Less damage from fire attacks
    if (AttackerElement == EElement::Water)
        return BaseDamage * 1.2f; // More damage from water attacks
    return BaseDamage;
}

void FireElementEffect::ApplyElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseDamageDealt(1.2f); // Fire increases damage dealt
}

void FireElementEffect::RemoveElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseDamageDealt(1.0f); // Reset damage to normal
}