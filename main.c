#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "BMI.c"

#define BUFF_SIZE 1024

typedef enum {false, true} bool;

int main(int argc, char **argv) {
    const BMI *bmiCalc;
    int inApp = 1;
    char userCalcMode[BUFF_SIZE];
    char userWeight[BUFF_SIZE];
    double userWeightN = 0;
    char userHeight[BUFF_SIZE];
    double userHeightN = 0;
    char userAge[BUFF_SIZE];
    unsigned int userAgeN = 0;
    double bmi = 0;
    do {
        puts("Select your calc mode, (m)etric or (i)mperal? Or type (e)xit.");
        fgets(userCalcMode, BUFF_SIZE, stdin);
        if(strcmp("e\n", userCalcMode) == 0 | strcmp("exit\n", userCalcMode) == 0) {
            inApp = 0;
        } else {
            if(strcmp("metric\n", userCalcMode) == 0 || strcmp("m\n", userCalcMode) == 0) {
                while(userWeightN<=0) {
                    puts("Selected calculation mode: metric\nWrite your weight in [kg]");
                    fgets(userWeight, BUFF_SIZE, stdin);
                    userWeightN = strtod(userWeight, 0);
                    if(userWeightN<=0) puts("Width [in kg] must be a number and be highter than 0, try again.");
                }
                while(userHeightN<=0) {
                    puts("Write yout height in [m]");
                    fgets(userHeight, BUFF_SIZE, stdin);
                    userHeightN = strtod(userHeight, 0);
                    if(userHeightN<=0) puts("Height [in m] must be a number and be highter than 0, try again.");
                }
                bmi = calcMetric(userWeightN, userHeightN);
                //printf("Your bmi is %f [kg/m^2]\n", bmi);
            } else if(strcmp("imperal\n", userCalcMode) == 0 || strcmp("i\n", userCalcMode) == 0) {
                while(userWeightN<=0) {
                    puts("Selected calculation mode: imperal\nWrite your weight in [lbs]");
                    fgets(userWeight, BUFF_SIZE, stdin);
                    userWeightN = strtod(userWeight, 0);
                    if(userWeightN<=0) puts("Width [in lbs] must be a number and be highter than 0, try again.");
                }
                while(userHeightN<=0) {
                    puts("Write your height in [inches]");
                    fgets(userHeight, BUFF_SIZE, stdin);
                    userHeightN = strtod(userHeight, 0);
                    if(userHeightN<=0) puts("Height [in inches] must be a number and be highter than 0, try again.");
                }
                bmi = calcImperal(userWeightN, userHeightN);
                //printf("Your bmi is %f [lbs/inches^2]\n", bmi);
            }
            while(userAgeN<=0) {
                puts("Write your age");
                fgets(userAge, BUFF_SIZE, stdin);
                userAgeN = strtod(userAge, 0);
                if(userAgeN<=0) puts("Age must a number and be highter than 0, try again.");
            }
            printf("Your bmi is %f\n", bmi);
            printf("Your prediction in percent %f\n", calcBP(bmi, userAgeN, 1));
            printf("Body weight classification: %s\n", describeBMI(bmi, userAgeN));
            userWeightN = 0; userHeightN = 0; bmi = 0;
        }
    } while(inApp);
    return 0;
}