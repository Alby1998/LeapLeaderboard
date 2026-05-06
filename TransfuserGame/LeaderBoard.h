#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LeaderBoard.generated.h"
USTRUCT(BlueprintType)
struct FLeaderboardEntry
{
 GENERATED_BODY()
 UPROPERTY(BlueprintReadOnly)
 int32 Rank = 0;
 UPROPERTY(BlueprintReadOnly)
 FString PlayerName;
 UPROPERTY(BlueprintReadOnly)
 int32 Score = 0;
};
UCLASS()
class YOURPROJECT_API ULeaderBoard : public UBlueprintFunctionLibrary
{
 GENERATED_BODY()

public:
 UFUNCTION(BlueprintCallable, Category = "Leaderboard")
 static bool AddScore(const FString& PlayerName, int32 PlayerScore);
 UFUNCTION(BlueprintCallable, Category = "Leaderboard")
 static bool GetLeaderboard(TArray<FLeaderboardEntry>& OutEntries);
private:
 static FString GetLeaderboardPath();
 static bool LoadEntries(TArray<FLeaderboardEntry>& Entries);
 static bool SaveEntries(const TArray<FLeaderboardEntry>& Entries);
};
