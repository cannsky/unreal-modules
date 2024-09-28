#include "ElementActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UElementActorComponent::UElementActorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UElementActorComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void UElementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// This function handles switching the element for this instance
void UElementActorComponent::SwitchElement()
{
    // Use the ElementManager to switch the element
    ElementManager.SwitchElement();
    // Log the current element for this component
    UE_LOG(LogTemp, Log, TEXT("Element switched to: %d"), static_cast<int32>(ElementManager.GetCurrentElement()));
}