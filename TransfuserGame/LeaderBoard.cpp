#include "LeaderBoard.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
bool ULeaderBoard::AddScore(const FString& PlayerName, int32 PlayerScore)
{
	TArray<FLeaderboardEntry> Entries;
	LoadEntries(Entries);
	
	bool bPlayerFound = false;
	for (FLeaderboardEntry& Entry : Entries)
	{
		if (Entry.PlayerName == PlayerName)
		{
			bPlayerFound = true;
			if (PlayerScore > Entry.Score)
			{
				Entry.Score = PlayerScore;
			}
			break;
		}
	}
	
	if (!bPlayerFound)
	{
		FLeaderboardEntry NewEntry;
		NewEntry.PlayerName = PlayerName;
		NewEntry.Score = PlayerScore;
		Entries.Add(NewEntry);
	}
	
	Entries.Sort([](const FLeaderboardEntry& A, const FLeaderboardEntry& B)
	{
		return A.Score > B.Score;
	});
	
	const int32 MaxEntries = 10;
	if (Entries.Num() > MaxEntries)
	{
		Entries.SetNum(MaxEntries);
	}
	
	for (int32 i = 0; i < Entries.Num(); ++i)
	{
		Entries[i].Rank = i + 1;
	}
	
	return SaveEntries(Entries);
}
bool ULeaderBoard::GetLeaderboard(TArray<FLeaderboardEntry>& OutEntries)
{
	return LoadEntries(OutEntries);
}
FString ULeaderBoard::GetLeaderboardPath()
{
	return FPaths::ProjectSavedDir() / TEXT("Leaderboard.txt");
}
bool ULeaderBoard::LoadEntries(TArray<FLeaderboardEntry>& Entries)
{
	Entries.Empty();
	
	FString FileContent;
	if (!FFileHelper::LoadFileToString(FileContent, *GetLeaderboardPath()))
	{
		return false;
	}
	
	TArray<FString> Lines;
	FileContent.ParseIntoArrayLines(Lines);
	
	for (const FString& Line : Lines)
	{
		TArray<FString> Parts;
		Line.ParseIntoArray(Parts, TEXT("|"));
		
		if (Parts.Num() != 3)
		{
			continue;
		}
		
		FLeaderboardEntry Entry;
		Entry.Rank = FCString::Atoi(*Parts[0]);
		Entry.PlayerName = Parts[1];
		Entry.Score = FCString::Atoi(*Parts[2]);
		Entries.Add(Entry);
	}
	
	return true;
}
bool ULeaderBoard::SaveEntries(const TArray<FLeaderboardEntry>& Entries)
{
	FString Output;
	for (const FLeaderboardEntry& Entry : Entries)
	{
		Output += FString::Printf(
			TEXT("%d|%s|%d\n"),
			Entry.Rank,
			*Entry.PlayerName,
			Entry.Score
		);
	}
	
	return FFileHelper::SaveStringToFile(Output, *GetLeaderboardPath());
}