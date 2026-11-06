#pragma once
#include "EnginePch.h"


struct FAnimTransform {
	FVector Location;
	FQuat Rotation;
	FVector Scale = FVector(1,1,1);
};

struct  FRawAnimSequenceTrack {
	TArray <FVector> PosKeys;
	TArray <FQuat> RotKeys;
	TArray <FVector> ScaleKeys;
};

struct FBoneAnimationTrack {
	FName Name;
	FRawAnimSequenceTrack InternalTrack;
};

struct FAnimNotifyEvent {
	float TriggerTime;
	float Duration;
	FName NotifyName;
};