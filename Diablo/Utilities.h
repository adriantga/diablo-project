#pragma once

void WriteLine(const char* aText, bool aNewLine = true);
void Pause();
void ClearInput();
void ForceInput(int& aInput);
void ForceInput(int& aInput, int aMin, int aMax);
bool HasSubceeded(int aSource, int aTarget);
bool HasExceeded(int aSource, int aTarget);