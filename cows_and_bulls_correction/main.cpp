#include <iostream>
#include <string>

int main()
{
    std::string firstPlayerNum;
    std::string secondPlayerNum;

    while (true)
    {
        std::cout << "First player: enter a number:\n";
        std::cin >> firstPlayerNum;

        std::cout << "Second player: try to guess:\n";
        std::cin >> secondPlayerNum;

        if (firstPlayerNum.length() != secondPlayerNum.length())
        {
            std::cout << "Different length!\n";
            continue;
        }

        bool correct = true;

        for (int i = 0; i < firstPlayerNum.length(); i++)
            if (firstPlayerNum[i] < '0' || firstPlayerNum[i] > '9')
                correct = false;

        for (int i = 0; i < secondPlayerNum.length(); i++)
            if (secondPlayerNum[i] < '0' || secondPlayerNum[i] > '9')
                correct = false;

        if (correct) break;

        std::cout << "Incorrect input!\n";
    }

    int n = firstPlayerNum.length();

    int bullsCounter = 0;
    int cowsCounter = 0;

    bool usedFirst[100] = { false };
    bool usedSecond[100] = { false };

    for (int i = 0; i < n; i++)
    {
        if (firstPlayerNum[i] == secondPlayerNum[i])
        {
            bullsCounter++;
            usedFirst[i] = true;
            usedSecond[i] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (usedSecond[i]) continue;

        for (int j = 0; j < n; j++)
        {
            if (usedFirst[j]) continue;

            if (secondPlayerNum[i] == firstPlayerNum[j])
            {
                cowsCounter++;
                usedSecond[i] = true;
                usedFirst[j] = true;
                break;
            }
        }
    }

    std::cout << "Bulls: " << bullsCounter << "\n";
    std::cout << "Cows: " << cowsCounter << "\n";
}