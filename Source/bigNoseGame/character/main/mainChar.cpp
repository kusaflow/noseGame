// Fill out your copyright notice in the Description page of Project Settings.


#include "mainChar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AmainChar::AmainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(GetRootComponent());
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 800;
	cameraBoom->SetRelativeRotation(FRotator(-20, -70, 0.f));
	//cameraBoom->RelativeRotation = FRotator(0.f, 0.f, 0.f);
	cameraBoom->bInheritPitch = cameraBoom->bInheritRoll = cameraBoom->bInheritYaw = false;

	bUseControllerRotationYaw = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);


}

// Called when the game starts or when spawned
void AmainChar::BeginPlay()
{
	Super::BeginPlay();

	bisWalking = false;
	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//WAlking or runnign 
	if (bisWalking)
		velocityShouldBe = 200;
	else
		velocityShouldBe = 600;

	SetVelForAnim();

	if (velocityShouldBe > GetCharacterMovement()->MaxWalkSpeed)
		GetCharacterMovement()->MaxWalkSpeed += 600 * DeltaTime;
	else if (velocityShouldBe < GetCharacterMovement()->MaxWalkSpeed)
		GetCharacterMovement()->MaxWalkSpeed -= 600 * DeltaTime;

	//velocity for animation
	
	
}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("forward", this, &AmainChar::moveForward);

	PlayerInputComponent->BindAxis("xAxis", this, &AmainChar::CameraYaw_z);
	PlayerInputComponent->BindAxis("yAxis", this, &AmainChar::CameraPitch_y);

	PlayerInputComponent->BindAxis("walking", this, &AmainChar::isWalking);


}

void AmainChar::CameraYaw_z(float val) {
	FRotator newR = FRotator(0, 0, 0);
	newR.Yaw += val;
	cameraBoom->AddRelativeRotation(newR);


}

void AmainChar::CameraPitch_y(float val) {
	FRotator newR = cameraBoom->GetRelativeRotation();
	newR.Pitch = FMath::Clamp(newR.Pitch + val, -80.0f, 4.0f);

	cameraBoom->SetRelativeRotation(newR);
}

void AmainChar::moveForward(float val) {
	const FRotator Rotation = FollowCamera->GetComponentRotation();//Controller->GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	if (val != 0) 
		RootComponent->SetWorldRotation(YawRotation);
	
	//UE_LOG( LogTemp, Warning, TEXT("sdsdsdsd"))

	AddMovementInput(Direction, val);
}

void AmainChar :: isWalking(float val) {
	if (val == 1)
		bisWalking = true;
	else
		bisWalking = false;
}








