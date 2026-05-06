README.md
# Leap Leaderboard UE4
A lightweight Unreal Engine 4 leaderboard system implemented in C++.
The system provides:
- Persistent score storage
- Automatic leaderboard sorting
- Blueprint integration
- Simple text-based save format
- Reusable gameplay utility architecture
---
# Features
- Read leaderboard entries from disk
- Update player scores
- Automatically sort scores
- Keep leaderboard size fixed
- Blueprint-callable API
- No external dependencies
- Uses Unreal Engine file utilities
---
# Technical Overview
The leaderboard system is built using:
- `FFileHelper`
- `FPaths`
- `TArray`
- `FString`

Blueprint Function Libraries
Leaderboard data is stored locally in a text file.
Example format:


# Repository Structure

- `README.md`
- `LeaderBoard.h`
- `LeaderBoard.cpp`
- `Score.txt`

# Integration
Include the header
- #include "LeaderBoard.h"

Add a score
- ULeaderBoard::AddScore(TEXT("Player"), 5000);

Read leaderboard entries
- TArray<FLeaderboardEntry> Entries;
- ULeaderBoard::GetLeaderboard(Entries);

# Design Goals
This system was designed to:
demonstrate Unreal Engine C++ architecture
expose systems to Blueprints
keep the implementation lightweight
provide clean reusable code for gameplay systems

# Future Improvements

- `JSON serialization`
- `SaveGame integration`
- `Async file operations`
- `Online leaderboard support`
- `UI widgets`
- `Unit testing`
- `Multiplayer synchronization`






