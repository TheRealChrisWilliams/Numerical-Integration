#include <stdio.h>

void Trapezoidal (int ordNum)
{

	float ordArray [ordNum], firstSum = 0, secondSum = 0, step, intApprox;

    printf ("Enter the step:\n");
    scanf ("%f", &step);

    printf ("Now enter the ordinates:\n");
    for (int i = 0; i < ordNum; i++)
    {
        scanf ("%f", &ordArray[i]);
    }

    firstSum = ordArray[0] + ordArray[ordNum-1];

    for (int i = 0; i < ordNum-2; i++)
    {
        secondSum += ordArray[i+1];
    }

    intApprox = (firstSum+(2*secondSum))*(step/2);

    printf ("%.4f -- Approximation of Integral", intApprox);
}

void SimpsonsOneThird (int ordNum)
{

	float ordArray [ordNum], firstSum = 0, secondSum = 0, thirdSum = 0, step, intApprox;

    printf ("Enter the step:\n");
    scanf ("%f", &step);

    printf ("Now enter the ordinates:\n");
    for (int i = 0; i < ordNum; i++)
    {
        scanf ("%f", &ordArray[i]);
    }

    firstSum = ordArray[0] + ordArray[ordNum-1];

    for (int i = 0; i < ordNum-2; i++)
    {
        if (i%2 == 0)
        {
            secondSum += ordArray[i+1];
            continue;
        }
        else if (i%2 != 0)
        {
            thirdSum += ordArray[i+1];
            continue;
        }
    }


    intApprox = (firstSum+(2*thirdSum)+(4*secondSum))*(step/3);

    //printf ("%f\n%f\n%f\n", firstSum, secondSum, thirdSum);

    printf ("%.4f -- Approximation of Integral", intApprox);
}

void SimpsonsThreeEighth(int ordNum)
{

	float ordArray [ordNum], firstSum = 0, secondSum = 0, thirdSum = 0, step, intApprox;

    printf ("Enter the step:\n");
    scanf ("%f", &step);

    printf ("Now enter the ordinates:\n");
    for (int i = 0; i < ordNum; i++)
    {
        scanf ("%f", &ordArray[i]);
    }

    firstSum = ordArray[0] + ordArray[ordNum-1];

    for (int i = 0; i < ordNum-2; i++)
    {
       if ((i+1)%3 == 0)
       {
            secondSum += ordArray[i+1];
            continue;
       }
        else if ((i+1)%3 != 0)
        {
            thirdSum += ordArray [i+1];
            continue;
        }
    }

    //printf ("%f\n%f\n%f\n", firstSum, secondSum, thirdSum);
    intApprox = (firstSum + (2*secondSum) + (3*thirdSum))*((3*step)/8);
    printf ("%.4f", intApprox);

}

int main()
{
    int ordNum, choiceNum;

    printf ("Enter the method:\n1 -- Trapezoidal\n2 -- Simpson's 1/3rd Rule\n3 -- Simpson's 3/8th Rule\n");
    scanf ("%d", &choiceNum);

    if (choiceNum == 1)
    {
        printf ("Enter the number of ordinates: ");
        scanf ("%d", &ordNum);
        Trapezoidal (ordNum);
    }
    else if (choiceNum == 2)
    {
        printf ("Enter the number of ordinates: ");
        scanf ("%d", &ordNum);
        SimpsonsOneThird (ordNum);
    }
    else if (choiceNum == 3)
    {
        printf ("Enter the number of ordinates: ");
        scanf ("%d", &ordNum);
        SimpsonsThreeEighth (ordNum);
    }
    else
        printf ("Enter a valid response!");

}
