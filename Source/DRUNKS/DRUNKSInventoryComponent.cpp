// Fill out your copyright notice in the Description page of Project Settings.


#include "DRUNKSInventoryComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UDRUNKSInventoryComponent::UDRUNKSInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // we have a delegate event that controls when the tick should happen. i think
	MaxInventorySize = 20; // Default maximum size

	// ...
}

void UDRUNKSInventoryComponent::AddItem(ADRUNKSItem* Item)
{
	if (Item && Items.Num() < MaxInventorySize)
	{
		Items.Add(Item);
		UE_LOG(LogTemp, Warning, TEXT("Item %s added to inventory."), *Item->ItemName.ToString());
		OnInventoryUpdated.Broadcast(); // Notify that the inventory has been updated
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to add item: %s. Inventory full or invalid item."), Item ? *Item->ItemName.ToString() : TEXT("Invalid Item"));
		return;
	}
}

bool UDRUNKSInventoryComponent::RemoveItem(ADRUNKSItem* Item)
{
	if (Item && Items.Remove(Item) > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item %s removed from inventory."), *Item->ItemName.ToString());
		OnInventoryUpdated.Broadcast(); // Notify that the inventory has been updated
		return true;
	}
	return false;
}

void UDRUNKSInventoryComponent::UseItem(ADRUNKSItem* Item)
{
	if (Item)
	{
		// Implement the logic for using the item
		UE_LOG(LogTemp, Warning, TEXT("Using item: %s"), *Item->ItemName.ToString());

		// Example: Automatically remove item after use
		RemoveItem(Item);

		// Destroy the item actor from the world if needed
		Item->Destroy();
	}
}

const TArray<ADRUNKSItem*>& UDRUNKSInventoryComponent::GetItems() const
{
	return Items;
}


// Called when the game starts
void UDRUNKSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDRUNKSInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

