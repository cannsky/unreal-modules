#include "UPlayerElementInputComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UPlayerElementInputComponent::UPlayerElementInputComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UPlayerElementInputComponent::BeginPlay()
{
    Super::BeginPlay();
    // Setup the element component to get the element actor component
    SetupElementComponent();
    // Setup the input component to listen for input
    SetupInputComponent();
}

void UPlayerElementInputComponent::SetupElementComponent() 
{
    // Get the element component from the owner actor
    ElementComponent = GetOwner()->FindComponentByClass<UElementActorComponent>();
    // Check if the element component was found
    if (!ElementComponent) UE_LOG(LogTemp, Error, TEXT("ElementComponent not found on %s!"), *GetOwner()->GetName());
}

void UPlayerElementInputComponent::SetupInputComponent()
{
    // Get the input component from the owner actor
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    // Bind the OnElementSwitch function to the "OnElementSwitch" action
    if (InputComponent) InputComponent->BindAction("OnElementSwitch", IE_Pressed, this, &UPlayerElementActorComponent::OnElementSwitch);
    else UE_LOG(LogTemp, Error, TEXT("InputComponent not found on %s!"), *GetOwner()->GetName());
}

// This function handles switching the element for this instance
void UPlayerElementInputComponent::OnElementSwitch()
{
    // Check if the element component is valid
    if (!ElementComponent) return;
    // Switch the element for this instance
    ElementComponent->SwitchElement(); 
}