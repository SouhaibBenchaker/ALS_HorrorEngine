

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "MyPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class HORRORENGINETOALS_API AMyPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float PPWeight = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FPostProcessSettings PPSettings;
    virtual void ApplyCameraModifiers(float DeltaTime, FMinimalViewInfo& InOutPOV) override
    {
        Super::ApplyCameraModifiers(DeltaTime, InOutPOV);
        if (PPWeight > 0.f)
        {
            AddCachedPPBlend(PPSettings, PPWeight);
        }
    }

    UFUNCTION(BlueprintCallable)
        void AddBlendable(const TScriptInterface<IBlendableInterface> InBlendableObject, const float InWeight = 1.f)
    {
        PPSettings.AddBlendable(InBlendableObject, InWeight);
    }

    UFUNCTION(BlueprintCallable)
        void RemoveBlendable(const TScriptInterface<IBlendableInterface> InBlendableObject)
    {
        PPSettings.RemoveBlendable(InBlendableObject);
    }
};
