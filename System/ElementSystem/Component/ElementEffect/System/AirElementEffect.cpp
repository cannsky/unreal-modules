#include "AirElementEffect.h"

float AirElementEffect::CalculateDamage(float BaseDamage, EElement AttackerElement) const
{
    if (AttackerElement == EElement::Earth)
        return BaseDamage * 0.8f; // Less damage from earth attacks
    return BaseDamage;
}

void AirElementEffect::ApplyElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseSpeed(1.2f); // Air increases player's speed
}

void AirElementEffect::RemoveElementalBonus(APlayerCharacter* Player) const
{
    Player->IncreaseSpeed(1.0f); // Reset speed to normal
}