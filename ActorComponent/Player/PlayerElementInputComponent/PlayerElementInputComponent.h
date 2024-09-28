#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElementSystem.h"  // Include the element system
#include "PlayerElementInputComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTVENUS_API UPlayerElementInputComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UPlayerElementInputComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;
    // Store element actor component for this instance
    UElementActorComponent* ElementComponent;

private:
    // Store element component for this instance
    void SetupElementComponent();
    // Setup the input component for listening to input
    void SetupInputComponent();
    // Handles switching the element for this component
    void OnElementSwitch();
};