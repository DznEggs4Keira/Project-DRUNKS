// Copyright Epic Games, Inc. All Rights Reserved.

#include "DRUNKSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


//////////////////////////////////////////////////////////////////////////
// ADRUNKSCharacter

ADRUNKSCharacter::ADRUNKSCharacter()
{
	// Set this character to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	//Set the location and rotation of the Character Mesh Transform
    GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FQuat(FRotator(0.0f, -90.0f, 0.0f)));

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ADRUNKSCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ADRUNKSCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ADRUNKSCharacter::Interact);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &ADRUNKSCharacter::Throw);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADRUNKSCharacter::Move);

	}

}

void ADRUNKSCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	if(!drunkShifting) {
		MovementVector = Value.Get<FVector2D>();
	}

	if (timerDrunkMove <= 0 && barValue >= 50)
    {
		isDecelerating = true;
	}

	if (Controller != nullptr)
	{
		if(GetCharacterMovement()->MaxWalkSpeed <= 200) {

			drunkShifting = true;

			if (GoRight)
    		{
    		    MovementVector = FVector2D(-0.25f, 0.5f);
    		}
    		else
    		{
    		    MovementVector = FVector2D(0.25f, -0.5f);
    		}

			GetCharacterMovement()->bOrientRotationToMovement = false;
		}
		 else
    	{
			GetCharacterMovement()->bOrientRotationToMovement = true;
    	    drunkShifting = false;
			isDecelerating = false;
    	}

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ADRUNKSCharacter::Interact()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Interact button pressed")));
}

void ADRUNKSCharacter::Throw()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Throwing")));
}

// Called every frame
void ADRUNKSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, FString::Printf(TEXT("Your Float Value: %f"), barValue));
	
	// Handle bar value timer.
    timerBarValue -= DeltaTime;

	if(isDecelerating) {
		GetCharacterMovement()->MaxWalkSpeed -= 50.f * DeltaTime;
		return;
	}

	// update player walking speed based on current state (Drunk/Sober)
	GetCharacterMovement()->MaxWalkSpeed = (barValue < 50 ? MinWalkingSpeed : (drunkShifting ? drunkShiftingSpeed : MaxWalkingSpeed));

	
    timerDrunkMove -= DeltaTime;
    timeDrunkLapse -= DeltaTime;

	if(barValue < 50) {
		isSober = true;
	} else if(barValue >= 50) {
		isSober = false;
	}

	if (timerBarValue <= 0)
    {
        barValue -= 1.0f;
        timerBarValue = 1.0f;
    }

	if (timeDrunkLapse <= 0 && timerDrunkMove <= 0 && barValue >= 50)
    {
        timerDrunkMove = 2.5f;
        timeDrunkLapse = 3.7f;
        GoRight = !GoRight;
    }

}




