#pragma once

void WriteLine(const char* aText, bool newLine = true);
bool IsCharacter(char aSource, char aTarget);
char ToLowerCharacter(char aSource);
char ToUpperCharacter(char aSource);
int Clamp(int aValue, int aMin, int aMax);
int Min(int aValue, int aMin);
int Max(int aValue, int aMax);
void ClearConsole();
void Pause();
void ClearInput();
void DoCommand(const char* aCommand);