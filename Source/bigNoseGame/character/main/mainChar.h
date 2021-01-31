// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "mainChar.generated.h"

UCLASS()
class BIGNOSEGAME_API AmainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AmainChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* cameraBoom;

	/* main camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;


	bool bisWalking;

	float velocityShouldBe;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = kusavar, meta = (AllowPrivateAccess = "true"))
	float velForAnim;

	//falling
	bool bIsFalling;

	//animMintages
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "montages", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* landing;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void CameraYaw_z(float val);

	UFUNCTION()
		void CameraPitch_y(float val);

	UFUNCTION()
		void moveForward(float val);
	UFUNCTION()
		void isWalking(float val);

	UFUNCTION(BlueprintImplementableEvent, Category = "kusaFx")
		void SetVelForAnim();


};
