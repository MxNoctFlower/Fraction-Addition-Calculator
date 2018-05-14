//Created by Nigel Jacobs
//This program adds two fractions together and simplifies the sum
#include<iostream>
using namespace std;

void Output(int, int, int, int, int, int, int, int, int);// Function will display results

int main()
{
    int num1, num2, num3, den1, den2, den3, mixed1 = 0, mixed2 = 0, mixednum1 = 0, mixednum2 = 0, mixednum3 = 0;
    char answer;

    cout << "Do you want to calculate mixed numbers?(Y/N): "; //Asks for mixed numbers
    cin >> answer;
    if(answer == 'Y'|| answer == 'y')
    {
        cout << "What is your whole number for your first fraction?(Put 0 if there is none): ";
        cin >> mixed1;
        cout << "What is your whole number for your second fraction?(Put 0 if there is none): ";
        cin >> mixed2;
    }
    cout << "Please enter the numerators for your two fractions: "; //Asks for numerators and denominators
    cin >> num1 >> num2;
    cout << "Please enter the denominators of your two fractions: ";
    cin >> den1 >> den2;
    if(den1 == den2) // If denominators are the same
    {
        if(mixed1 == 0 && mixed2 == 0) //If there are no mixed numbers
        {
            den3 = den1;
            num3 = num1 + num2;
            for(int count = num3*den3; count > 1; count--) //Reduces fractions
            {
                if(den3 % count == 0 && num3 % count == 0)
                {
                    den3 /= count;
                    num3 /= count;
                }
           }
           mixednum3 = num3/den3;
           num3 %= den3;
        }
        else //If there are mixed numbers
        {
            mixednum1 = (mixed1*den1) + num1;
            mixednum2 = (mixed2*den2) + num2;
            den3 = den1;
            num3 = (mixednum1 + mixednum2) % den3;
            for(int count = num3*den3; count > 1; count--)//Reduces fractions
            {
                if(den3 % count == 0 && num3 % count == 0)
                {
                    den3 /= count;
                    num3 /= count;
                }
            }
            mixednum3 = (mixednum1 + mixednum2)/den3;
            num3 %= den3;

        }

    }
    else //If the denominators are different
    {
        if(mixed1 == 0 && mixed2 == 0)//If there are no mixed numbers
        {
            den3 = den1*den2;
            num3 = (num1*den2) + (num2*den1);
            for(int count = num3*den3; count > 1; count--)//Reduces fractions
            {
                if(den3 % count == 0 && num3 % count == 0)
                {
                    den3 /= count;
                    num3 /= count;
                }
           }
           mixednum3 = num3/den3;
           num3 %= den3;
        }
        else //If there are mixed numbers
        {
            mixednum1 = ((mixed1*den1) + num1)*den2;
            mixednum2 = ((mixed2*den2) + num2)*den1;
            den3 = den1*den2;
            num3 = mixednum1 + mixednum2;
            for(int count = num3*den3; count > 1; count--)//Reduces fractions
            {
                if(den3 % count == 0 && num3 % count == 0)
                {
                    den3 /= count;
                    num3 /= count;
                }
            }
            mixednum3 = num3/den3;
            num3 %= den3;
        }
    }
    Output(mixed1, mixed2, mixednum3, num1, den1, num2, den2, num3, den3);//Selects display
    return 0;
}

void Output(int mixed1, int mixed2, int mixednum3, int num1, int den1, int num2, int den2, int num3, int den3)
{
    if(mixed1 == 0 && mixed2 == 0 && mixednum3 == 0) //If there are no mixed numbers
       cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << num3 << "/" << den3 << endl; 
    else if(mixed1 == 0 && mixed2 == 0) // If fractions 1 & 2 are not mixed numbers
        cout << num1 << "/" << den1 <<  " + " << num2 << "/" << den2 << " = " << mixednum3 << "(" << num3 << "/" << den3 << ")" << endl;
    else if(mixed1 == 0) //If fraction 1 is not a mixed number
        cout << num1 << "/" << den1 << " + " << mixed2 << "(" << num2 << "/" << den2 << ") = " << mixednum3 << "(" << num3 << "/" << den3 << ")" << endl;
    else if(mixed2 == 0) //If fraction 2 is not a mixed number
        cout << mixed1 << "(" << num1 << "/" << den1 << ")" << " + " << num2 << "/" << den2 << " = " << mixednum3 << "(" << num3 << "/" << den3 << ")" << endl;
    else if(mixednum3 == 0) //If result is not a mixed number
        cout << mixed1 << "(" << num1 << "/" << den1 << ")" << " + " << mixed2 << "(" << num2 << "/" << den2 << ") = " << num3 << "/" << den3 <<  endl;
    else if(num3 == 0) //If result has no numerator
        cout << mixed1 << "(" << num1 << "/" << den1 << ")" << " + " << mixed2 << "(" << num2 << "/" << den2 << ") = " << mixednum3 <<  endl;
    else //If all fractions are mixed numbers
       cout << mixed1 << "(" << num1 << "/" << den1 << ")" << " + " << mixed2 << "(" << num2 << "/" << den2 << ") = " << mixednum3 << "(" << num3 << "/" << den3 << ")" <<  endl;
}
