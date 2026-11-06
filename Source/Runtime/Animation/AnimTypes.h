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

struct FRawAnimationData {
	TArray <FBoneAnimationTrack> BoneAnimationTracks;
	float FrameRate = 30.0f;
	int32 NumberOfKeys = 0;
	int32 NumberOfFrames = 0;
	float PlayLength = 0.0f;
};

struct FAnimNotifyEvent {
	float TriggerTime;
	float Duration;
	FName NotifyName;
};