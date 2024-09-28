#pragma once

#include "CoreMinimal.h"
#include "ElementEffect.h"

class PROJECTVENUS_API WaterElementEffect : public ElementEffect
{
public:
    virtual float CalculateDamage(float BaseDamage, EElement AttackerElement) const override;
    virtual void ApplyElementalBonus(APlayerCharacter* Player) const override;
    virtual void RemoveElementalBonus(APlayerCharacter* Player) const override;
};