#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElementSystem.h"  // Include the element system
#include "ElementActorComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTVENUS_API UElementActorComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    // Sets default values for this component's properties
    UElementActorComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Handles switching the element for this component
    void SwitchElement();

    // Handles switching the element for this component
    void SetElement();

private:
    // Instance of ElementSystem to manage this component's element
    ElementSystem ElementManager;
};