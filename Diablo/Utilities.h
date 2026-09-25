#pragma once

void ForceInput(int& aInput);
void ForceInput(int& aInput, int aMin = -1, int aMax = -1);
void ClearConsole();
void PauseConsole();
int GetRandomNumber(int aMin, int aMax);
void WriteLine(const char* aText, bool aNewLine = true);
int Min(int aValue, int aMin);
void ClearInput();
