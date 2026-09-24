#pragma once

void WriteLine(const char* aText, bool aNewLine = true);
void InitializeRandom();
int GetRandomNumber(int aMin, int aMax);
int Min(int aValue, int aMin);
int Max(int aValue, int aMax);
int Clamp(int aValue, int aMin, int aMax);