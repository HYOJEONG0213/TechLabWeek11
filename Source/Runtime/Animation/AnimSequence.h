#pragma once

#include "AnimTypes.h"
#include "Asset/RenderAsset.h"
#include "AnimSequence.generated.h"

UCLASS()
class UAnimDataModel : public UObject
{
    GENERATED_BODY()
public:
    float GetFrameRate() const { return FrameRate; }
    void SetFrameRate(float InFrameRate) { FrameRate = InFrameRate; }

    int32 GetNumOfKeys() const { return NumberOfKeys; }
    void SetNumberOfKeys(int32 InNumberOfKeys) { NumberOfKeys = InNumberOfKeys; }

    int32 GetNumberOfFrames() const { return NumberOfFrames; }
    void SetNumberOfFrames(int32 InNumberOfFrames) { NumberOfFrames = InNumberOfFrames; }

    float GetPlayLength() const { return PlayLength; }
    void SetPlayLength(float InPlayLength) { PlayLength = InPlayLength; }

    TArray <FBoneAnimationTrack>& GetBoneAnimationTracks() const { return BoneAnimationTracks; }
    void SetBoneAnimationTracks(TArray <FBoneAnimationTrack>& InBoneAnimationTracks) { BoneAnimationTracks = InBoneAnimationTracks; }


private:
    TArray <FBoneAnimationTrack> BoneAnimationTracks;
    float FrameRate = 30.0f;
    int32 NumberOfKeys = 0;
    int32 NumberOfFrames = 0;
    float PlayLength = 0.0f;
};

UCLASS()
class UAnimSequenceBase : public URenderAsset {
    GENERATED_BODY()
public:
    float GetPlayLength();
    virtual void GetPose(float Time, TArray<FAnimTransform>& Out);
    UAnimDataModel &GetDataModel() const { return *DataModel; }

private:
    UAnimDataModel* DataModel = nullptr;
    TArray<FAnimNotifyEvent> Notifies;
};

UCLASS()
class UAnimSequence : public UAnimSequenceBase {
    GENERATED_BODY()
public:

private:
};