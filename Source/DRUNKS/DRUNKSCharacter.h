// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DRUNKSInventoryComponent.h"
#include "DRUNKSInteractionComponent.h"
#include "DRUNKSCharacter.generated.h"


UCLASS(config=Game)
class ADRUNKSCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Inventory component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDRUNKSInventoryComponent* InventoryComponent;

	/** Interaction Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDRUNKSInteractionComponent* InteractionComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

protected: 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomMovementSettings, meta = (AllowPrivateAccess = "true"))
	float MaxWalkingSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomMovementSettings, meta = (AllowPrivateAccess = "true"))
	float MinWalkingSpeed = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomMovementSettings, meta = (AllowPrivateAccess = "true"))
	float drunkShiftingSpeed = 350.f;

	bool GoRight = false;

	float barValue = 100.f;
    float timerBarValue = 1.f;

    float timerDrunkMove = 2.5f;
    float timeDrunkLapse = 3.7f;

	FVector2D MovementVector;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomMovementSettings)
	bool isSober = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomMovementSettings)
	bool drunkShifting = false;

public:
	ADRUNKSCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	// Called when interacting with an interactable
	void Interact();

	// Called when an interactable is held and thrown
	void Throw();
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();
};

