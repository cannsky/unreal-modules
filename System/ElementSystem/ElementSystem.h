#pragma once

#include "CoreMinimal.h"
#include "EElement.h"
#include "ElementEffect.h"
#include "FireElementEffect.h"
#include "WaterElementEffect.h"
#include "EarthElementEffect.h"
#include "AirElementEffect.h"

class PROJECTVENUS_API ElementSystem
{
public:
    // Constructor to initialize the element system
    ElementSystem();

    // Switches to the next element
    void SwitchElement();

    // Get the current element
    EElement GetCurrentElement() const;

private:
    // Instance variable to store the current element
    EElement CurrentElement;
    // Instance variable to store the current element effect
    ElementEffect* CurrentElementEffect;
};