// Copyright Cullen Sarles 2016

#include "EscapeTheRoom.h"
#include "LightManager.h"


// Sets default values for this component's properties
ULightManager::ULightManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULightManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	lightMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	floorLightComp->SetMaterial(0, lightMaterial);
	setLightColor(currentColorIndex);
}


// Called every frame
void ULightManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void ULightManager::CycleColor()
{
	++currentColorIndex;
	setLightColor(currentColorIndex);
}

void ULightManager::setLightColor(int32 colorIndex)
{
	if (colorIndex >= lightColorSequence.Num())
	{
		colorIndex = 0;
	}
	sectionPointLight->SetLightColor(lightColorSequence[colorIndex]);
	sectionSpotLight->SetLightColor(lightColorSequence[colorIndex]);
	lightMaterial->SetVectorParameterValue("LightColor", lightColorSequence[colorIndex]);
}

