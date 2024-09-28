#include "ElementSystem.h"

// Constructor initializes the current element to Fire by default
ElementSystem::ElementSystem(): CurrentElement(EElement::Fire) { }

// Switches to the next element in the cycle
void ElementSystem::SwitchElement()
{
    // Clean up the old element effect
    if (CurrentElementEffect)
    {
        // Remove the current element's buffs
        CurrentElementEffect->RemoveElementalBonus(GetOwner());
        // Delete the current element effect
        delete CurrentElementEffect;
    }
    // Switch to the next element
    switch (CurrentElement)
    {
        case EElement::Fire:
            CurrentElement = EElement::Water;
            CurrentElementEffect = new WaterElementEffect();
            break;
        case EElement::Water:
            CurrentElement = EElement::Earth;
            CurrentElementEffect = new EarthElementEffect();
            break;
        case EElement::Earth:
            CurrentElement = EElement::Air;
            CurrentElementEffect = new AirElementEffect();
            break;
        case EElement::Air:
            CurrentElement = EElement::Fire;
            CurrentElementEffect = new FireElementEffect();
            break;
    }
    // Apply the current element's buffs
    CurrentElementEffect->ApplyElementalBonus(GetOwner());
}

// Returns the current element
EElement ElementSystem::GetCurrentElement() const
{
    return CurrentElement;
}