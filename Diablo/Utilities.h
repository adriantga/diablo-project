#pragma once
#include "Enums.h"

int GetRandomNumber(int aMin, int aMax);
int Min(int aValue, int aMin);
int Max(int aValue, int aMax);
int Clamp(int aValue, int aMin, int aMax);
void AdjustAmount(int& aAmount);
void Increase(int& aSource, int aAmount);
int Abs(const int& aValue);
void ClearInput();
void ClearConsole();
void Pause();
void DoCommand(const char* aCommand);
char LowerChar(char aSource);
char UpperChar(char aSource);
const char* FromCharacterTypeToText(CharacterType aCharacterType);