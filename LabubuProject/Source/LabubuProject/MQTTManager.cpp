// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MQTTManager.h"
#include "Async/Async.h"
#include "CoreMinimal.h"
#include "ST_PiState.generated.h"

USTRUCT(BlueprintType)
struct FST_PiState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly) float timestamp;
    UPROPERTY(BlueprintReadOnly) FString dialogue;
    UPROPERTY(BlueprintReadOnly) FString app_state;

    UPROPERTY(BlueprintReadOnly) float arm_pos_x;
    UPROPERTY(BlueprintReadOnly) float arm_pos_y;
    UPROPERTY(BlueprintReadOnly) float arm_pos_z;
    UPROPERTY(BlueprintReadOnly) float arm_rot_pitch;
    UPROPERTY(BlueprintReadOnly) float arm_rot_yaw;
    UPROPERTY(BlueprintReadOnly) float arm_rot_roll;

    UPROPERTY(BlueprintReadOnly) float head_pos_x;
    UPROPERTY(BlueprintReadOnly) float head_pos_y;
    UPROPERTY(BlueprintReadOnly) float head_pos_z;
    UPROPERTY(BlueprintReadOnly) float head_rot_pitch;
    UPROPERTY(BlueprintReadOnly) float head_rot_yaw;
    UPROPERTY(BlueprintReadOnly) float head_rot_roll;

    UPROPERTY(BlueprintReadOnly) bool eyes_open;
    UPROPERTY(BlueprintReadOnly) float audio_level;
    UPROPERTY(BlueprintReadOnly) bool is_speaking;
};


