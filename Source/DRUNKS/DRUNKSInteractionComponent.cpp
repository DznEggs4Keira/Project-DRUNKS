// Fill out your copyright notice in the Description page of Project Settings.


#include "DRUNKSInteractionComponent.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UDRUNKSInteractionComponent::UDRUNKSInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	InteractionRange = 200.0f;

	// ...
}


// Called when the game starts
void UDRUNKSInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UDRUNKSInteractionComponent::ExecuteInteraction(AActor* Interactable, AActor* Instigator)
{
	if (Interactable && Interactable->GetClass()->ImplementInterface(UBPI_Inventory::StaticClass()))
	{
		IBPI_Inventory::Execute_AddItemToInventory(InteractableActor, Cast<ADRUNKSItem>(InteractableActor));

		FString Message = FString::Printf(TEXT("Interacting with: %s"), *InteractableActor->GetName());
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, Message);
	}
}

AActor* UDRUNKSInteractionComponent::GetInteractableInReach()
{
	FHitResult HitResult;
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start + GetOwner()->GetActorForwardVector() * InteractionRange; // Example reach distance

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);
	if (bHit)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Green, false, 1.0f, 0, 1.0f);
		return HitResult.GetActor();
	}

	return nullptr;
}


// Called every frame
void UDRUNKSInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

