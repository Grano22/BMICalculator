#include<math.h>

typedef struct
{

} BMI;

float calcMetric(double weight, double height) {
    return weight / pow(height, 2);
}

float calcImperal(double weight, double height) {
    return (703 * weight) / pow(height, 2);
}

double calcBP(double bmi, int age, int sex) {
    if(age>=15) {
        return (1.20 * bmi) + (0.23 * age) - (10.8 * sex) - 5.4;
    } else {
        return (1.51 * bmi) - (0.70 * age) - (3.6 * sex) + 1.4;
    }
}

char* describeBMI(double bmi, unsigned int age) {
    int dx = 0;
    if(age>25) {
        dx = round((age - 25) / 9);
    } else if(age<19) {
        dx = -1;
    }
    if(bmi<16+dx) return "starvation";
    else if(bmi<17+dx) return "emaciation";
    else if(bmi<18+dx) return "underweight";
    else if(bmi<25+dx) return "optimum";
    else if(bmi<30+dx) return "overweight";
    else if(bmi<35+dx) return "obesity level 1";
    else if(bmi<40+dx) return "obesity level 2";
    else return "obesity level 3";
}