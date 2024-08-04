// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRUNKSItem.h"
#include "DRUNKSInventoryComponent.generated.h"

// Delegate for broadcasting inventory changes
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRUNKS_API UDRUNKSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UDRUNKSInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(ADRUNKSItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(ADRUNKSItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem(ADRUNKSItem* Item);

	// Returns the items in the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const TArray<ADRUNKSItem*>& GetItems() const;

	// Maximum number of items the inventory can hold
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 MaxInventorySize;

	// Event triggered when the inventory is updated
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Array to store inventory items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<ADRUNKSItem*> Items;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
