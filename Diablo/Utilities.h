#pragma once
#include "Enums.h"

int Min(int aValue, int aMin);
int Max(int aValue, int aMax);
int Clamp(int aValue, int aMin, int aMax);
int Abs(const int& aValue);
void ClearInput();
void ClearConsole();
void Pause();
void DoCommand(const char* aCommand);
char LowerChar(char aSource);
char UpperChar(char aSource);
const char* FromCharacterTypeToText(CharacterType aCharacterType);