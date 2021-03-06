// Copyright Cullen Sarles 2016

#include "EscapeTheRoom.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	//get the player's pawn
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	AActor* pOwner = GetOwner();
	FRotator actorRotation = pOwner->GetActorRotation();
	actorRotation.Yaw += openAngle;
	pOwner->SetActorRotation(actorRotation);
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume,
// 	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
// 	{
// 		// If the ActorThatOpens is in the volume, open the door
// 		OpenDoor();
// 	}
}

