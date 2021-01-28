// Fill out your copyright notice in the Description page of Project Settings.


#include "mainC_M_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../../character/main/mainChar.h"

void UmainC_M_AnimInstance::NativeInitializeAnimation() {

}

void UmainC_M_AnimInstance::update() {
	AmainChar* player = Cast<AmainChar>(TryGetPawnOwner());

	if (player) {
		playerVel = player->velForAnim;
	}

}