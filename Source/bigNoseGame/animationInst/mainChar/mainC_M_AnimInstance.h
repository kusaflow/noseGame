// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "mainC_M_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BIGNOSEGAME_API UmainC_M_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public :
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "AnimProperty")
		void update();

	//var
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "kusaVar")
	float playerVel;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "kusaVar")
	bool bIsFalling;
	
};
