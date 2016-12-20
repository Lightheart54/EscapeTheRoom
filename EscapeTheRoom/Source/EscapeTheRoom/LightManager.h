// Copyright Cullen Sarles 2016

#pragma once

#include "Components/SceneComponent.h"
#include "LightManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPETHEROOM_API ULightManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULightManager();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//cycles the color of the attached components
	UFUNCTION(Category="LightManagement",BlueprintCallable)
	void CycleColor();
	UFUNCTION(Category = "LightManagement", BlueprintCallable)
	void setLightColor(int32 colorIndex);


private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* lightTriggerVolume;	
	UPROPERTY(EditAnywhere)
	UPointLightComponent* sectionPointLight;	
	UPROPERTY(EditAnywhere)
	USpotLightComponent* sectionSpotLight;
	UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* floorLightComp;

	UPROPERTY(EditAnywhere)
	int32 currentColorIndex;
	UPROPERTY(EditAnywhere)
	TArray<FLinearColor> lightColorSequence;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* BaseMaterial;

	UMaterialInstanceDynamic* lightMaterial;
};
