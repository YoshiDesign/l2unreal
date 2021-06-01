// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    PrintLine(Input);

    if (Input == hiddenWord) 
    {
        PrintLine(TEXT("WINNNERRR"));
    } else 
    {
        --this->lives;
        if (this->lives == 0) {
            PrintLine(TEXT("YOU LOSE!"));
        } else {            
            PrintLine(TEXT("Guess again..."));
        }
    }

}

void UBullCowCartridge::InitGame()
{
    this->hiddenWord = TEXT("Derp");
    const TCHAR HW[5] = {TEXT('d'),TEXT('e'),TEXT('r'),TEXT('p')};
    PrintLine(FString::Printf(TEXT("Hidden word is: %s\n%i Characters in length."), *this->hiddenWord, this->hiddenWord.Len()));
    this->lives = 5;
}